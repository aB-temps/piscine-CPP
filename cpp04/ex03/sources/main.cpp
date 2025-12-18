/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 11:14:22 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

using	std::cout;
using	std::endl;

// int main(void)
// {
// 	cout << ">>> XXXXXXXX:\n";
// 	cout << "> Constructors:" << endl;
//
//
// 	cout << endl;
//
// 	cout << "> Destructors:" << endl;
//
// 	cout << endl;
//
// 	return (0);
// }

int	main(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());


	ICharacter* me = new Character("me");
	AMateria* tmp;

	cout << "GroundQty:" << Character::getGroundQty() << endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->unequip(1);
	cout << "GroundQty:" << Character::getGroundQty() << endl;

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	Character::clearGround();

	return 0;
}
