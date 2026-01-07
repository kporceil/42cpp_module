/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:41:31 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/07 16:43:30 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	swap(T& a, T& b) {
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T	min(T a, T b) {
	return (a > b ? b : a);
}

template <typename T>
T	max(T a, T b) {
	return (a < b ? b : a);
}
