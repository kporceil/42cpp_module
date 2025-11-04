/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:07:34 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/04 17:11:21 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) {
	std::cout << "ScavTrap : default constructor called" << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) {
	std::cout << "ScavTrap : constructor called" << std::endl;
	m_name = name;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << m_name << " is now in gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& name) {
	if (m_energyPoints == 0) {
		std::cout << "ScavTrap " << m_name << " can't attack because he has no energy points" << std::endl;
		return ;
	}
	if (m_hitPoints == 0) {
		std::cout << "ScavTrap " << m_name << " can't attack because he has no hit points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << m_name << " attacks " << name << " causing " << m_attackDamage << " points of damage!" << std::endl;
	--m_energyPoints;
}

ScavTrap::ScavTrap(const ScavTrap& cpy) {
	std::cout << "ScavTrap : copy constructor called" << std::endl;
	*this = cpy;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap : destructor called" << std::endl;
}
