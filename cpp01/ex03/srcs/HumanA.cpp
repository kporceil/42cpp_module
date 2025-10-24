/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:37:04 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 19:39:39 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, const Weapon &weapon): _name(name), _weapon(weapon) {
	std::cout << "HumanA : constructor called" << std::endl;
	return ;
}

void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "HumanA : destructor called" << std::endl;
	return ;
}
