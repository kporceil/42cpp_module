/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:06:52 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/24 17:07:30 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) {
	std::cout << "Cure : default constructor called" << std::endl;
	m_type = "cure";
}


Cure::Cure(const Cure& cpy): AMateria(cpy) {
	std::cout << "Cure : copy constructor called" << std::endl;
}

Cure::~Cure(void) {
	std::cout << "Cure : destructor called" << std::endl;
}

AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure&	Cure::operator=(const Cure& cpy) {
	std::cout << "Cure : assign operator called" << std::endl;
	if (this != &cpy)
	{
		AMateria::operator=(cpy);
	}
	return (*this);
}
