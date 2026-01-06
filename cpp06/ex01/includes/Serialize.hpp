/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:40:01 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/06 20:42:16 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <stdint.h>

typedef struct s_data {
	int	value;
}				Data;

class Serialize {
	private:
		Serialize(void);
		Serialize(const Serialize& cpy);
		~Serialize(void);

		Serialize& operator=(const Serialize& cpy);
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
