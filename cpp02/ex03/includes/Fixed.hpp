/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:21:00 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/28 19:25:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_binPoint;
	public:
		Fixed(void);
		Fixed(int const nb);
		Fixed(float const nb);
		Fixed(const Fixed& cpy);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&	min(Fixed& f1, Fixed& f2);
		static Fixed&	max(Fixed& f1, Fixed& f2);
		static const Fixed&	min(Fixed const& f1, Fixed const& f2);
		static const Fixed&	max(Fixed const& f1, Fixed const& f2);

		bool			operator<(const Fixed& cmp) const;
		bool			operator>(const Fixed& cmp) const;
		bool			operator<=(const Fixed& cmp) const;
		bool			operator>=(const Fixed& cmp) const;
		bool			operator==(const Fixed& cmp) const;
		bool			operator!=(const Fixed& cmp) const;
		Fixed			operator+(const Fixed& add) const;
		Fixed			operator-(const Fixed& substract) const;
		Fixed			operator*(const Fixed& mult) const;
		Fixed			operator/(const Fixed& div) const;
		Fixed			operator++(int);
		Fixed			operator--(int);
		Fixed&			operator++(void);
		Fixed&			operator--(void);
		Fixed&			operator=(const Fixed& cpy);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& nb);

#endif
