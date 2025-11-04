/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:15:58 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/04 16:17:28 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	ct1("jean");
	ClapTrap	ct2("yves");

	ct1.attack("yves");
	ct2.takeDamage(0);
	ct2.beRepaired(0);
}
