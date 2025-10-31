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
#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void) {
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(0, 10);
	Point	edge(0, 10);
	Point	in(1, 1);
	Point	out(0, 20);

	std::cout << "a: (0, 0); b: (10, 0); c: (0, 10); Point: (0, 10); Result: " << bsp(a, b, c, edge) << std::endl;
	std::cout << "a: (0, 0); b: (10, 0); c: (0, 10); Point: (1, 1); Result: " << bsp(a, b, c, in) << std::endl;
	std::cout << "a: (0, 0); b: (10, 0); c: (0, 10); Point: (0, 20); Result: " << bsp(a, b, c, out) << std::endl;
	return (0);
}

