/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:44:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/23 02:31:46 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

const std::string&	Contact::getFirstName(void) const {
	return (this->_FirstName);
}

const std::string&	Contact::getLastName(void) const {
	return (this->_LastName);
}

const std::string&	Contact::getNickName(void) const {
	return (this->_NickName);
}

const std::string&	Contact::getPhoneNumber(void) const {
	return (this->_PhoneNumber);
}

const std::string&	Contact::getDarkestSecret(void) const {
	return (this->_DarkestSecret);
}

void	Contact::setFirstName(std::string& FirstName) {
	this->_FirstName = FirstName;
}

void	Contact::setLastName(std::string& LastName) {
	this->_LastName = LastName;
}

void	Contact::setNickName(std::string& NickName) {
	this->_NickName = NickName;
}

void	Contact::setPhoneNumber(std::string& PhoneNumber) {
	this->_PhoneNumber = PhoneNumber;
}

void	Contact::setDarkestSecret(std::string& DarkestSecret) {
	this->_DarkestSecret = DarkestSecret;
}
