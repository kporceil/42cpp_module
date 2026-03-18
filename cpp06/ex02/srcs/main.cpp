/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:07:19 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/06 21:18:31 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

namespace std
{
	class bad_cast : public std::exception
	{};
} // namespace std

Base*
generate(void)
{
	int rd;

	srand(clock());
	rd = rand();
	switch (rd % 3)
	{
		case 0:
			std::cout << "Generate A class" << std::endl;
			return (new A);
		case 1:
			std::cout << "Generate B class" << std::endl;
			return (new B);
		case 2:
			std::cout << "Generate C class" << std::endl;
			return (new C);
	}
	std::cout << "Problem" << std::endl;
	return (NULL);
}

void
identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "invalid pointer" << std::endl;
	}
}

void
identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast& e)
	{
		try
		{
			(void) dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast& e)
		{
			try
			{
				(void) dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast& e)
			{
				std::cout << "invalid reference" << std::endl;
			}
		}
	}
}

int
main(void)
{
	Base* test = generate();

	std::cout << "Pointer identification: ";
	identify(test);
	std::cout << "Reference identification: ";
	identify(*test);
	delete test;
	return (0);
}
