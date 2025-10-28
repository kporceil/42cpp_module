/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:22:51 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/28 19:28:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_binPoint = 8;

Fixed::Fixed(void): _value(0) {
	std::cout << "Fixed : default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy) {
	std::cout << "Fixed : copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::~Fixed(void) {
	std::cout << "Fixed : destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "Fixed : getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "Fixed : setRawBits member function called" << std::endl;
	this->_value = raw;
}

Fixed&	Fixed::operator=(const Fixed& cpy) {
	std::cout << "Fixed : assign operator called" << std::endl;
	if (this != &cpy)
	{
		this->_value = cpy.getRawBits();
	}
	return (*this);
}
