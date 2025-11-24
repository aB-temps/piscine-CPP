/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:27:29 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/24 16:31:01 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsp.hpp"

using		std::cout;
using		std::endl;

static Point	build_vec2(const Point p1, const Point p2)
{
	Fixed x(p2.getX() - p1.getX());
	Fixed y(p2.getY() - p1.getY());
	Point vec(x.toFloat(), y.toFloat());

	return (vec);
}

static Fixed	cross_product(const Point u, const Point v, const Point p)
{
	Point vecUV = build_vec2(u, v);
	Point vecUP = build_vec2(u, p);

	Fixed xproduct(vecUV.getX() * vecUP.getY() - vecUV.getY() * vecUP.getX());

	return (xproduct);
}


bool			bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed xproductAB = cross_product(a,b,point);
	Fixed xproductBC = cross_product(b,c,point);
	Fixed xproductCA = cross_product(c,a,point);

	if ((xproductAB > 0 && xproductBC > 0 && xproductCA > 0) || (xproductAB < 0 && xproductBC < 0 && xproductCA < 0))
		return (true);
	else
		return (false);
}
