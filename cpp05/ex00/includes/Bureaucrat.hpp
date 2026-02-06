/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/06 18:57:18 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__BUREAUCRAT_HPP__
# define	__BUREAUCRAT_HPP__

namespace	bureaucratDefault
{
	extern const char defName[];
	extern const uint8_t defGrade;
}

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(const std::string &name, const uint8_t &grade);
		~Bureaucrat(void);

		Bureaucrat			&operator=(const Bureaucrat &assign);

		const std::string	&getName(void) const;
		const uint8_t		&getGrade(void) const;

	private:
		const std::string	_name;	
		const uint8_t		_grade;	

};

#endif
