/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/10 13:20:11 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__DATA_HPP__
# define	__DATA_HPP__

# include <iostream>

class	Data
{
	public:
		Data(void);
		Data(const Data &copy);
		Data(const std::string &name);
		~Data(void);

		Data	&operator=(const Data &assign);
	
		const std::string	&getName(void) const;

	private:
		std::string	_name;
};

#endif
