/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:38:13 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 14:16:03 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "iostream"

Bureaucrat::Bureaucrat(): m_name("Unitialized"), m_grade(150) {};

Bureaucrat::Bureaucrat(unsigned char grade): m_name("Unitialized") {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	m_grade = grade;
};

Bureaucrat::Bureaucrat(const std::string& name): m_name(name), m_grade(150) {};

Bureaucrat::Bureaucrat(const std::string& name, unsigned char grade): m_name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	m_grade = grade;
};

std::string const&	Bureaucrat::getName() const {
	return (m_name);
}

unsigned char	Bureaucrat::getGrade() const {
	return (m_grade);
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& cpy) {
	if (this != &cpy)
	{
		m_grade = cpy.m_grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {};

char const*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat can't be instantiate with a grade higher than 1");
}

char const*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat can't be instantiate with a grade lower than 150");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bc) {
	os << bc.getName() << ", bureaucrat grade " << static_cast<int>(bc.getGrade()) << ".";
	return (os);
}
