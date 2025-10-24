/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:27:17 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 19:38:37 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	private:
		std::string			_name;
		const Weapon		&_weapon;
	public:
		HumanA(const std::string &name, const Weapon &weapon);

		void	attack(void);

		~HumanA(void);
};

#endif
