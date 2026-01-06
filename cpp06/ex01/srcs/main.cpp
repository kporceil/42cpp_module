/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:47:38 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/06 20:51:07 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include <iostream>

int	main(void) {
	Data	test = {45};
	uintptr_t	convert = Serialize::serialize(&test);
	Data	*unconvert = Serialize::deserialize(convert);

	std::cout << "Data Pointer: " << &test << " int value: " << test.value << std::endl;
	std::cout << "Serialized value: " << std::showbase << std::hex << convert << std::dec << std::endl;
	std::cout << "Unserialized value: " << unconvert << " int value: " << unconvert->value << std::endl;
	return (0);
}
