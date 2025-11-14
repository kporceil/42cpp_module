/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:27:01 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 19:45:24 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) {
	std::cout << "Cat : default constructor called" << std::endl;
	m_type = "Cat";
	m_brain = new Brain();
}

Cat::Cat(const Cat& cpy) {
	std::cout << "Cat : copy constructor called" << std::endl;
	*this = cpy;
}

Cat::~Cat(void) {
	std::cout << "Cat : destructor called" << std::endl;
	delete m_brain;
}

void	Cat::makeSound(void) const {
	std::cout << "MIAOWWWWWWWWWW" << std::endl;
}

const std::string*	Cat::getBrainIdeas(void) const {
	return (m_brain->getIdeas());
}

std::string	Cat::getBrainIdea(size_t i) const {
	return (m_brain->getIdea(i));
}

void	Cat::setBrainIdea(size_t i, const std::string& idea) {
	m_brain->setIdea(i, idea);
}

const Brain*	Cat::getBrain(void) const {
	return (m_brain);
}

Cat&	Cat::operator=(const Cat& cpy) {
	if (this != &cpy)
	{
		m_type = cpy.m_type;
		m_brain = new Brain(*cpy.m_brain);
	}
	return (*this);
}
