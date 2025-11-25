/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:01:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/24 17:05:40 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) {
	std::cout << "Ice : default constructor called" << std::endl;
	m_type = "ice";
}


Ice::Ice(const Ice& cpy): AMateria(cpy) {
	std::cout << "Ice : copy constructor called" << std::endl;
}

Ice::~Ice(void) {
	std::cout << "Ice : destructor called" << std::endl;
}

AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice&	Ice::operator=(const Ice& cpy) {
	std::cout << "Ice : assign operator called" << std::endl;
	if (this != &cpy)
	{
		AMateria::operator=(cpy);
	}
	return (*this);
}
