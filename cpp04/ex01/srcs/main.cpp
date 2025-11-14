/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:36:05 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 15:40:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void) {
	Animal*	animals[10];

	for (size_t i = 0; i < 5; ++i) {
		animals[i] = new Dog();
		if (animals[i]->getType().compare("Dog") == 0)
			std::cout << "Type test: test passed" << std::endl;
		else
			std::cout << "Type test: test failed" << std::endl;
	}
	for (size_t i = 5; i < 10; ++i) {
		animals[i] = new Cat();
		if (animals[i]->getType().compare("Cat") == 0)
			std::cout << "Type test: test passed" << std::endl;
		else
			std::cout << "Type test: test failed" << std::endl;
	}

	Dog*	firstDog = dynamic_cast<Dog*>(animals[0]);
	firstDog->setBrainIdea(10, "Idea 1");

	Dog*	copy = new Dog(*firstDog);
	copy->setBrainIdea(10, "Another Idea");

	if (firstDog->getBrainIdea(10).compare(copy->getBrainIdea(10)) != 0)
		std::cout << "Deep copy test: test passed" << std::endl;
	else
		std::cout << "Deep copy test: test failed" << std::endl;

	delete copy;

	for (size_t i = 0; i < 10; ++i) {
		delete animals[i];
	}
	return (0);
}
