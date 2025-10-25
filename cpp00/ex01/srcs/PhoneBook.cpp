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
#include <cstdio>
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook(void): _nbContacts(0), _nextChange(0){
	return ;
}

void	PhoneBook::addContact(void) {
	std::string	input;
	int			id;

	id = this->_nextChange;

first_name:
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << std::endl;
		return ;
	}
	if (input.size() == 0) {
		std::cout << "A contact field can't be empty" << std::endl;
		goto first_name;
	}
	this->_contacts[id].setFirstName(input);

last_name:
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << std::endl;
		return ;
	}
	if (input.size() == 0) {
		std::cout << "A contact field can't be empty" << std::endl;
		goto last_name;
	}
	this->_contacts[id].setLastName(input);

nickname:
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << std::endl;
		return ;
	}
	if (input.size() == 0) {
		std::cout << "A contact field can't be empty" << std::endl;
		goto nickname;
	}
	this->_contacts[id].setNickName(input);

phone_number:
	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << std::endl;
		return ;
	}
	if (input.size() == 0) {
		std::cout << "A contact field can't be empty" << std::endl;
		goto phone_number;
	}
	this->_contacts[id].setPhoneNumber(input);

darkest_secret:
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << std::endl;
		return ;
	}
	if (input.size() == 0) {
		std::cout << "A contact field can't be empty" << std::endl;
		goto darkest_secret;
	}
	this->_contacts[id].setDarkestSecret(input);

	std::cout << std::endl;

	if (this->_nbContacts < 8)
		++this->_nbContacts;
	++this->_nextChange;
	if (this->_nextChange == 8)
		this->_nextChange = 0;
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
	for (; i < 8; ++i) {
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
