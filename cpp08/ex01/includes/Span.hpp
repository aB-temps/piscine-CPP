/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/20 21:27:09 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__SPAN_HPP__
# define	__SPAN_HPP__

# include <iostream>
# include <vector>

// Typedef =====================================================================
typedef unsigned char	t_uint8;

// Class declaration ===========================================================
class	Span
{
	public:
		Span(const unsigned int &capacity);
		Span(const Span &copy);
		~Span(void);

		Span			&operator=(const Span &assign);
		int				&operator[](const unsigned int &i);
		const int		&operator[](const unsigned int &i) const;
	            		
		void			addNumber(const int &n);
		void			addRange(const unsigned int &r);
		int				longestSpan(void) const;
		int				shortestSpan(void) const;

		void			outOfRange(const unsigned int &i, const unsigned char mode) const;

		unsigned int	getSize(void) const;

	private:
		std::vector<int>	_array;
		unsigned int		_capacity;
		

};

// Utils =======================================================================
std::ostream	&operator<<(std::ostream &out, const Span &sp);

#endif
