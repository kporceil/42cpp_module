/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:11:15 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 22:15:01 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	private:
		Intern(const Intern& cpy) {(void)cpy;}
		Intern& operator=(const Intern& cpy) {(void)cpy; return(*this);}
	public:
		Intern() {}
		~Intern() {}

		AForm*	makeForm(std::string const& form, std::string const& target) const;
};

#endif
