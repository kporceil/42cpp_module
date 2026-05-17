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
#define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat {
private:
  std::string const m_name;
  unsigned char m_grade;

public:
  Bureaucrat();
  Bureaucrat(unsigned char grade);
  Bureaucrat(std::string const &name);
  Bureaucrat(std::string const &name, unsigned char grade);
  Bureaucrat(Bureaucrat const &cpy);

  class GradeTooHighException : public std::exception {
  public:
    char const *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    char const *what() const throw();
  };

  void incrementGrade();
  void decrementGrade();

  std::string const &getName() const;
  unsigned char getGrade() const;
  void signForm(AForm &form);

  Bureaucrat &operator=(Bureaucrat const &cpy);

  ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bc);

#endif
