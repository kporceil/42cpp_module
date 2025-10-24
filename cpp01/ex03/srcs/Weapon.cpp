/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:28:49 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 19:33:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void) {
	std::cout << "Weapon : default constructor called" << std::endl;
	return ;
}

Weapon::Weapon(const std::string& type): _type(type) {
	std::cout << "Weapon : constructor called" << std::endl;
	return ;
}

const std::string	&Weapon::getType(void) const {
	return (this->_type);
}

void	Weapon::setType(const std::string &type) {
	this->_type = type;
	return ;
}

Weapon::~Weapon(void) {
	std::cout << "Weapon : destructor called" << std::endl;
	return ;
}
