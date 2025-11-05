/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:52:48 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/04 22:54:17 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) {
	std::cout << "FragTrap : default constructor called" << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) {
	std::cout << "FragTrap : constructor called" << std::endl;
	m_name = name;
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& cpy) {
	std::cout << "FragTrap : copy constructor called" << std::endl;
	*this = cpy;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap : destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << m_name << " want to do a High Five !" << std::endl;
}
