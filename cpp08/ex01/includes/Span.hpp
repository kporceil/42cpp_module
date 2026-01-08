/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:08:23 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/08 17:34:56 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {
	private:
		std::vector<int>	m_nbs;
		std::size_t			m_size;
	public:
		Span();
		Span(std::size_t const N);
		Span(Span const& cpy);

		void	addNumber(int const nb);
		int		shortestSpan();
		int		longestSpan();
		void	displayNumber();
		void	fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		~Span();
		
		Span&	operator=(Span const& cpy);
};

#endif
