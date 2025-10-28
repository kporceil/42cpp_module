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

class Fixed {
	private:
		int					_value;
		static const int	_binPoint;
	public:
		Fixed(void);
		Fixed(const Fixed& cpy);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed& operator=(const Fixed& cpy);
};

#endif
