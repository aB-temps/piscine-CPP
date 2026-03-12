/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/05 17:43:03 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__SCALARCONVERTER_HPP__
# define	__SCALARCONVERTER_HPP__

# include <iostream>

// Typedef =====================================================================
typedef unsigned char	t_uint8;

// Class declaration ===========================================================
class	ScalarConverter
{
	public:
		static void				convert(const std::string &s);
	
	private:
		ScalarConverter(void);
		enum
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			TYPES,
			UNKNOWN
		};
		static unsigned char	_getType(const std::string &s);

		static void				_displayChar(const std::string &s, const unsigned char type);
		static void				_displayInt(const std::string &s, const unsigned char type);
		static void				_displayFloat(const std::string &s, const unsigned char type);
		static void				_displayDouble(const std::string &s, const unsigned char type);

};

// Utils =======================================================================

#endif
