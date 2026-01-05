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
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int	main(void)
{
	Intern	someRandomIntern;
	AForm*	form;

	std::cout << "=== Test 1: Creation robotomy request ===" << std::endl;
	try {
		Bureaucrat	bob("Bob", 1);
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form) {
			std::cout << *form << std::endl;
			bob.signForm(*form);
			form->execute(bob);
			delete form;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Creation shrubbery creation ===" << std::endl;
	try {
		Bureaucrat	alice("Alice", 1);
		form = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form) {
			std::cout << *form << std::endl;
			alice.signForm(*form);
			form->execute(alice);
			delete form;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Creation presidential pardon ===" << std::endl;
	try {
		Bureaucrat	charlie("Charlie", 1);
		form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		if (form) {
			std::cout << *form << std::endl;
			charlie.signForm(*form);
			form->execute(charlie);
			delete form;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Formulaire inexistant ===" << std::endl;
	form = someRandomIntern.makeForm("tax evasion", "Donald");
	if (!form)
		std::cout << "Form was not created (NULL returned)" << std::endl;

	std::cout << "\n=== Test 5: Intern avec bureaucrate insuffisant ===" << std::endl;
	try {
		Bureaucrat	bob("Bob", 150);
		form = someRandomIntern.makeForm("presidential pardon", "Zaphod");
		if (form) {
			std::cout << *form << std::endl;
			bob.signForm(*form);
			delete form;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
