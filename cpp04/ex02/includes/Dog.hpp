/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:29:40 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 19:45:56 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain*	m_brain;
	public:
		Dog(void);
		Dog(const Dog& cpy);
		~Dog(void);

		const std::string*	getBrainIdeas(void) const;
		std::string			getBrainIdea(size_t i) const;
		void				setBrainIdea(size_t i, const std::string& idea);
		const Brain*		getBrain(void) const;

		void	makeSound(void) const;

		Dog&	operator=(const Dog& cpy);
};

#endif
