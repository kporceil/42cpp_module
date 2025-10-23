/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:29:44 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/23 02:08:04 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>
#include <iostream>
#include <string>

void	search(PhoneBook &book);

int	main(void) {
	PhoneBook	book;
	std::string	input;

	while (1) {
		std::cout << "Hi, what do you want to do ? SEARCH, ADD, or EXIT ?" << std::endl;
		std::cout << ">> ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (input == "SEARCH")
			search(book);
		else if (input == "ADD")
			book.addContact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Wrong operation" << std::endl;
	}

	return (0);
}
