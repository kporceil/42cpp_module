/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:11:51 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/06 14:41:27 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy) {(void)cpy;}

ScalarConverter::~ScalarConverter() {};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cpy) { (void)cpy; return (*this); }

void	ScalarConverter::convert(std::string const& litteral) {
	try {
		double	dnb = std::strtod(litteral.c_str(), NULL);
		if (!std::isnan(dnb) && !std::isinf(dnb) && static_cast<double>(std::numeric_limits<char>::min()) < dnb && static_cast<double>(std::numeric_limits<char>::max()) > dnb) {
			std::cout << "char: ";
			if (std::isprint(static_cast<char>(dnb)))
				std::cout << static_cast<char>(dnb);
			else
				std::cout << "Non displayable";
			std::cout << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl;
		}
		if (!std::isnan(dnb) && !std::isinf(dnb) && static_cast<double>(std::numeric_limits<int>::min()) < dnb && static_cast<double>(std::numeric_limits<int>::max()) > dnb) {
			std::cout << "int: " << static_cast<int>(dnb) << std::endl;
		} else {
			std::cout << "int: impossible" << std::endl;
		}
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(dnb) << 'f' << std::endl;
		std::cout << "double: " << dnb << std::endl;
	} catch (std::exception& e) {
		std::cout << "cannot perform conversion because: " << e.what() << std::endl;
		return ;
	}

}
