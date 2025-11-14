/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:16:13 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 15:22:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	private:
	protected:
		std::string	m_type;
	public:
		Animal(void);
		Animal(const Animal& cpy);
		virtual ~Animal(void);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;

		Animal& operator=(const Animal& cpy);
};

#endif
