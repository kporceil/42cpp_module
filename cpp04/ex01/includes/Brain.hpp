/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:37:07 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/14 18:58:10 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
	private:
		std::string	m_ideas[100];
	public:
		Brain(void);
		Brain(const Brain& cpy);
		~Brain(void);

		std::string	getIdea(size_t i) const;
		const std::string	*getIdeas(void) const;
		
		void	setIdea(size_t i, const std::string& idea);

		Brain& operator=(const Brain& cpy);
};

#endif
