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

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	AMateria* tmp;
	cout << "GroundQty:" << Character::getGroundQty() << endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	cout << endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	cout << endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->unequip(0);
	cout << "GroundQty:" << Character::getGroundQty() << endl;
	me->unequip(1);
	cout << "GroundQty:" << Character::getGroundQty() << endl;
	me->unequip(2);
	cout << "GroundQty:" << Character::getGroundQty() << endl;
	me->unequip(3);
	cout << "GroundQty:" << Character::getGroundQty() << endl;
	me->equip(tmp);
	cout << "GroundQty:" << Character::getGroundQty() << endl;
	me->unequip(3);
	cout << "GroundQty:" << Character::getGroundQty() << endl;
	me->equip(tmp);
	cout << endl;

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	cout << endl;

	delete bob;
	delete me;
	delete src;
	Character::clearGround();

	return 0;
}
