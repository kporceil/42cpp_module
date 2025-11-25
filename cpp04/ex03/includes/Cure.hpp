/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:05:56 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/24 17:06:36 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure(void);
		Cure(Cure const& cpy);
		~Cure(void);

		AMateria* clone() const;
		void use(ICharacter& target);

		Cure&	operator=(const Cure& cpy);
};

#endif
