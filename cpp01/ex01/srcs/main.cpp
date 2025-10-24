/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 06:19:03 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 06:31:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, const std::string name);

int	main(void) {
	Zombie *zomb = zombieHorde(10, "foo");

	for (int i = 0; i < 10; ++i) {
		zomb[i].announce();
	}
	delete[] zomb;
	return (0);
}
