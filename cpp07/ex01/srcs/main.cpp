/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:36:29 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/07 17:39:57 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void) {
	int const	arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int			arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter(arr1, 10, printOne);
	std::cout << std::endl;
	iter(arr2, 10, printOne);
	std::cout << std::endl;
	
	return (0);
}
