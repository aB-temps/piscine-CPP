/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:28:06 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/24 15:20:12 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "errors.hpp"

using	std::cout;
using	std::endl;

void	put_stream_error(int state, const char *func, const char *calling_func)
{
	cout	<< CLR_ERROR BOLD << "Error in function " << RST
			<< func << CLR_ERROR << ": " << RST
			<< calling_func << RST << endl;
	
	cout	<< CLR_ERROR BOLD
			<< (state < std::ios::failbit ? ERR_M_BADBIT : ERR_M_FAILBIT)
			<< RST << endl;
}
