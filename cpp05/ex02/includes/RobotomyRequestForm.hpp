/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:19:44 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/24 18:22:17 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__ROBOTOMYREQUESTFORM_HPP__
# define	__ROBOTOMYREQUESTFORM_HPP__

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(const char *target);
		RobotomyRequestForm(RobotomyRequestForm &copy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(RobotomyRequestForm &assign);

		static const char			*defaultName;
		static const t_uint8		defaultSignGrade;
		static const t_uint8		defaultExecGrade;

		void						execute(Bureaucrat const &executor) const;
};

#endif
