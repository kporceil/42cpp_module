/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:14:25 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/08 17:45:56 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <stdint.h>
#include <stdexcept>

Span::Span(): m_size(0) {}

Span::Span(std::size_t const N): m_size(N) {}

Span::Span(Span const& cpy): m_nbs(cpy.m_nbs), m_size(cpy.m_size) {}

void	Span::addNumber(int const nb) {
	if (m_nbs.size() == m_size)
		throw (std::out_of_range("Span is full"));
	m_nbs.push_back(nb);
}

static void	printNumber(int n) {
	std::cout << n << " ";
}

int	Span::shortestSpan() {
	if (m_nbs.size() < 2)
		throw (std::runtime_error("No number to compare"));
	std::vector<int> adjacentVec = m_nbs;
	std::sort(adjacentVec.begin(), adjacentVec.end());
	std::adjacent_difference(adjacentVec.begin(), adjacentVec.end(), adjacentVec.begin());
	adjacentVec.erase(adjacentVec.begin());
	return (*std::min_element(adjacentVec.begin(), adjacentVec.end()));
}

int	Span::longestSpan() {
	if (m_nbs.size() < 2)
		throw (std::runtime_error("No number to compare"));
	return (*std::max_element(m_nbs.begin(), m_nbs.end()) - *std::min_element(m_nbs.begin(), m_nbs.end()));
}

void	Span::displayNumber() {
	std::for_each(m_nbs.begin(), m_nbs.end(), printNumber);
}

void	Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (m_nbs.size() + static_cast<size_t>(std::labs(std::distance(begin, end))) > m_size)
		throw (std::length_error("Span is full"));
	m_nbs.insert(m_nbs.end(), begin, end);
}

Span::~Span() {}

Span&	Span::operator=(Span const& cpy) {
	if (this != &cpy) {
		m_nbs = cpy.m_nbs;
		m_size = cpy.m_size;
	}
	return (*this);
}
