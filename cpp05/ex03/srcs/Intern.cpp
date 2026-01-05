/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:15:07 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 22:16:21 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static AForm*	createShrubberyForm(std::string const& target) {
	return (new ShrubberyCreationForm(target));
}

static AForm*	createRobotomyForm(std::string const& target) {
	return (new RobotomyRequestForm(target));
}

static AForm*	createPresidentialForm(std::string const& target) {
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string const& form, std::string const& target) const {
	std::string	formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formCreators[3])(std::string const&) = {
		&createShrubberyForm,
		&createRobotomyForm,
		&createPresidentialForm
	};

	for (int i = 0; i < 3; i++) {
		if (form == formNames[i]) {
			std::cout << "Intern creates " << form << std::endl;
			return (formCreators[i](target));
		}
	}

	std::cout << "Intern cannot create " << form << " form because it doesn't exist" << std::endl;
	return (NULL);
}
