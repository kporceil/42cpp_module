/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:32:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 15:33:03 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
	private:
	protected:
		std::string	m_type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& cpy);
		virtual ~WrongAnimal(void);

		std::string	getType(void) const;
		void	makeSound(void) const;

		WrongAnimal& operator=(const WrongAnimal& cpy);
};
#endif
