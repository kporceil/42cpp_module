/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:10:39 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/06 14:11:44 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& cpy);
		~ScalarConverter(void);

		ScalarConverter& operator=(const ScalarConverter& cpy);
	public:
		static void	convert(std::string const& litteral);
};

#endif
