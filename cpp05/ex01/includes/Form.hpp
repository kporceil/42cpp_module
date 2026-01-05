/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:45:34 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 17:48:53 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form {
	private:
		std::string const	m_name;
		bool				m_signState;
		int const			m_signGrade;
		int const			m_execGrade;
	public:
		Form();
		Form(std::string const& name, int const signGrade, int const execGrade);
		Form(const Form& cpy);

		class GradeTooHighException : public std::exception {
			public:
				char const	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
				char const	*what() const throw();
		};

		std::string const&	getName() const;
		int	getSignGrade() const;
		int	getExecGrade() const;
		int	getSignState() const;

		void	beSigned(Bureaucrat const& bc);

		~Form();

		Form& operator=(const Form& cpy);
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
