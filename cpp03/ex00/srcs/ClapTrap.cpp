/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:50:41 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/04 16:19:31 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): m_hitPoints(10), m_energyPoints(10), m_attackDamage(0) {
	std::cout << "ClapTrap : default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0) {
	std::cout << "ClapTrap : constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy) {
	std::cout << "ClapTrap : copy constructor called" << std::endl;
	*this = cpy;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap : destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& name) {
	if (m_energyPoints == 0) {
		std::cout << "ClapTrap " << m_name << " can't attack because he has no energy points" << std::endl;
		return ;
	}
	if (m_hitPoints == 0) {
		std::cout << "ClapTrap " << m_name << " can't attack because he has no hit points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << m_name << " attacks " << name << " causing " << m_attackDamage << " points of damage!" << std::endl;
	--m_energyPoints;
}

void	ClapTrap::takeDamage(unsigned int	amount) {
	if (m_hitPoints == 0) {
		std::cout << "ClapTrap " << m_name << " can't take damage because he has no hit points" << std::endl;
		return ;
	}
	if (amount >= m_hitPoints) {
		std::cout << "ClapTrap " << m_name << " take " << amount << " points of damage, causing him to die" << std::endl;
		m_hitPoints = 0;
		return;
	}
	m_hitPoints -= amount;
	std::cout << "ClapTrap " << m_name << " take " << amount << " points of damage, leaving him with " << m_hitPoints << " hit points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int	amount) {
	if (m_energyPoints == 0) {
		std::cout << "ClapTrap " << m_name << " can't repair himself because he has no energy points" << std::endl;
		return ;
	}
	if (m_hitPoints == 0) {
		std::cout << "ClapTrap " << m_name << " can't repair himself because he has no hit points" << std::endl;
		return ;
	}
	m_hitPoints += amount;
	std::cout << "ClapTrap " << m_name << " regains " << amount << " hit points by repairing himself, he now have " << m_hitPoints << " hit points" << std::endl;
	--m_energyPoints;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& cpy) {
	std::cout << "ClapTrap : assign operator called" << std::endl;
	if (this != &cpy)
	{
		m_name = cpy.m_name;
		m_hitPoints = cpy.m_hitPoints;
		m_energyPoints = cpy.m_energyPoints;
		m_attackDamage = cpy.m_attackDamage;
	}
	return (*this);
}
