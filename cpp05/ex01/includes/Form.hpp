/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/07 18:09:59 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__FORM_HPP__
# define	__FORM_HPP__

# include <iostream>
# include "Bureaucrat.hpp"

// Class declaration ===========================================================
class	Form
{
	public:
		Form(void);
		Form(const Form &copy);
		Form(const std::string &name, const t_uint8 &sign_grade, const t_uint8 &exec_grade);
		~Form(void);

		Form						&operator=(const Form &assign);

		const std::string			&getName(void) const;
		const t_uint8				&getSignGrade(void) const;
		const t_uint8				&getExecGrade(void) const;
		const bool					&getStatus(void) const;

		void						beSigned(const Bureaucrat &b);

		static const char			*defaultName;
		static const t_uint8		defaultSignGrade;
		static const t_uint8		defaultExecGrade;

		class FormException:  public GradeException
		{
			public:
				FormException();
				FormException(const char *msg);
		};

		class GradeTooLowException: public FormException
		{
			public:
				GradeTooLowException();
		};

		class GradeTooHighException: public FormException
		{
			public:
				GradeTooHighException();
		};

		class AlreadySignedException: public FormException
		{
			public:
				AlreadySignedException();
		};

	private:
		const std::string			_name;	
		const t_uint8				_sign_grade;	
		const t_uint8				_exec_grade;	
		bool						_signed;

};

// Utils =======================================================================
std::ostream	&operator<<(std::ostream &outstream, const Form &insert);

#endif
