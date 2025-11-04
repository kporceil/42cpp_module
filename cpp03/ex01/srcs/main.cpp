/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:15:58 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/04 17:11:33 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	ct1("jean");
	ClapTrap	ct2("yves");
	ScavTrap	st1("pierre");
	ScavTrap	st2("roger");

	ct1.attack("yves");
	ct2.takeDamage(0);
	ct2.beRepaired(0);
	st1.attack("roger");
	st2.attack("pierre");
	st1.guardGate();
	st2.guardGate();
}
