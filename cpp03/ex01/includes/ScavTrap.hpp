/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:50:29 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/27 16:03:53 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__SCAVTRAP_HPP__
# define	__SCAVTRAP_HPP__

# include "ClapTrap.hpp"

# define	ST_DEF_NAME	"Anonymous" 
# define	ST_DEF_HP		100 
# define	ST_DEF_EP		50
# define	ST_DEF_DAMAGE	20

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap(void);
    	
		ScavTrap		&operator=(const ScavTrap &assign);
                    	
		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			guardGate(void);
		void			displayStats(void);

	private:
		bool			_gateKeeperMode;

};

#endif
