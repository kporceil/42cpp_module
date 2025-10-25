/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:19:34 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/25 21:37:17 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void) const {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info(void) const {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning(void) const {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	return ;
}

void	Harl::error(void) const {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level) const {
	void		(Harl::*funcs[4])(void) const = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	size_t		i;

	for (i = 0; levels[i].compare(level) != 0 && i < 4; ++i);
	if (i < 4)
		(this->*funcs[i])();
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return ;
}
