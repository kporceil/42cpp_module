/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:57:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/25 17:37:46 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(void) {
	m_inventory[0] = NULL;
	m_inventory[1] = NULL;
	m_inventory[2] = NULL;
	m_inventory[3] = NULL;
	std::cout << "Character : default constructor called" << std::endl;
}

Character::Character(std::string const& name): m_name(name) {
	m_inventory[0] = NULL;
	m_inventory[1] = NULL;
	m_inventory[2] = NULL;
	m_inventory[3] = NULL;
	std::cout << "Character : constructor called" << std::endl;
}

Character::Character(const Character& cpy): m_name(cpy.m_name) {
	std::cout << "Character : copy constructor called" << std::endl;
	if (cpy.m_inventory[0])
		m_inventory[0] = cpy.m_inventory[0]->clone();
	else
		m_inventory[0] = NULL;
	if (cpy.m_inventory[1])
		m_inventory[1] = cpy.m_inventory[1]->clone();
	else
		m_inventory[1] = NULL;
	if (cpy.m_inventory[2])
		m_inventory[2] = cpy.m_inventory[2]->clone();
	else
		m_inventory[2] = NULL;
	if (cpy.m_inventory[3])
		m_inventory[3] = cpy.m_inventory[3]->clone();
	else
		m_inventory[3] = NULL;
}

Character::~Character(void) {
	std::cout << "Character : destructor called" << std::endl;
	if (m_inventory[0])
		delete m_inventory[0];
	if (m_inventory[1])
		delete m_inventory[1];
	if (m_inventory[2])
		delete m_inventory[2];
	if (m_inventory[3])
		delete m_inventory[3];
}

Character&	Character::operator=(const Character& cpy) {
	std::cout << "Character : assign operator called" << std::endl;
	if (this != &cpy)
	{
		m_name = cpy.m_name;
		if (m_inventory[0])
			delete m_inventory[0];
		if (m_inventory[1])
			delete m_inventory[1];
		if (m_inventory[2])
			delete m_inventory[2];
		if (m_inventory[3])
			delete m_inventory[3];
		if (cpy.m_inventory[0])
			m_inventory[0] = cpy.m_inventory[0]->clone();
		else
			m_inventory[0] = NULL;
		if (cpy.m_inventory[1])
			m_inventory[1] = cpy.m_inventory[1]->clone();
		else
			m_inventory[1] = NULL;
		if (cpy.m_inventory[2])
			m_inventory[2] = cpy.m_inventory[2]->clone();
		else
			m_inventory[2] = NULL;
		if (cpy.m_inventory[3])
			m_inventory[3] = cpy.m_inventory[3]->clone();
		else
			m_inventory[3] = NULL;
	}
	return (*this);
}

std::string const&	Character::getName() const {
	return (m_name);
}

void	Character::equip(AMateria* m) {
	if (m_inventory[0] == NULL)
		m_inventory[0] = m;
	else if (m_inventory[1] == NULL)
		m_inventory[1] = m;
	else if (m_inventory[2] == NULL)
		m_inventory[2] = m;
	else if (m_inventory[3] == NULL)
		m_inventory[3] = m;
	else
		std::cerr << "Cannot equip Materia: inventory full" << std::endl;
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && m_inventory[idx])
		m_inventory[idx] = NULL;
	else if (idx < 0 || idx >= 4)
		std::cerr << "Cannot unequip the " << idx << " materia: out of range [0:3]" << std::endl;
	else
		std::cerr << "Cannot unequip the " << idx << " materia: no materia is equiped at the " << idx << " slot" << std::endl;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && m_inventory[idx])
		m_inventory[idx]->use(target);
	else if (idx < 0 || idx >= 4)
		std::cerr << "Cannot use the " << idx << " materia: out of range [0:3]" << std::endl;
	else
		std::cerr << "Cannot use the " << idx << " materia: no materia is equiped at the " << idx << " slot" << std::endl;
}
