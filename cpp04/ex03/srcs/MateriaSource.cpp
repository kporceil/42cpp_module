/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:14:38 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/25 17:42:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {
	std::cout << "MateriaSource : default constructor called" << std::endl;
	m_inventory[0] = NULL;
	m_inventory[1] = NULL;
	m_inventory[2] = NULL;
	m_inventory[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& cpy) {
	std::cout << "MateriaSource : copy constructor called" << std::endl;
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

MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource : destructor called" << std::endl;
	if (m_inventory[0])
		delete m_inventory[0];
	if (m_inventory[1])
		delete m_inventory[1];
	if (m_inventory[2])
		delete m_inventory[2];
	if (m_inventory[3])
		delete m_inventory[3];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& cpy) {
	std::cout << "MateriaSource : assign operator called" << std::endl;
	if (this != &cpy)
	{
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

void	MateriaSource::learnMateria(AMateria* m) {
	if (m_inventory[0] == NULL)
		m_inventory[0] = m;
	else if (m_inventory[1] == NULL)
		m_inventory[1] = m;
	else if (m_inventory[2] == NULL)
		m_inventory[2] = m;
	else if (m_inventory[3] == NULL)
		m_inventory[3] = m;
	else
		std::cerr << "Cannot learn Materia: inventory full" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	if (m_inventory[0] && m_inventory[0]->getType() == type)
		return (m_inventory[0]->clone());
	if (m_inventory[1] && m_inventory[1]->getType() == type)
		return (m_inventory[1]->clone());
	if (m_inventory[2] && m_inventory[2]->getType() == type)
		return (m_inventory[2]->clone());
	if (m_inventory[3] && m_inventory[3]->getType() == type)
		return (m_inventory[3]->clone());
	else
		std::cerr << "MateriaSource: Cannot create materia of type " << type << ": Unknow materia type" << std::endl;
	return (NULL);
}
