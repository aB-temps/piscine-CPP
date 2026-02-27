/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/27 15:58:27 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__INTERN_HPP__
# define	__INTERN_HPP__

# include <iostream>
# include "GradeException.hpp"

class AForm;

// Typedef =====================================================================
typedef unsigned char	t_uint8;


// Class declaration ===========================================================
class	Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		~Intern(void);

		Intern							&operator=(const Intern &assign);

		AForm							*makeForm(const std::string &name, const std::string &target);

		enum						e_formTypes
		{
			SHRUBBERY,
			ROBOTOMY,
			PRESIDENTIAL,
			FORMS_QTY,
		};

		static const char				*formNames[FORMS_QTY];

		class InternException:  public GradeException
		{
			public:
				InternException();
				InternException(const char *msg);
		};

		class UnknownFormException: public InternException
		{
			public:
				UnknownFormException(void);
		};

		typedef	AForm	*(*formConstructor)(const char *);

		template <typename T>
		static AForm	*buildForm(const char *name)
		{
			return (new T(name));
		}

		static const formConstructor	_constructors[FORMS_QTY];

};

#endif
