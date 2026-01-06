/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:33:31 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/06 14:34:25 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
		return (1);
	ScalarConverter::convert(argv[1]);
	return (0);
}
