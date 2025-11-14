/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:30:53 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 15:31:35 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) {
	std::cout << "Dog : default constructor called" << std::endl;
	m_type = "Dog";
}

Dog::Dog(const Dog& cpy) {
	std::cout << "Dog : copy constructor called" << std::endl;
	*this = cpy;
}

Dog::~Dog(void) {
	std::cout << "Dog : destructor called" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "WAF WAF" << std::endl;
}
