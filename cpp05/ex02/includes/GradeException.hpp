/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:13:04 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/07 18:10:22 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__GRADE_EXCEPTION_HPP__
# define	__GRADE_EXCEPTION_HPP__

# include <exception>

class GradeException: public std::exception
{
	public:
		GradeException(void);
		GradeException(const char *targetType, const char *msg);
		virtual ~GradeException(void) throw();

		virtual const char	*what(void) const throw();

	private:
		static const std::string	_excptType;
		const std::string			_targetType;
		const std::string			_errMsg;
		const std::string			_whatMsg;
};

#endif
