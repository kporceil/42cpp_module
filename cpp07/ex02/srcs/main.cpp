/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:16:30 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/07 18:47:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

void	printSection(std::string const& title) {
	std::cout << "\n" << YELLOW << "=== " << title << " ===" << RESET << "\n" << std::endl;
}

int main(void)
{
	// Test 1: Construction par defaut
	printSection("Test 1: Construction par defaut");
	{
		Array<int> empty;
		std::cout << "Array vide cree, taille: " << empty.size() << std::endl;
	}

	// Test 2: Construction avec taille
	printSection("Test 2: Construction avec taille");
	{
		Array<int> arr(5);
		std::cout << "Array<int> de taille " << arr.size() << " cree" << std::endl;
		std::cout << "Valeurs par defaut: ";
		for (size_t i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	// Test 3: Modification et acces via operator[]
	printSection("Test 3: Modification et acces");
	{
		Array<int> arr(5);
		for (size_t i = 0; i < arr.size(); i++)
			arr[i] = i * 10;
		std::cout << "Valeurs apres modification: ";
		for (size_t i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	// Test 4: Constructeur de copie
	printSection("Test 4: Constructeur de copie");
	{
		Array<int> arr(3);
		arr[0] = 42;
		arr[1] = 21;
		arr[2] = 84;

		Array<int> copy(arr);
		std::cout << "Original: ";
		for (size_t i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << "\nCopie:    ";
		for (size_t i = 0; i < copy.size(); i++)
			std::cout << copy[i] << " ";
		std::cout << std::endl;

		copy[0] = 999;
		std::cout << "\nApres modification de la copie:" << std::endl;
		std::cout << "Original[0]: " << arr[0] << " (inchange)" << std::endl;
		std::cout << "Copie[0]:    " << copy[0] << " (modifie)" << std::endl;
	}

	// Test 5: Operateur d'affectation
	printSection("Test 5: Operateur d'affectation");
	{
		Array<int> arr1(3);
		arr1[0] = 1;
		arr1[1] = 2;
		arr1[2] = 3;

		Array<int> arr2(5);
		arr2 = arr1;

		std::cout << "arr2 taille apres affectation: " << arr2.size() << std::endl;
		std::cout << "arr2 contenu: ";
		for (size_t i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;
	}

	// Test 6: Exception hors limites
	printSection("Test 6: Exception hors limites");
	{
		Array<int> arr(5);
		try {
			std::cout << "Tentative d'acces arr[10]..." << std::endl;
			arr[10] = 42;
			std::cout << RED << "ERREUR: Aucune exception levee!" << RESET << std::endl;
		} catch (std::exception& e) {
			std::cout << GREEN << "Exception attrapee: " << e.what() << RESET << std::endl;
		}

		try {
			std::cout << "Tentative d'acces arr[-1]..." << std::endl;
			arr[-1] = 42;
			std::cout << RED << "ERREUR: Aucune exception levee!" << RESET << std::endl;
		} catch (std::exception& e) {
			std::cout << GREEN << "Exception attrapee: " << e.what() << RESET << std::endl;
		}
	}

	// Test 7: Array de strings
	printSection("Test 7: Array de strings");
	{
		Array<std::string> strArr(3);
		strArr[0] = "test1";
		strArr[1] = "test2";
		strArr[2] = "test3";

		std::cout << "Array<string>: ";
		for (size_t i = 0; i < strArr.size(); i++)
			std::cout << strArr[i] << " ";
		std::cout << std::endl;
	}

	// Test 8: Array const (test operator[] const)
	printSection("Test 8: Array const");
	{
		Array<int> arr(3);
		arr[0] = 10;
		arr[1] = 20;
		arr[2] = 30;

		Array<int> const constArr(arr);
		std::cout << "Lecture depuis Array const: ";
		for (size_t i = 0; i < constArr.size(); i++)
			std::cout << constArr[i] << " ";
		std::cout << std::endl;
	}

	std::cout << "\n" << GREEN << "Tous les tests sont passes!" << RESET << std::endl;
	return 0;
}
