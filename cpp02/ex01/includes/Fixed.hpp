/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:33:23 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/10 19:58:18 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__FIXED_HPP__
# define	__FIXED_HPP__

class		Fixed
{
	public:
		Fixed(void);
		Fixed(const int v);
		Fixed(const float v);
		Fixed(const	Fixed &copy);
		~Fixed(void);

		Fixed	&operator=(const Fixed &assign);
		float	operator<<(const Fixed &insert);
                			
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_fract;

};

#endif
