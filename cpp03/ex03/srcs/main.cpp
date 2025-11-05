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
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ClapTrap	ct1("jean");
	ClapTrap	ct2("yves");
	ScavTrap	st1("pierre");
	ScavTrap	st2("roger");
	FragTrap	ft1("claude");
	FragTrap	ft2("lucien");
	DiamondTrap	dt1("gerard");
	DiamondTrap	dt2("albert");

	ct1.attack("yves");
	ct2.takeDamage(0);
	ct2.beRepaired(0);
	st1.attack("roger");
	st2.attack("pierre");
	st1.guardGate();
	st2.guardGate();
	ft1.highFivesGuys();
	ft2.highFivesGuys();
	dt1.attack("albert");
	dt2.attack("gerard");
	dt1.whoAmI();
	dt2.whoAmI();
}
