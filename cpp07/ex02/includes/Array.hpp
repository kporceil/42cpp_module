/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:16:30 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/07 18:47:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
	private:
		T		*m_arr;
		size_t	m_size;
	public:
		Array(): m_arr(new T[0]()), m_size(0) {}

		Array(unsigned int n): m_arr(new T[n]()), m_size(n) {}

		Array(Array const& cpy): m_arr(new T[cpy.m_size]), m_size(cpy.m_size) {
			for (size_t i = 0; i < cpy.m_size; ++i) {
				m_arr[i] = cpy.m_arr[i];
			}
		}

		Array& operator=(Array const& cpy) {
			if (this != &cpy)
			{
				delete[] m_arr;
				m_size = cpy.m_size;
				m_arr = new T[cpy.m_size];
				for (size_t i = 0; i < cpy.m_size; ++i) {
					m_arr[i] = cpy.m_arr[i];
				}
			}
			return (*this);
		}

		T&	operator[](int const i) {
			if (i < 0 || static_cast<size_t>(i) >= m_size)
				throw (std::out_of_range("Index out of range"));
			return (m_arr[i]);
		}

		T const&	operator[](int const i) const {
			if (i < 0 || static_cast<size_t>(i) >= m_size)
				throw (std::out_of_range("Index out of range"));
			return (m_arr[i]);
		}

		size_t	size() const {
			return (m_size);
		}

		~Array() {
			delete[] m_arr;
		}
};

#endif
