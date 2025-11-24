/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:51:58 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/24 17:53:31 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__POINT_HPP__
# define	__POINT_HPP__

# include	"Fixed.hpp"

class		Point
{

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &copy);
		~Point(void);

		Point		&operator=(const Point &assign);

		Fixed		getX(void) const;
		Fixed		getY(void) const;

	private:
		const Fixed		_x;
		const Fixed		_y;
};

#endif
