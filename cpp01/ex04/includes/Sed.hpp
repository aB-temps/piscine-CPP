/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 17:21:09 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		__SED_HPP__
# define	__SED_HPP__

#include <iostream>
#include <fstream>

class	Sed
{
	public:
		enum		e_mode
		{
			FROM,
			TO,
		};
		bool				openInfile(const char *filename);
		bool				createOutfile(const char *filename);
		void				setSeq(const char *seq, int mode);
		const std::string	&getSeq(int mode) const;
		void				replaceOccurences(void);

	private:
		std::string			_seq_from;
		std::string			_seq_to;
		std::ifstream		_infile;
		std::ofstream		_outfile;

};

#endif
