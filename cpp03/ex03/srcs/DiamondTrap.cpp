/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:44:36 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/05 18:48:39 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) {
	std::cout << "DiamondTrap : default constructor called" << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name") {
	std::cout << "DiamondTrap : constructor called" << std::endl;
	m_name = name;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& cpy) {
	std::cout << "DiamondTrap : copy constructor called" << std::endl;
	*this = cpy;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap : destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "I am " << m_name << " Diamond Trap, and " << ClapTrap::m_name << " Clap Trap" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& cpy) {
	std::cout << "DiamondTrap : assign operator called" << std::endl;
	if (this != &cpy) {
		ClapTrap::operator=(cpy);
		this->m_name = cpy.m_name;
	}
	return (*this);
}
