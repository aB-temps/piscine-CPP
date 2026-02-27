/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:19:40 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/24 18:22:57 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__PRESIDENTIALPARDONFORM_HPP__
# define	__PRESIDENTIALPARDONFORM_HPP__

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(const char *target);
		PresidentialPardonForm(PresidentialPardonForm &copy);
		~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(PresidentialPardonForm &assign);

		void						execute(Bureaucrat const &executor) const;

	private:
		static const char			*_defaultName;
		static const t_uint8		_defaultSignGrade;
		static const t_uint8		_defaultExecGrade;
};

#endif
