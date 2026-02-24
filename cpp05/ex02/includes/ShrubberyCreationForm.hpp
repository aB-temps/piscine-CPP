/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:19:48 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/24 18:21:19 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__SHRUBBERYCREATIONFORM_HPP__
# define	__SHRUBBERYCREATIONFORM_HPP__

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(const char *target);
		ShrubberyCreationForm(ShrubberyCreationForm &copy);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm &assign);

		static const char			*defaultName;
		static const t_uint8		defaultSignGrade;
		static const t_uint8		defaultExecGrade;
};

#endif
