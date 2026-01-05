/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:00:17 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 18:22:48 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Form;

class Bureaucrat {
	private:
		std::string const	m_name;
		unsigned char		m_grade;
	public:
		Bureaucrat();
		Bureaucrat(unsigned char grade);
		Bureaucrat(const std::string& name);
		Bureaucrat(const std::string& name, unsigned char grade);
		Bureaucrat(Bureaucrat const& cpy);

		class GradeTooHighException : public std::exception {
			public:
				char const	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				char const	*what() const throw();
		};

		std::string const&	getName() const;
		unsigned char		getGrade() const;
		void				signForm(Form& form);

		Bureaucrat&	operator=(Bureaucrat const& cpy);

		~Bureaucrat();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bc);

#endif
