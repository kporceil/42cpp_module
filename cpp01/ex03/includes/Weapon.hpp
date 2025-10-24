/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:15:59 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 19:30:41 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	private:
		std::string	_type;
	public:
		Weapon(void);
		Weapon(const std::string& type);

		const std::string	&getType(void) const;

		void	setType(const std::string& type);

		~Weapon(void);
};

#endif
