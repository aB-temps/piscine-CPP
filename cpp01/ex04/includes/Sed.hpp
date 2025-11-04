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

#pragma		once

#ifndef		__SED_HPP__
# define	__SED_HPP__

# define EOFBIT			GREEN"Reached EOF."RST
# define BUFFER_SIZE 	4

# include <iostream>
# include <sstream>
# include <fstream>

class	Sed
{
	public:
		Sed(void);
		enum				e_streamDirection
		{
			FROM,
			TO,
		};
		bool				parseArguments(int ac, char *av[]);
		void				closeIOFiles(void);
		bool				openInfile(const char *filename);
		bool				createOutfile(const char *filename);
		void				setSeq(const char *seq, int mode);
		const std::string	&getSeq(int mode) const;
		void				replaceOccurences(void);

	private:
		enum				_e_flags
		{
			RANK_V = 0,
			RANK_L = 1,
		};
		std::string			_strReplace(std::string str, int &overlap);
		void				_incrementStats(void);
		void				_displayStats(void);
		int					_mode;
		int					_limit;
		int					_occurences_count;
		int					_removed_bytes;
		int					_added_bytes;
		std::string			_seq_from;
		std::string			_seq_to;
		std::ifstream		_infile;
		std::ofstream		_outfile;

};

#endif
