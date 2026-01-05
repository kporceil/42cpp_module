/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:00:54 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 22:02:33 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardon", 25, 5), m_target("Unitialized") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target): AForm("PresidentialPardon", 25, 5), m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy): AForm(cpy), m_target(cpy.m_target) {};

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& cpy) {
	if (this != &cpy)
	{
		AForm::operator=(cpy);
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	checkExecRequirement(executor);
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
