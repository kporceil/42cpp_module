/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:00:00 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/25 18:00:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void	print_title(std::string const& title) {
	std::cout << "\n========================================\n"
	<< "  " << title << '\n'
	<< "========================================\n" << std::endl;
}

void	test_subject_main(void) {
	print_title("SUBJECT TEST");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	test_materia_creation(void) {
	print_title("TEST CREATION MATERIAS");

	std::cout << "Creating Ice materia:" << std::endl;
	AMateria* ice = new Ice();
	if (ice->getType() == "ice")
		std::cout << "Type check: OK (" << ice->getType() << ")" << std::endl;
	else
		std::cout << "Type check: FAIL | expected : ice | Type: " << ice->getType() << std::endl;

	std::cout << "\nCreating Cure materia:" << std::endl;
	AMateria* cure = new Cure();
	std::cout << "Type: " << cure->getType() << std::endl;
	if (cure->getType() == "cure")
		std::cout << "Type check: OK (" << cure->getType() << ")" << std::endl;
	else
		std::cout << "Type check: FAIL | expected : cure | Type: " << cure->getType() << std::endl;

	delete ice;
	delete cure;
}

void	test_materia_clone() {
	print_title("TEST CLONE MATERIAS");

	Ice* ice = new Ice();
	AMateria* cloned_ice = ice->clone();
	if (ice->getType() == cloned_ice->getType())
		std::cout << "Clone check: OK" << std::endl;
	else
		std::cout << "Clone check: FAIL | Expected Type: ice | Type: " << cloned_ice->getType() << std::endl;
	if (ice != cloned_ice)
		std::cout << "Pointer check: OK" << std::endl;
	else
		std::cout << "Point check: FAIL | original and clone address are the same | Original: " << ice << " | Clone: " << cloned_ice << std::endl;

	Cure* cure = new Cure();
	AMateria* cloned_cure = cure->clone();
	if (cure->getType() == cloned_cure->getType())
		std::cout << "Clone check: OK" << std::endl;
	else
		std::cout << "Clone check: FAIL | Expected Type: cure | Type: " << cloned_cure->getType() << std::endl;
	if (cure != cloned_cure)
		std::cout << "Pointer check: OK" << std::endl;
	else
		std::cout << "Point check: FAIL | original and clone address are the same | Original: " << cure << " | Clone: " << cloned_cure << std::endl;

	delete ice;
	delete cloned_ice;
	delete cure;
	delete cloned_cure;
}

void	test_materia_source() {
	print_title("TEST MATERIA SOURCE");

	MateriaSource* src = new MateriaSource();

	std::cout << "Learning Ice materia:" << std::endl;
	src->learnMateria(new Ice());

	std::cout << "\nLearning Cure materia:" << std::endl;
	src->learnMateria(new Cure());

	std::cout << "\nCreating ice materia from source:" << std::endl;
	AMateria* tmp = src->createMateria("ice");
	if (tmp)
		std::cout << "Created materia type: " << tmp->getType() << std::endl;
	delete tmp;

	std::cout << "\nCreating cure materia from source:" << std::endl;
	tmp = src->createMateria("cure");
	if (tmp)
		std::cout << "Created materia type: " << tmp->getType() << std::endl;
	delete tmp;

	std::cout << "\nTrying to create unknown materia:" << std::endl;
	tmp = src->createMateria("fire");
	if (!tmp)
		std::cout << "NULL returned as expected" << std::endl;

	delete src;
}

void	test_materia_source_full() {
	print_title("TEST MATERIA SOURCE FULL");

	MateriaSource* src = new MateriaSource();

	std::cout << "Learning 4 materias:" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\nTrying to learn 5th materia (should fail):" << std::endl;
	AMateria* extra = new Ice();
	src->learnMateria(extra);
	delete extra;

	delete src;
}

void	test_character_basic() {
	print_title("TEST CHARACTER BASIC");

	Character* me = new Character("Warrior");
	std::cout << "Character name: " << me->getName() << std::endl;

	std::cout << "\nEquipping Ice materia:" << std::endl;
	me->equip(new Ice());

	std::cout << "\nEquipping Cure materia:" << std::endl;
	me->equip(new Cure());

	Character* target = new Character("Enemy");
	std::cout << "\nUsing materia 0 on " << target->getName() << ":" << std::endl;
	me->use(0, *target);

	std::cout << "\nUsing materia 1 on " << target->getName() << ":" << std::endl;
	me->use(1, *target);

	delete me;
	delete target;
}

void	test_character_full_inventory() {
	print_title("TEST CHARACTER FULL INVENTORY");

	Character* me = new Character("Mage");

	std::cout << "Filling inventory with 4 materias:" << std::endl;
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());
	me->equip(new Cure());

	std::cout << "\nTrying to equip 5th materia (should fail):" << std::endl;
	AMateria* extra = new Ice();
	me->equip(extra);
	delete extra;

	Character* target = new Character("Target");
	std::cout << "\nUsing all 4 materias:" << std::endl;
	me->use(0, *target);
	me->use(1, *target);
	me->use(2, *target);
	me->use(3, *target);

	delete me;
	delete target;
}

