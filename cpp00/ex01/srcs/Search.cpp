/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:49:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/23 02:15:55 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

void	search(PhoneBook &book) {
	int	id;

	book.displayList();

	std::cout << "Select a contact id: ";
	std::cin >> id;
	std::cout << std::endl;
	if (std::cin.eof())
		return ;
	if (std::cin.fail() || id >= book.getContactNb()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "this is not a valid id" << std::endl;
		return ;
	}
	else {
		char c;
		std::cin.get(c);
		if (c != '\n') {
			std::cout << "this is not a valid id" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return ;
		}
	}
	book.displayContact(id);
}
