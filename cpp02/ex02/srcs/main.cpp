/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:26:31 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/28 19:27:21 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void) {
	Fixed	a(2.5f);
	Fixed	b(2);
	Fixed	c(-1);
	Fixed	d(1);

	std::cout << "a = " << a.toFloat() << std::endl;
	std::cout << "b = " << b.toFloat() << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "c = " << c.toFloat() << std::endl;
	std::cout << "d = " << d.toFloat() << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << std::endl;
	std::cout << "a = " << a.toFloat() << std::endl;
	std::cout << "b = " << b.toFloat() << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "a == b ? " << (a == b ? "true" : "false") << std::endl;
	std::cout << "a != b ? " << (a != b ? "true" : "false") << std::endl;
	std::cout << "a > b ? " << (a > b ? "true" : "false") << std::endl;
	std::cout << "a < b ? " << (a < b ? "true" : "false") << std::endl;
	std::cout << "a <= b ? " << (a <= b ? "true" : "false") << std::endl;
	std::cout << "a >= b ? " << (a >= b ? "true" : "false") << std::endl;
	return (0);
}

