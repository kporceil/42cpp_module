/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:17:26 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/25 21:26:11 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {
	private:
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;
	public:
		void	complain(std::string level) const;
};

#endif
