/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:05:56 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/24 17:01:37 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice(void);
		Ice(Ice const& cpy);
		~Ice(void);

		AMateria* clone() const;
		void use(ICharacter& target);

		Ice&	operator=(const Ice& cpy);
};

#endif
