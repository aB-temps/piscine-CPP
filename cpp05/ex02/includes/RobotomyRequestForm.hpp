/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:19:44 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/04 00:11:25 by abetemps         ###   ########.fr       */
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

	private:
		void						_executeSelf(void) const;
		static const char			*_defaultName;
		static const t_uint8		_defaultSignGrade;
		static const t_uint8		_defaultExecGrade;
};

#endif
