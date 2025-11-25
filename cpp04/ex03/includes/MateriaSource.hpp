/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:12:27 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/25 17:14:25 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
		AMateria*	m_inventory[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& cpy);
		~MateriaSource(void);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);

		MateriaSource& operator=(const MateriaSource& cpy);

};

#endif
