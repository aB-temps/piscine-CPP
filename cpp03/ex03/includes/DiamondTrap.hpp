/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:50:29 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/27 17:03:55 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__DIAMONDTRAP_HPP__
# define	__DIAMONDTRAP_HPP__

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define	DT_DEF_NAME "Anonymous"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap(void);
    	
		DiamondTrap		&operator=(const DiamondTrap &assign);
                    	
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			whoAmI(void);

	private:
		std::string		_name;
};

#endif
