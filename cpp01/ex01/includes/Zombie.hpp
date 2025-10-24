/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 05:53:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/24 06:29:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		std::string	_name;
	public:
		Zombie(void);
		Zombie(const std::string &name);
		void	setName(const std::string &name);
		void	announce(void);
		~Zombie(void);
};

#endif
