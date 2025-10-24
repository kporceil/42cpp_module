/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:39:56 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 19:44:48 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name): _name(name), _weapon(NULL) {
	std::cout << "HumanB : constructor called" << std::endl;
	return ;
}

void	HumanB::setWeapon(const Weapon &weapon) {
	this->_weapon = &weapon;
	return ;
}

void	HumanB::attack(void) {
	std::cout << this->_name << " attacks with their " << (this->_weapon ? this->_weapon->getType() : "") << std::endl;
	return ;
}

HumanB::~HumanB(void) {
	std::cout << "HumanB : destructor called" << std::endl;
	return ;
}
