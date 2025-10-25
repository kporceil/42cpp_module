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

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: Harl [Start Level]" << std::endl;
		return (1);
	}

	Harl	harl;

	switch (argv[1][0]) {
		case ('D'):
			std::cout << "[DEBUG]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
		case ('I'):
			std::cout << "[INFO]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
		case ('W'):
			std::cout << "[WARNING]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
		case ('E'):
			std::cout << "[ERROR]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break ;
		default:
			harl.complain("rien");
	}
}
