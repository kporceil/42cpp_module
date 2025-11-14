/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:45:56 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 18:59:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain : default constructor called" << std::endl;
}

Brain::Brain(const Brain& cpy) {
	std::cout << "Brain : copy constructor called" << std::endl;
	*this = cpy;
}

Brain::~Brain(void) {
	std::cout << "Brain : destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& cpy) {
	std::cout << "Brain : assign operator called" << std::endl;
	if (this != &cpy)
	{
		for (size_t i = 0; i < 100; ++i) {
			m_ideas[i] = cpy.m_ideas[i];
		}
	}
	return (*this);
}

std::string	Brain::getIdea(size_t i) const
{
	if (i < 100)
		return (m_ideas[i]);
	std::cerr << "Brain can't have more than 100 idea" << std::endl;
	return ("");
}

const std::string*	Brain::getIdeas(void) const
{
	return (m_ideas);
}

void	Brain::setIdea(size_t i, const std::string& idea) {

	if (i < 100)
		m_ideas[i] = idea;
	else
		std::cerr << "Brain can't have more than 100 idea" << std::endl;
}
