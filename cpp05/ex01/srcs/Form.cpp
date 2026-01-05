/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:14:22 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 18:25:40 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <stdexcept>
#include <iostream>

Form::Form(): m_name("Unitialized"), m_signState(false), m_signGrade(150), m_execGrade(150) {};

Form::Form(std::string const& name, int const signGrade, int const execGrade): m_name(name), m_signState(false), m_signGrade(signGrade), m_execGrade(execGrade){
	if (signGrade > 150 || execGrade > 150)
		throw (GradeTooLowException());
	else if (signGrade < 1 || execGrade < 1)
		throw (GradeTooHighException());
}

Form::Form(const Form& cpy): m_name(cpy.m_name), m_signState(cpy.m_signState), m_signGrade(cpy.m_signGrade), m_execGrade(cpy.m_execGrade) {};

char const*	Form::GradeTooHighException::what() const throw() {
	return ("Form can't be instantiate with a limit grade higher than 1");
}

char const*	Form::GradeTooLowException::what() const throw() {
	return ("Form can't be instantiate, signed or executed with a limit grade lower than 150 or the required grade");
}

std::string const&	Form::getName() const {
	return (m_name);
}

int	Form::getSignGrade() const {
	return (m_signGrade);
}

int	Form::getExecGrade() const {
	return (m_execGrade);
}

int	Form::getSignState() const {
	return (m_signState);
}

void	Form::beSigned(Bureaucrat const& bc) {
	if (bc.getGrade() > m_signGrade)
		throw (GradeTooLowException());
	if (m_signState == true)
		throw (std::runtime_error("Form is already signed"));
	m_signState = true;
}

Form::~Form() {};

Form&	Form::operator=(const Form& cpy)
{
	if (this != &cpy)
	{
		m_signState = cpy.m_signState;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form& form) {
	os << form.getName() << ", form signed: " << form.getSignState() << ", required grade to sign:" << form.getSignGrade() << ", required grade to exec: " << form.getExecGrade();
	return (os);
}
