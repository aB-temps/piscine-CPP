/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:56:36 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 17:14:02 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include "close_file.tpp"
#include "errors.hpp"

using	std::cout;
using	std::endl;

Sed::Sed(void): _mode(0), _limit(0), _occurences_count(0), _removed_bytes(0), _added_bytes(0) {}

bool				Sed::parseArguments(int ac, char *av[])
{
	if (ac < 4)
	{
		cout << BAD_ARGS << endl;
		return (false);
	}
	if (ac > 4)
	{
		for (int i = 4; i < ac; ++i)
		{
			std::string	param(av[i]);
			if (param == "-l")
			{
				if (i + 1 < ac)
				{
					std::stringstream arg(av[i + 1]);
					arg >> this->_limit;
					if (this->_limit <= 0)
					{
						cout << BAD_ARGS << endl;
						return (false);
					}
					this->_mode |= (1 << RANK_L);
					++i;
				}
				else
				{
					cout << BAD_ARGS << endl;
					return (false);
				}
			}
			else if (param == "-v")
				this->_mode |= (1 << RANK_V);
			else
			{
				cout << BAD_ARGS << endl;
				return (false);
			}
		}
	}
	setSeq(av[2], FROM);
	setSeq(av[3], TO);
	return (true);
}

void				Sed::closeIOFiles(void)
{
	close_file<std::ifstream>(this->_infile);
	close_file<std::ofstream>(this->_outfile);
}

bool				Sed::openInfile(const char *infile)
{
	this->_infile.open(infile);
	if (this->_infile.is_open())
		return (true);
	cout << FAIL_OPEN << endl;
	return (false);
}

bool				Sed::createOutfile(const char *infile)
{
	std::string	outfilename(infile);
	outfilename += ".replace";
	this->_outfile.open(outfilename.c_str());
	if (this->_outfile.is_open())
		return (true);
	cout << FAIL_CREATE << endl;
	return (false);
}

void				Sed::setSeq(const char *seq, int streamdir)
{
	if (streamdir == FROM)
		this->_seq_from = seq;
	else
		this->_seq_to = seq;
}

const std::string	&Sed::getSeq(int streamdir) const
{
	if (streamdir == FROM)
		return (this->_seq_from);
	else
		return (this->_seq_to);
}

void				Sed::_displayStats(void)
{
	if (this->_occurences_count > 1)
		cout << BLUE BOLD << this->_occurences_count << " occurences replaced." << RST << endl;
	else
		cout << BLUE BOLD << this->_occurences_count << " occurence replaced." << RST << endl;

	if (this->_removed_bytes > 1)
		cout << RED BOLD << "-" << this->_removed_bytes << " bytes" << endl;
	else
		cout << RED BOLD << "-" << this->_removed_bytes << " byte" << endl;

	if (this->_added_bytes > 1)
		cout << GREEN BOLD << "+" << this->_added_bytes << " bytes" << RST << endl;
	else
		cout << GREEN BOLD << "+" << this->_added_bytes << " byte" << RST << endl;
}

void				Sed::_incrementStats(void)
{
	const int	seq_from_len = this->_seq_from.length();
	const int	seq_to_len = this->_seq_to.length();

	++this->_occurences_count;
	this->_removed_bytes += seq_from_len;
	this->_added_bytes += seq_to_len;
}

void				Sed::replaceOccurences(void)
{
	const unsigned long overlap_size = this->_seq_from.length() - 1;
	std::string 		obuff;
	std::string 		tbuff;
	std::string 		pbuff;
	char				rbuff[BUFFER_SIZE + 1];
	unsigned long		bytes_read;
	unsigned long		plen;

	this->_infile.exceptions(std::ios::badbit);
	try
	{
		while (1)
		{
			this->_infile.read(rbuff, BUFFER_SIZE);
			bytes_read = this->_infile.gcount();
			if (bytes_read <= 0)
			{
				cout << RED"finished"RST << endl;
				obuff = pbuff.substr(pbuff.length() - overlap_size) + obuff;
				break;
			}
			rbuff[bytes_read] = '\0';
			cout << "prev_obuff= \'" << obuff << "\'" << endl;
			cout << "rbuff= \'" << rbuff << "\'" << endl;
			tbuff = obuff + std::string(rbuff, bytes_read);
			cout << "tbuff= \'" << tbuff << "\'" << endl;
			if (tbuff.length() <= overlap_size)
			{
				obuff = tbuff;
				cout << "obuff(ctn)= \'" << obuff << "\'" << endl;
				continue;
			}
			else
				cout << GREEN"LEN OK!"RST << endl;
			plen = tbuff.length() - overlap_size;
			pbuff = tbuff.substr(0, plen);
			cout << "pbuff= \'" << pbuff << "\'" << endl;

			_processAndWriteBuff(pbuff);
			obuff = tbuff.substr(plen);
			cout << "obuff= \'" << obuff << "\'" << endl;
		}
		_processAndWriteBuff(obuff);
	}
	catch (const std::ios::failure &error)
	{
		cout << error.what() << endl;
		if (this->_infile.bad())
		{
			cout << BADBIT << endl;
			throw;
		}
		if (this->_infile.eof())
		{
			cout << EOFBIT << endl;
			throw;
		}

	}
	if ((this->_mode & 0b0001) != 0)
		this->_displayStats();
}

void					Sed::_processAndWriteBuff(std::string s)
{
	const unsigned long seq_len = this->_seq_from.length();
	unsigned long		match_pos = 0;
	unsigned long		last_pos = 0;

	cout << "processing....: \'" << s << "\'\n" << endl;
	while (true)
	{
		match_pos = s.find(this->_seq_from, last_pos);
		if (match_pos == s.npos)
		{
			this->_outfile << s.substr(last_pos);
			break;
		}
		this->_outfile << s.substr(last_pos, match_pos - last_pos) << this->_seq_to;
		last_pos = match_pos + seq_len;
	}
}
