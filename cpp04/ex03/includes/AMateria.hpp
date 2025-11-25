/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:21:29 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/24 17:56:14 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string	m_type;
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &cpy);

		virtual ~AMateria(void);

		std::string const& getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);

		AMateria& operator=(const AMateria& cpy);
};

#endif
