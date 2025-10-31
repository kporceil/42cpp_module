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
}

Fixed::Fixed(const Fixed& cpy) {
	*this = cpy;
}

Fixed::Fixed(float const nb): _value(roundf(nb * (1 << Fixed::_binPoint))) {
}

Fixed::Fixed(int const nb): _value(nb << Fixed::_binPoint) {
}

Fixed::~Fixed(void) {
}

int	Fixed::getRawBits(void) const {
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(this->_value) / static_cast<float>((1 << Fixed::_binPoint)));
}

int	Fixed::toInt(void) const {
	return (this->_value >> Fixed::_binPoint);
}

Fixed&	Fixed::min(Fixed& f1, Fixed &f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed const&	Fixed::min(Fixed const& f1, Fixed const& f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed&	Fixed::max(Fixed& f1, Fixed &f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed const&	Fixed::max(Fixed const& f1, Fixed const& f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

bool			Fixed::operator<(const Fixed& cmp) const {
	return (this->_value < cmp.getRawBits());
}
bool			Fixed::operator>(const Fixed& cmp) const {
	return (this->_value > cmp.getRawBits());
}

bool			Fixed::operator<=(const Fixed& cmp) const {
	return (this->_value <= cmp.getRawBits());
}

bool			Fixed::operator>=(const Fixed& cmp) const {
	return (this->_value >= cmp.getRawBits());
}

bool			Fixed::operator==(const Fixed& cmp) const {
	return (this->_value == cmp.getRawBits());
}

bool			Fixed::operator!=(const Fixed& cmp) const {
	return (this->_value != cmp.getRawBits());
}

Fixed			Fixed::operator+(const Fixed& add) const {
	Fixed	result;

	result.setRawBits(this->_value + add.getRawBits());
	return (result);
}

Fixed			Fixed::operator-(const Fixed& substract) const {
	Fixed	result;

	result.setRawBits(this->_value - substract.getRawBits());
	return (result);
}

Fixed			Fixed::operator*(const Fixed& mult) const {
	Fixed	result;

	result.setRawBits((this->_value * mult.getRawBits()) / (1 << this->_binPoint));
	return (result);
}

Fixed			Fixed::operator/(const Fixed& div) const {
	Fixed	result;

	result.setRawBits((this->_value * (1 << this->_binPoint)) / div.getRawBits());
	return (result);
}

Fixed			Fixed::operator++(int) {
	Fixed	tmp(*this);

	++this->_value;
	return (tmp);
}

Fixed			Fixed::operator--(int) {
	Fixed	tmp(*this);

	--this->_value;
	return (tmp);
}
Fixed&			Fixed::operator++(void) {
	++this->_value;
	return (*this);
}

Fixed&			Fixed::operator--(void) {
	--this->_value;
	return (*this);
}

Fixed&	Fixed::operator=(const Fixed& cpy) {
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
