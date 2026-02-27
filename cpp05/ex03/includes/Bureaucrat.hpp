/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/07 18:10:58 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__BUREAUCRAT_HPP__
# define	__BUREAUCRAT_HPP__

# include <iostream>
# include "GradeException.hpp"

class AForm;

// Typedef =====================================================================
typedef unsigned char	t_uint8;

// Class declaration ===========================================================
class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(const std::string &name, const t_uint8 &grade);
		~Bureaucrat(void);

		Bureaucrat					&operator=(const Bureaucrat &assign);
		Bureaucrat					operator++(int);
		Bureaucrat					&operator++(void);
		Bureaucrat					operator--(int);
		Bureaucrat					&operator--(void);
                            	
		const std::string			&getName(void) const;
		const t_uint8				&getGrade(void) const;

		void						upGrade(void);
		void						downGrade(void);
		void						signForm(AForm &f);
		void						executeForm(AForm const &form) const;

		static const t_uint8		minGrade;
		static const t_uint8 		maxGrade;

		class BureaucratException: public GradeException
		{
			public:
				BureaucratException();
				BureaucratException(const char *msg);
		};

		class GradeTooLowException: public BureaucratException
		{
			public:
				GradeTooLowException();
		};

		class GradeTooHighException: public BureaucratException
		{
			public:
				GradeTooHighException();
		};

	private:
		static const char			*_defaultName;
		static const t_uint8		_defaultGrade;

		std::string					_name;	
		t_uint8						_grade;	

};

// Utils =======================================================================
std::ostream	&operator<<(std::ostream &outstream, const t_uint8 &insert);
std::ostream	&operator<<(std::ostream &outstream, const Bureaucrat &insert);

#endif
