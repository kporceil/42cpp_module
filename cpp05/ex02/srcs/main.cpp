/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:07:54 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 22:03:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "=== Test 1: ShrubberyCreationForm - Succes ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 130);
		ShrubberyCreationForm form("home");
		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << std::endl;
		form.execute(bob);
		std::cout << "File 'home_shrubbery' created successfully" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: RobotomyRequestForm - Succes ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm form("Bender");
		std::cout << alice << std::endl;
		std::cout << form << std::endl;
		alice.signForm(form);
		std::cout << std::endl;
		form.execute(alice);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: PresidentialPardonForm - Succes ===" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm form("Arthur Dent");
		std::cout << president << std::endl;
		std::cout << form << std::endl;
		president.signForm(form);
		std::cout << std::endl;
		form.execute(president);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Execution sans signature ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 1);
		PresidentialPardonForm form("Ford Prefect");
		std::cout << "Tentative d'execution sans signature:" << std::endl;
		form.execute(charlie);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Signature avec grade insuffisant ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm form("Zaphod");
		std::cout << intern << std::endl;
		std::cout << form << std::endl;
		intern.signForm(form);
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Execution avec grade insuffisant ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat worker("Worker", 100);
		RobotomyRequestForm form("Marvin");
		std::cout << "Signature par le boss:" << std::endl;
		boss.signForm(form);
		std::cout << std::endl;
		std::cout << "Tentative d'execution par le worker:" << std::endl;
		form.execute(worker);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Multiple robotomies (test aleatoire) ===" << std::endl;
	try {
		Bureaucrat engineer("Engineer", 1);
		RobotomyRequestForm form1("Target1");
		RobotomyRequestForm form2("Target2");
		RobotomyRequestForm form3("Target3");

		engineer.signForm(form1);
		std::cout << std::endl;
		form1.execute(engineer);
		std::cout << std::endl;

		engineer.signForm(form2);
		std::cout << std::endl;
		form2.execute(engineer);
		std::cout << std::endl;

		engineer.signForm(form3);
		std::cout << std::endl;
		form3.execute(engineer);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
