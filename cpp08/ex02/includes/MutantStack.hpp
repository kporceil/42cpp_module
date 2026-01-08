/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:32:05 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/08 18:44:46 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack(void): std::stack<T>() {}
		MutantStack(const MutantStack& cpy): std::stack<T>(cpy) {}
		~MutantStack(void) {}

		iterator	end() {
			return (std::stack<T>::c.end());
		}

		iterator	begin() {
			return (std::stack<T>::c.begin());
		}

		const_iterator	end() const {
			return (std::stack<T>::c.end());
		}

		const_iterator	begin() const {
			return (std::stack<T>::c.begin());
		}

		reverse_iterator	rend() {
			return (std::stack<T>::c.rend());
		}

		reverse_iterator	rbegin() {
			return (std::stack<T>::c.rbegin());
		}

		const_reverse_iterator	rend() const {
			return (std::stack<T>::c.rend());
		}

		const_reverse_iterator	rbegin() const {
			return (std::stack<T>::c.rbegin());
		}

		MutantStack& operator=(const MutantStack& cpy) {
			if (this != &cpy) {
				std::stack<T>::operator=(cpy);
			}
			return (*this);
		}
};

#endif
