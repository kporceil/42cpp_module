/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:45:34 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 21:27:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>

class AForm {
	private:
		std::string const	m_name;
		bool				m_signState;
		int const			m_signGrade;
		int const			m_execGrade;
	public:
		AForm();
		AForm(std::string const& name, int const signGrade, int const execGrade);
		AForm(const AForm& cpy);

		class GradeTooHighException : public std::exception {
			public:
				char const	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				char const	*what() const throw();
		};

		std::string const&	getName() const;
		int	getSignGrade() const;
		int	getExecGrade() const;
		int	getSignState() const;

		void			beSigned(Bureaucrat const& bc);
		virtual void	execute(Bureaucrat const& executor) const = 0;
		void			checkExecRequirement(Bureaucrat const& executor) const {
			if (getSignState() == false)
				throw (std::runtime_error("Cannot execute unsigned contract"));
			if (getExecGrade() < executor.getGrade())
				throw (AForm::GradeTooLowException());
		}

		virtual ~AForm();

		AForm& operator=(const AForm& cpy);
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
