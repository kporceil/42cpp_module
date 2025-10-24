/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 06:22:54 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 06:27:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, const std::string name) {
	Zombie	*horde = new Zombie[n];

	for (int i = 0; i < n; ++i) {
		horde[i].setName(name);
	}
	return (horde);
}
