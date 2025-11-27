/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:43:25 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/25 14:43:58 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__CLAPTRAP_HPP__
# define	__CLAPTRAP_HPP__

# include	<iostream>

# define	DEFAULT_NAME	"Anonymous" 
# define	DEFAULT_HP		10 
# define	DEFAULT_EP		10
# define	DEFAULT_DAMAGE	0

# define	ATTACK_COST		1
# define	REPAIR_COST		1

class		ClapTrap
{

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap(void);
    	
		ClapTrap		&operator=(const ClapTrap &assign);
                    	
		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			displayStats(void);

	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamages;

};

#endif
