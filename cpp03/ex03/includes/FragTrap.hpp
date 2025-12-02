/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:50:29 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/27 16:50:52 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__FRAGTRAP_HPP__
# define	__FRAGTRAP_HPP__

# include "ClapTrap.hpp"

# define	FT_DEF_NAME	"Anonymous" 
# define	FT_DEF_HP		100 
# define	FT_DEF_EP		100
# define	FT_DEF_DAMAGE	30

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		virtual ~FragTrap(void);
    	
		FragTrap		&operator=(const FragTrap &assign);
                    	
		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			highFivesGuys(void);
};

#endif
