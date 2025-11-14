/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:35:36 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 15:35:59 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) {
	std::cout << "WrongCat : default constructor called" << std::endl;
	m_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& cpy) {
	std::cout << "WrongCat : copy constructor called" << std::endl;
	*this = cpy;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat : destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "MIAOWWWWWWWWWW" << std::endl;
}
