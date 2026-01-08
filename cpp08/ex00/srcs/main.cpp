/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:54:39 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/08 15:01:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

void	print(int n)
{
	std::cout << n << " ";
}

int	main(void) {
	{
		std::cout << "====== LIST test ======" << std::endl;
		std::list<int> testList;
		testList.push_back(1);
		testList.push_back(4);
		testList.push_back(3);
		testList.push_back(4);
		std::cout << "list values: ";
		std::for_each(testList.begin(), testList.end(), print);
		std::cout << std::endl;
		std::cout << "occurence to search: 4" << std::endl << "test: ";
		std::cout << easyfind(testList, 4) << std::endl;
	}
	{
		std::cout << "====== VECTOR test ======" << std::endl;
		std::vector<int>	testVector;
		testVector.push_back(1);
		testVector.push_back(4);
		testVector.push_back(3);
		testVector.push_back(4);
		std::cout << "vector values: ";
		std::for_each(testVector.begin(), testVector.end(), print);
		std::cout << std::endl;
		std::cout << "occurence to search: 4" << std::endl << "test: ";
		std::cout << easyfind(testVector, 4) << std::endl;
	}
	{
		std::cout << "====== DEQUE test ======" << std::endl;
		std::deque<int>	testDeque;
		testDeque.push_back(1);
		testDeque.push_back(4);
		testDeque.push_back(3);
		testDeque.push_back(4);
		std::cout << "deque values: ";
		std::for_each(testDeque.begin(), testDeque.end(), print);
		std::cout << std::endl;
		std::cout << "occurence to search: 4" << std::endl << "test: ";
		std::cout << easyfind(testDeque, 4) << std::endl;
	}
	{
		std::cout << "====== LIST no occurence test ======" << std::endl;
		std::list<int> testList;
		testList.push_back(1);
		testList.push_back(2);
		testList.push_back(3);
		testList.push_back(2);
		std::cout << "list values: ";
		std::for_each(testList.begin(), testList.end(), print);
		std::cout << std::endl;
		std::cout << "occurence to search: 4" << std::endl << "test: ";
		try {
			std::cout << easyfind(testList, 4) << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception catch: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "====== VECTOR no occurence test ======" << std::endl;
		std::vector<int>	testVector;
		testVector.push_back(1);
		testVector.push_back(2);
		testVector.push_back(3);
		testVector.push_back(2);
		std::cout << "vector values: ";
		std::for_each(testVector.begin(), testVector.end(), print);
		std::cout << std::endl;
		std::cout << "occurence to search: 4" << std::endl << "test: ";
		try {
			std::cout << easyfind(testVector, 4) << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception catch: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "====== DEQUE no occurence test ======" << std::endl;
		std::deque<int>	testDeque;
		testDeque.push_back(1);
		testDeque.push_back(2);
		testDeque.push_back(3);
		testDeque.push_back(2);
		std::cout << "deque values: ";
		std::for_each(testDeque.begin(), testDeque.end(), print);
		std::cout << std::endl;
		std::cout << "occurence to search: 4" << std::endl << "test: ";
		try {
			std::cout << easyfind(testDeque, 4) << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception catch: " << e.what() << std::endl;
		}
	}
}
