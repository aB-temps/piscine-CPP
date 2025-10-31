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
#include "errors.hpp"

using	std::cout;
using	std::endl;

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

void				Sed::setSeq(const char *seq, int mode)
{
	if (mode == FROM)
		this->_seq_from = seq;
	else
		this->_seq_to = seq;
}

const std::string	&Sed::getSeq(int mode) const
{
	if (mode == FROM)
		return (this->_seq_from);
	else
		return (this->_seq_to);
}

void				Sed::replaceOccurences(void)
{
	std::string	tmp;

	this->_infile.exceptions(std::ios::badbit | std::ios::eofbit | std::ios::failbit);
	try
	{
		while (true)
		{
			getline(this->_infile, tmp);
			this->_outfile << tmp;	
		}
	}
	catch (const std::ios::failure &error)
	{
		if (this->_infile.bad())
		{
			cout << "BAD" << endl;
			throw;
		}
		else if (this->_infile.eof())
		{
			cout << "EOF" << endl;
			throw;
		}
	}
}
