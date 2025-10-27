/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:50:10 by abetemps          #+#    #+#             */
/*   Updated: 2025/09/27 00:52:19 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		__STYLE_HPP__
# define	__STYLE_HPP__

# include "text_formatting.hpp"

# define JOINTER_LEFT			"╠"
# define JOINTER_RIGHT			"╣"
# define CORNER_TOP_LEFT		"╔"
# define CORNER_TOP_RIGHT		"╗"
# define CORNER_BOTTOM_LEFT 	"╚"
# define CORNER_BOTTOM_RIGHT	"╝"
# define WALL					"║"
# define FLOOR					"═"
# define SEPARATOR				"|"

# define CLR_MAIN				BLUE
# define CLR_SCND				CYAN
# define CLR_ALT				MAGENTA
# define CLR_SUCCESS			GREEN
# define CLR_WARN				YELLOW
# define CLR_ERROR				RED

#endif
