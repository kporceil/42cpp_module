/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:14:22 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 18:51:41 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <stdexcept>
#include <iostream>

AForm::AForm(): m_name("Unitialized"), m_signState(false), m_signGrade(150), m_execGrade(150) {};

AForm::AForm(std::string const& name, int const signGrade, int const execGrade): m_name(name), m_signState(false), m_signGrade(signGrade), m_execGrade(execGrade){
	if (signGrade > 150 || execGrade > 150)
		throw (GradeTooLowException());
	else if (signGrade < 1 || execGrade < 1)
		throw (GradeTooHighException());
}

AForm::AForm(const AForm& cpy): m_name(cpy.m_name), m_signState(cpy.m_signState), m_signGrade(cpy.m_signGrade), m_execGrade(cpy.m_execGrade) {};

char const*	AForm::GradeTooHighException::what() const throw() {
	return ("Form can't be instantiate with a limit grade higher than 1");
}

char const*	AForm::GradeTooLowException::what() const throw() {
	return ("Form can't be instantiate, signed or executed with a limit grade lower than 150 or the required grade");
}

std::string const&	AForm::getName() const {
	return (m_name);
}

int	AForm::getSignGrade() const {
	return (m_signGrade);
}

int	AForm::getExecGrade() const {
	return (m_execGrade);
}

int	AForm::getSignState() const {
	return (m_signState);
}

void	AForm::beSigned(Bureaucrat const& bc) {
	if (bc.getGrade() > m_signGrade)
		throw (GradeTooLowException());
	if (m_signState == true)
		throw (std::runtime_error("Form is already signed"));
	m_signState = true;
}

AForm::~AForm() {};

AForm&	AForm::operator=(const AForm& cpy)
{
	if (this != &cpy)
	{
		m_signState = cpy.m_signState;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const AForm& form) {
	os << form.getName() << ", form signed: " << form.getSignState() << ", required grade to sign:" << form.getSignGrade() << ", required grade to exec: " << form.getExecGrade();
	return (os);
}
