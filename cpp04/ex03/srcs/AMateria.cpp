/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:47:00 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/24 16:53:31 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) {
	std::cout << "AMateria : default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type): m_type(type) {
	std::cout << "AMateria : constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& cpy): m_type(cpy.m_type) {
	std::cout << "AMateria : copy constructor called" << std::endl;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria : destructor called" << std::endl;
}

std::string const&	AMateria::getType(void) const {
	return (m_type);
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}

AMateria&	AMateria::operator=(const AMateria& cpy) {
	std::cout << "AMateria : assign operator called" << std::endl;
	if (this != &cpy)
	{
		m_type = cpy.m_type;
	}
	return (*this);
}
