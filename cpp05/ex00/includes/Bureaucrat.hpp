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

# include <iostream>

// Typedef =====================================================================
typedef unsigned char	t_uint8;

// Namespace ===================================================================
namespace	ns_BureaucratSettings
{
	extern const char		defaultName[];
	extern const t_uint8	minGrade;
	extern const t_uint8 	maxGrade;
	extern const t_uint8	defaultGrade;
}

// Class declaration ===========================================================
class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(const std::string &name, const t_uint8 &grade);
		~Bureaucrat(void);

		Bureaucrat			&operator=(const Bureaucrat &assign);

		const std::string	&getName(void) const;
		const t_uint8		&getGrade(void) const;

	private:
		std::string	_name;	
		t_uint8		_grade;	

};

// Utils =======================================================================
std::ostream	&operator<<(std::ostream &outstream, const t_uint8 &insert);
std::ostream	&operator<<(std::ostream &outstream, const Bureaucrat &insert);

#endif
