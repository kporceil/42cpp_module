/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:52:31 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/23 02:34:34 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook(void): _nbContacts(0) {
	return ;
}

void	PhoneBook::addContact(void) {
	std::string	input;
	int			id;

	id = this->_nbContacts;
	if (id == 9)
		id = 0;

	std::cout << "First Name: ";
	std::getline(std::cin, input);
	this->_contacts[id].setFirstName(input);

	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	this->_contacts[id].setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	this->_contacts[id].setNickName(input);

	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	this->_contacts[id].setPhoneNumber(input);

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	this->_contacts[id].setDarkestSecret(input);

	std::cout << std::endl;

	if (this->_nbContacts < 9)
		++this->_nbContacts;
}

void	PhoneBook::displayContact(int id) {
	std::cout << "First Name: " << this->_contacts[id].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contacts[id].getLastName() << std::endl;
	std::cout << "Nick Name: " << this->_contacts[id].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->_contacts[id].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[id].getDarkestSecret() << std::endl;
}

void	PhoneBook::displayList(void) {
	std::string	lineBreaker('-', 45);
	int			i;

	std::cout << lineBreaker << std::endl;
	std::cout << "|" << std::setw(10) << "Id"
		<< "|" << std::setw(10) << "First Name"
		<< "|" << std::setw(10) << "Last Name"
		<< "|" << std::setw(10) << "Nickname"
		<< "|" << std::endl;
	std::cout << lineBreaker << std::endl;

	for (i = 0; i < this->_nbContacts; ++i) {
		std::cout << "|" << std::setw(10) << i
			<< '|' << std::setw(10) << (this->_contacts[i].getFirstName().size() > 10 ? this->_contacts[i].getFirstName().substr(0, 9) + '.' : this->_contacts[i].getFirstName())
			<< '|' << std::setw(10) << (this->_contacts[i].getLastName().size() > 10 ? this->_contacts[i].getLastName().substr(0, 9) + '.' : this->_contacts[i].getLastName())
			<< '|' << std::setw(10) << (this->_contacts[i].getNickName().size() > 10 ? this->_contacts[i].getNickName().substr(0, 9) + '.' : this->_contacts[i].getNickName())
			<< '|' << std::endl;
		std::cout << lineBreaker << std::endl;
	}
	for (; i < 9; ++i) {
		std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << " " << "|" << std::setw(10) << " " << "|" << std::setw(10) << " " << "|" << std::endl;
		std::cout << lineBreaker << std::endl;
	}
}

int	PhoneBook::getContactNb(void) {
	return (this->_nbContacts);
}

PhoneBook::~PhoneBook(void) {
	return ;
}