void	test_character_unequip() {
	print_title("TEST CHARACTER UNEQUIP");

	Character* me = new Character("Rogue");

	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	me->equip(ice);
	me->equip(cure);

	Character* target = new Character("Dummy");

	std::cout << "Using materia 0:" << std::endl;
	me->use(0, *target);

	std::cout << "\nUnequipping materia 0:" << std::endl;
	me->unequip(0);

	std::cout << "\nTrying to use unequipped materia 0 (should fail):" << std::endl;
	me->use(0, *target);

	std::cout << "\nUsing materia 1 (still equipped):" << std::endl;
	me->use(1, *target);

	std::cout << "\nDeleting unequipped materia manually:" << std::endl;
	delete ice;

	delete me;
	delete target;
}

void	test_character_invalid_operations() {
	print_title("TEST CHARACTER INVALID OPERATIONS");

	Character* me = new Character("Tester");
	Character* target = new Character("Target");

	std::cout << "Trying to use materia at empty slot 0:" << std::endl;
	me->use(0, *target);

	std::cout << "\nTrying to use materia at invalid index -1:" << std::endl;
	me->use(-1, *target);

	std::cout << "\nTrying to use materia at invalid index 4:" << std::endl;
	me->use(4, *target);

	std::cout << "\nTrying to unequip at empty slot 0:" << std::endl;
	me->unequip(0);

	std::cout << "\nTrying to unequip at invalid index -1:" << std::endl;
	me->unequip(-1);

	std::cout << "\nTrying to unequip at invalid index 4:" << std::endl;
	me->unequip(4);

	delete me;
	delete target;
}

void	test_character_copy() {
	print_title("TEST CHARACTER COPY");

	Character* original = new Character("Original");
	original->equip(new Ice());
	original->equip(new Cure());

	std::cout << "Creating copy via copy constructor:" << std::endl;
	Character* copy = new Character(*original);
	std::cout << "Copy name: " << copy->getName() << std::endl;

	Character* target = new Character("Target");

	std::cout << "\nUsing materia from original:" << std::endl;
	original->use(0, *target);
	original->use(1, *target);

	std::cout << "\nUsing materia from copy (should have cloned materias):" << std::endl;
	copy->use(0, *target);
	copy->use(1, *target);

	delete original;
	delete copy;
	delete target;
}

void	test_character_assignment() {
	print_title("TEST CHARACTER ASSIGNMENT");

	Character* char1 = new Character("Character1");
	char1->equip(new Ice());
	char1->equip(new Cure());

	Character* char2 = new Character("Character2");
	char2->equip(new Ice());

	std::cout << "Before assignment:" << std::endl;
	std::cout << "char1 name: " << char1->getName() << std::endl;
	std::cout << "char2 name: " << char2->getName() << std::endl;

	std::cout << "\nAssigning char1 to char2:" << std::endl;
	*char2 = *char1;

	std::cout << "\nAfter assignment:" << std::endl;
	std::cout << "char2 name: " << char2->getName() << std::endl;

	Character* target = new Character("Target");

	std::cout << "\nUsing materias from char2 (should have char1's materias):" << std::endl;
	char2->use(0, *target);
	char2->use(1, *target);

	delete char1;
	delete char2;
	delete target;
}

void	test_materia_source_copy() {
	print_title("TEST MATERIA SOURCE COPY");

	MateriaSource* original = new MateriaSource();
	original->learnMateria(new Ice());
	original->learnMateria(new Cure());

	std::cout << "Creating copy via copy constructor:" << std::endl;
	MateriaSource* copy = new MateriaSource(*original);

	std::cout << "\nCreating materia from original:" << std::endl;
	AMateria* tmp1 = original->createMateria("ice");
	if (tmp1)
		std::cout << "Created from original: " << tmp1->getType() << std::endl;

	std::cout << "\nCreating materia from copy:" << std::endl;
	AMateria* tmp2 = copy->createMateria("cure");
	if (tmp2)
		std::cout << "Created from copy: " << tmp2->getType() << std::endl;

	delete tmp1;
	delete tmp2;
	delete original;
	delete copy;
}

int main() {
	test_subject_main();
	test_materia_creation();
	test_materia_clone();
	test_materia_source();
	test_materia_source_full();
	test_character_basic();
	test_character_full_inventory();
	test_character_unequip();
	test_character_invalid_operations();
	test_character_copy();
	test_character_assignment();
	test_materia_source_copy();
	return 0;
}
