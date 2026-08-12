/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:09:39 by abetemps          #+#    #+#             */
/*   Updated: 2026/08/12 19:38:19 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__ERRORS_HPP__
# define	__ERRORS_HPP__

# include	<exception>
# include	"text_formatting.hpp"

# define	USAGE		YELLOW "Usage: ./PmergeMe <positive.s integer.s> <...>\n" \
						DIM "example: ./PmergeMe \"24 211 12\" 69 9 \"26 47\"" RST

# define	ERR			RED BOLD "Error: " RST BOLD
# define	BAD_ARG		RED "invalid arguments" RST
# define	BAD_ARG_QTY	RED "wrong number of arguments" RST

#endif
