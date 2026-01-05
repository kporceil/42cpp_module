/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:07:54 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 18:10:45 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "=== Test 1: Creation de formulaire valide ===" << std::endl;
	try {
		Form form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Form avec grade de signature trop haut (0) ===" << std::endl;
	try {
		Form form2("Invalid Form", 0, 50);
		std::cout << form2 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Form avec grade d'execution trop bas (151) ===" << std::endl;
	try {
		Form form3("Invalid Form", 50, 151);
		std::cout << form3 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Bureaucrat signe un formulaire avec succes ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 30);
		Form form4("Contract", 50, 25);
		std::cout << "Avant signature: " << form4 << std::endl;
		bob.signForm(form4);
		std::cout << std::endl;
		std::cout << "Apres signature: " << form4 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Bureaucrat grade insuffisant pour signer ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 100);
		Form form5("Top Secret", 50, 25);
		std::cout << charlie << std::endl;
		std::cout << form5 << std::endl;
		charlie.signForm(form5);
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Tentative de double signature ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 1);
		Form form6("Important Doc", 10, 5);
		std::cout << "Premiere signature:" << std::endl;
		alice.signForm(form6);
		std::cout << std::endl;
		std::cout << "Deuxieme tentative:" << std::endl;
		alice.signForm(form6);
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Forms avec grades limites valides ===" << std::endl;
	try {
		Form form7a("Min Grade Form", 1, 1);
		Form form7b("Max Grade Form", 150, 150);
		std::cout << form7a << std::endl;
		std::cout << form7b << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
