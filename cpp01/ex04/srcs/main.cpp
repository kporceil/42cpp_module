/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:20:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 23:25:07 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>

int	main(int argc, char **argv) {
	if (argc != 4 || !argv[2][0]) {
		std::cerr << "Bad usage: use: sed [FILE] [SEARCH] [REPLACE]" << std::endl;
		return (1);
	}

	// load the file in a string
	std::ifstream	file(argv[1]);

	if (!file.is_open()) {
		std::cerr << "Error when opening file" << std::endl;
		return (1);
	}
	
	std::stringstream	buffer;

	buffer << file.rdbuf();

	std::string	string;

	string = buffer.str();
	
	// search and replace
	size_t	pos = 0;
	size_t	next_pos = 0;
	std::string	search(argv[2]);
	
	// open output file
	std::string		outname(argv[1]);
	outname += ".replace";
	std::ofstream	out(outname.c_str(), std::ofstream::out | std::ofstream::trunc);
	
	if (!out.is_open()) {
		std::cerr << "Canno't open output file" << std::endl;
		return (1);
	}

	while (pos != std::string::npos) {
		pos = string.find(search, next_pos);
		out << string.substr(next_pos, pos - next_pos);
		if (pos != std::string::npos)
			out << argv[3];
		next_pos = pos + search.size();
	}
}
