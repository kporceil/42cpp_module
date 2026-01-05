/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:44:41 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 21:59:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequest", 72, 45), m_target("Unitialized") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target): AForm("RobotomyRequest", 72, 45), m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy): AForm(cpy), m_target(cpy.m_target) {};

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& cpy) {
	if (this != &cpy)
	{
		AForm::operator=(cpy);
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	checkExecRequirement(executor);
	int	nb;

	srand(clock());
	nb = rand();
	std::cout << "bbrrrr brrr zzrrrr rrrrzzz\n";
	if (nb % 2)
		std::cout << m_target << " has been successfully robotomized" << std::endl;
	else
		std::cout << m_target << " robotomization failed" << std::endl;
}
