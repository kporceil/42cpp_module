/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:27:30 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 19:43:01 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	private:
		std::string			_name;
		const Weapon		*_weapon;
	public:
		HumanB(const std::string &name);

		void	setWeapon(const Weapon &weapon);
		void	attack(void);

		~HumanB(void);
};

#endif
