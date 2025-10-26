/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:38:04 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/25 21:39:06 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

size_t	getLevel(char *complain) {
	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	size_t		i;

	for (i = 0; levels[i].compare(complain) != 0 && i < 4; ++i);
	return (i);
}

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: Harl [Start Level]" << std::endl;
		return (1);
	}

	Harl	harl;
	size_t	level = getLevel(argv[1]);

	switch (level) {
		case (0):
			std::cout << "[DEBUG]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
		case (1):
			std::cout << "[INFO]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
		case (2):
			std::cout << "[WARNING]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
		case (3):
			std::cout << "[ERROR]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break ;
		default:
			harl.complain("rien");
	}
}
