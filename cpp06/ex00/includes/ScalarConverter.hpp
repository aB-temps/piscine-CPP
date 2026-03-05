/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/05 16:25:15 by abetemps         ###   ########.fr       */
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
		// ScalarConverter(void);
		// ScalarConverter(const ScalarConverter &copy);
		// ~ScalarConverter(void);
		//
		// ScalarConverter		&operator=(const ScalarConverter &assign);
                            
		static	void		convert(const std::string &s);

};

// Utils =======================================================================

#endif
