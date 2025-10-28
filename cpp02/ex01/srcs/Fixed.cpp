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
#include <cmath>
#include <iostream>

const int	Fixed::_binPoint = 8;

Fixed::Fixed(void): _value(0) {
	std::cout << "Fixed : default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy) {
	std::cout << "Fixed : copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed(float const nb) {
	std::cout << "Fixed : float constructor called" << std::endl;
	this->_value = roundf(nb * (1 << Fixed::_binPoint));
}

Fixed::Fixed(int const nb) {
	std::cout << "Fixed : int constructor called" << std::endl;
	this->_value = nb << Fixed::_binPoint;
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

float	Fixed::toFloat(void) const {
	return (static_cast<float>(this->_value) / static_cast<float>((1 << Fixed::_binPoint)));
}

int	Fixed::toInt(void) const {
	return (this->_value >> Fixed::_binPoint);
}

Fixed&	Fixed::operator=(const Fixed& cpy) {
	std::cout << "Fixed : assign operator called" << std::endl;
	if (this != &cpy)
	{
		this->_value = cpy.getRawBits();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& nb) {
	os << nb.toFloat();
	return (os);
}
