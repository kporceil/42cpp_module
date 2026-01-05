/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:47:14 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 21:22:17 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm: public AForm {
	private:
		std::string const	m_target;

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& cpy);
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
		~ShrubberyCreationForm();
		
		void	execute(Bureaucrat const& executor) const;
};

#endif
