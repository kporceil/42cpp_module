/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:21:27 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 15:26:40 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) {
	std::cout << "Animal : default constructor called" << std::endl;
}

Animal::Animal(const Animal& cpy) {
	std::cout << "Animal : copy constructor called" << std::endl;
	*this = cpy;
}

Animal::~Animal(void) {
	std::cout << "Animal : destructor called" << std::endl;
}

std::string	Animal::getType(void) const {
	return (m_type);
}

void	Animal::makeSound(void) const {
	std::cout << "ANNIMAAAAAALLLLLLL" << std::endl;
}

Animal&	Animal::operator=(const Animal& cpy) {
	std::cout << "Animal : assign operator called" << std::endl;
	if (this != &cpy)
	{
		m_type = cpy.m_type;
	}
	return (*this);
}
