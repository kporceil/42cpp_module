/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:03:36 by kporceil          #+#    #+#             */
/*   Updated: 2026/03/26 09:33:37 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int
main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc("data.csv");
		btc.processInput(argv[1]);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
