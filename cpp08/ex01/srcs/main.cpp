/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:30:47 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/08 17:52:41 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>

int main()
{
	{
		std::cout << "===== SUBJECT TEST =====" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Number list: ";
		sp.displayNumber();
		std::cout << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "===== 100000 NUMBER TEST =====" << std::endl;
		std::vector<int>	vec;
		vec.reserve(100000);
		for (size_t i = 0; i < 100000; ++i)
			vec.push_back(i);
		Span sp(100000);
		sp.fillSpan(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "===== ADD NUMBER THROWING TEST =====" << std::endl;
		Span	sp;
		try {
			sp.addNumber(6);
			std::cout << "ERROR: No exception catched" << std::endl;
		} catch (std::exception& e) {
			std::cout << "SUCCESS: exception catched: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "===== FILL NUMBER THROWING TEST =====" << std::endl;
		std::vector<int>	vec;
		for (size_t i = 0; i < 10; ++i)
			vec.push_back(i);
		Span	sp;
		try {
			sp.fillSpan(vec.begin(), vec.end());
			std::cout << "ERROR: No exception catched" << std::endl;
		} catch (std::exception& e) {
			std::cout << "SUCCESS: exception catched: " << e.what() << std::endl;
		}
	}
	return 0;
}
