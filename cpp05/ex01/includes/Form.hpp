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

		static const char			*defaultName;
		static const t_uint8		minGrade;
		static const t_uint8 		maxGrade;
		static const t_uint8		defaultGrade;

		class GradeException: public std::exception
		{
			public:
				const char	*what(void) const throw();
				const char	*name(void) const;

			protected:
				GradeException(const char *msg);
				const char			*_msg;

			private:
				static const char	*_name;
		};

		class GradeTooHighException: public GradeException
		{
			public:
				GradeTooHighException(void);
		};

		class GradeTooLowException: public GradeException
		{
			public:
				GradeTooLowException(void);
		};

	private:
		std::string					_name;	
		t_uint8						_grade;	

};

// Utils =======================================================================
std::ostream	&operator<<(std::ostream &outstream, const t_uint8 &insert);
std::ostream	&operator<<(std::ostream &outstream, const Bureaucrat &insert);

#endif
