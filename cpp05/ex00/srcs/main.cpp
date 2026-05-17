/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:07:54 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 14:08:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int
main(void)
{
	std::cout << "=== Test 1: Bureaucrat valide ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade trop haut (0) ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade trop bas (151) ===" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Grade limite valide (1) ===" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Grade limite valide (150) ===" << std::endl;
	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Decrement grade too low (150) ===" << std::endl;
	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Increment grade too low (150) ===" << std::endl;
	try
	{
		Bureaucrat top("top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
