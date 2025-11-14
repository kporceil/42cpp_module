/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:27:01 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 15:31:10 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) {
	std::cout << "Cat : default constructor called" << std::endl;
	m_type = "Cat";
}

Cat::Cat(const Cat& cpy) {
	std::cout << "Cat : copy constructor called" << std::endl;
	*this = cpy;
}

Cat::~Cat(void) {
	std::cout << "Cat : destructor called" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "MIAOWWWWWWWWWW" << std::endl;
}
