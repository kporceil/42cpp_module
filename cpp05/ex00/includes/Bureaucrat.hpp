/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:00:17 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/05 14:11:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat {
	private:
		std::string const	m_name;
		unsigned char		m_grade;
	public:
		Bureaucrat();
		Bureaucrat(unsigned char grade);
		Bureaucrat(const std::string& name);
		Bureaucrat(const std::string& name, unsigned char grade);

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

		Bureaucrat&	operator=(Bureaucrat const& cpy);

		~Bureaucrat();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& nb);

#endif
