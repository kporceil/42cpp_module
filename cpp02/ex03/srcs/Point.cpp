/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:30:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/30 21:35:10 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void): m_x(0), m_y(0) {
}

Point::Point(float const x, float const y): m_x(x), m_y(y) {
}

Point::Point(const Point& cpy): m_x(cpy.m_x), m_y(cpy.m_y) {
}

Point::~Point(void) {
}

Fixed const&	Point::getX(void) const {
	return (this->m_x);
}

Fixed const&	Point::getY(void) const {
	return (this->m_y);
}

Point&	Point::operator=(const Point& cpy) {
	(void)cpy;
	return (*this);
}
