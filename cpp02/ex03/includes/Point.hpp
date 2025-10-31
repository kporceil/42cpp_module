/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:28:53 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/30 21:34:18 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		Fixed const	m_x;
		Fixed const	m_y;
	public:
		Point(void);
		Point(float const x, float const y);
		Point(const Point& cpy);
		~Point(void);

		Fixed const&	getX(void) const;
		Fixed const&	getY(void) const;

		Point& operator=(const Point& cpy);

};

#endif
