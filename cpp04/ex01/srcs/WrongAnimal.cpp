/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:33:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 15:40:13 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal : default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy) {
	std::cout << "WrongAnimal : copy constructor called" << std::endl;
	*this = cpy;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal : destructor called" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (m_type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "ANNIMAAAAAALLLLLLL" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& cpy) {
	std::cout << "WrongAnimal : assign operator called" << std::endl;
	if (this != &cpy)
	{
		m_type = cpy.m_type;
	}
	return (*this);
}
