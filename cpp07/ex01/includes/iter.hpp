/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:22:39 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/07 17:39:42 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void	printOne(T& toPrint) {
	std::cout << toPrint;
}

template <typename T>
void	iter(T* arr, size_t const size, void func(T&)) {
	for (size_t i = 0; i < size; ++i) {
		func(arr[i]);
	}
}

#endif
