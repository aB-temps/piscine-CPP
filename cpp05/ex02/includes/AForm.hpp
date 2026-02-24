/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/24 18:17:18 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__AFORM_HPP__
# define	__AFORM_HPP__

# include <iostream>
# include "Bureaucrat.hpp"

// Class declaration ===========================================================
class	AForm
{
	public:
		AForm(void);
		AForm(const AForm &copy);
		AForm(const std::string &name, const std::string &target, const t_uint8 &sign_grade, const t_uint8 &exec_grade);
		~AForm(void);

		AForm						&operator=(const AForm &assign);

		const std::string			&getName(void) const;
		const std::string			&getTarget(void) const;
		const t_uint8				&getSignGrade(void) const;
		const t_uint8				&getExecGrade(void) const;
		const bool					&getStatus(void) const;

		void						signForm(const Bureaucrat &b);

		static const char			*defaultName;
		static const char			*defaultTarget;
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
		void						_beSigned(const Bureaucrat &b);
		const std::string			_name;	
		const std::string			_target;	
		const t_uint8				_sign_grade;	
		const t_uint8				_exec_grade;	
		bool						_signed;

};

// Utils =======================================================================
std::ostream	&operator<<(std::ostream &outstream, const AForm &insert);

#endif
