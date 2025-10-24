/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 05:56:56 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 06:30:22 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}


Zombie::Zombie(const std::string &name): _name(name) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(const std::string &name) {
	this->_name = name;
	return ;
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

Zombie::~Zombie(void) {
	std::cout << this->_name << ": no longer BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
