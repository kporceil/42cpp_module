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

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const& cpy)
{
	(void) cpy;
}

ScalarConverter::~ScalarConverter() {};

ScalarConverter&
ScalarConverter::operator=(ScalarConverter const& cpy)
{
	(void) cpy;
	return (*this);
}

static int
isInteger(double nb)
{
	return (nb == std::floor(nb));
}

void
ScalarConverter::convert(std::string const& litteral)
{
	if (litteral.empty())
	{
		std::cout << "cannot perform conversion" << std::endl;
		return;
	}
	try
	{
		char*  check;
		double dnb;
		if (litteral.size() == 1)
		{
			dnb = litteral[0];
			check = const_cast<char*>(&litteral[1]);
		}
		else
			dnb = std::strtod(litteral.c_str(), &check);
		if (*check != '\0' && (*check != 'f' || *(check + 1) != '\0'))
		{
			std::cout << "cannot perform conversion" << std::endl;
			return;
		}
		if (!std::isnan(dnb) && !std::isinf(dnb) &&
			static_cast<double>(std::numeric_limits<char>::min()) <= dnb &&
			static_cast<double>(std::numeric_limits<char>::max()) >= dnb)
		{
			std::cout << "char: ";
			if (std::isprint(static_cast<char>(dnb)))
				std::cout << static_cast<char>(dnb);
			else
				std::cout << "Non displayable";
			std::cout << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
		}
		if (!std::isnan(dnb) && !std::isinf(dnb) &&
			static_cast<double>(std::numeric_limits<int>::min()) <= dnb &&
			static_cast<double>(std::numeric_limits<int>::max()) >= dnb)
		{
			std::cout << "int: " << static_cast<int>(dnb) << std::endl;
		}
		else
		{
			std::cout << "int: impossible" << std::endl;
		}
		std::cout << "float: " << std::fixed
				  << std::setprecision(isInteger(dnb) && !std::isinf(dnb) ? 1
																		  : 3)
				  << static_cast<float>(dnb) << "f" << std::endl;
		std::cout << "double: " << std::fixed
				  << std::setprecision(isInteger(dnb) && !std::isinf(dnb) ? 1
																		  : 3)
				  << dnb << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "cannot perform conversion because: " << e.what()
				  << std::endl;
		return;
	}
}
