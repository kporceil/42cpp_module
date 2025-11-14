/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:30:53 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 19:46:38 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) {
	std::cout << "Dog : default constructor called" << std::endl;
	m_type = "Dog";
	m_brain = new Brain();
}

Dog::Dog(const Dog& cpy) {
	std::cout << "Dog : copy constructor called" << std::endl;
	*this = cpy;
}

Dog::~Dog(void) {
	std::cout << "Dog : destructor called" << std::endl;
	delete m_brain;
}

void	Dog::makeSound(void) const {
	std::cout << "WAF WAF" << std::endl;
}

const std::string*	Dog::getBrainIdeas(void) const {
	return (m_brain->getIdeas());
}

std::string	Dog::getBrainIdea(size_t i) const {
	return (m_brain->getIdea(i));
}

void	Dog::setBrainIdea(size_t i, const std::string& idea) {
	m_brain->setIdea(i, idea);
}

const Brain*	Dog::getBrain(void) const {
	return (m_brain);
}

Dog&	Dog::operator=(const Dog& cpy) {
	if (this != &cpy)
	{
		m_type = cpy.m_type;
		m_brain = new Brain(*cpy.m_brain);
	}
	return (*this);
}
