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
	if (getSeq(FROM).empty())
	{
		cout << BAD_ARGS << endl;
		return (false);
	}
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
	std::stringstream ss;

	this->_infile.exceptions(std::ios::badbit);
	this->_outfile.exceptions(std::ios::badbit);
	try
	{
		ss << this->_infile.rdbuf();
		_processAndWrite(ss.str());
	}
	catch (const std::ios::failure &error)
	{
		if (this->_infile.bad())
		{
			cout << "infile: " << BADBIT << endl;
			throw;
		}
		if (this->_outfile.bad())
		{
			cout << "outfile: " << BADBIT << endl;
			throw;
		}
	}
	if ((this->_mode & 0b0001) != 0)
		this->_displayStats();
}

void					Sed::_processAndWrite(std::string s)
{
	const unsigned long seq_len = this->_seq_from.length();
	unsigned long		match_pos = 0;


	while (true)
	{
		match_pos = s.find(this->_seq_from, last_pos);
		if (match_pos == s.npos || (this->_limit > 0 && this->_occurences_count == this->_limit))
		{
			this->_outfile << &s[last_pos];
			break;
		}
		this->_outfile << s.substr(last_pos, match_pos - last_pos) << this->_seq_to;
		this->_incrementStats();
		last_pos = match_pos + seq_len;
	}
}
