/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:22:42 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 19:43:21 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain*	m_brain;
	public:
		Cat(void);
		Cat(const Cat& cpy);
		~Cat(void);

		const std::string*	getBrainIdeas(void) const;
		std::string			getBrainIdea(size_t i) const;
		void				setBrainIdea(size_t i, const std::string& idea);
		const Brain*		getBrain(void) const;

		void	makeSound(void) const;

		Cat&	operator=(const Cat& cpy);
};

#endif
