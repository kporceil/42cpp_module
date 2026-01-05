/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:50:45 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 21:42:39 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137), m_target("Unitialized") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target): AForm("Shrubbery", 145, 137), m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy): AForm(*this), m_target(cpy.m_target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& cpy) {
	if (this != &cpy)
	{
		AForm::operator=(cpy);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	checkExecRequirement(executor);
	std::string filename = m_target + "_shrubbery";
	std::ofstream	file(filename.c_str());
	file << "                                                         .\n"
		<< "                                              .         ;\n"
		<< "                 .              .              ;%     ;; \n"
		<< "                   ,           ,                :;%  %;\n"
		<< "                    :         ;                   :;%;'     .,\n"
		<< "           ,.        %;     %;            ;        %;'    ,;\n"
		<< "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
		<< "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
		<< "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
		<< "                `%;.     ;%;     %;'         `;%%;.%;'\n"
		<< "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
		<< "                    `:%;.  :;bd%;          %;@%;'\n"
		<< "                      `@%:.  :;%.         ;@@%;'\n"
		<< "                        `@%.  `;@%.      ;@@%;\n"
		<< "                          `@%%. `@%%    ;@@%;\n"
		<< "                            ;@%. :@%%  %@@%;\n"
		<< "                              %@bd%%%bd%%:;\n"
		<< "                                #@%%%%%:;;\n"
		<< "                                %@@%%%::;\n"
		<< "                                %@@@%(o);  . ' \n"
		<< "                                %@@@o%;:(.,' \n"
		<< "                            `.. %@@@o%::; \n"
		<< "                               `)@@@o%::;\n"
		<< "                                %@@(o)::;\n"
		<< "                               .%@@@@%::;\n"
		<< "                               ;%@@@@%::;. \n"
		<< "                              ;%@@@@%%:;;;.\n"
		<< "                          ...;%@@@@@%%:;;;;,..\n" << std::endl;
}
