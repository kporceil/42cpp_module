/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:38:04 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/25 21:39:06 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl	complain;

	complain.complain("DEBUG");
	complain.complain("INFO");
	complain.complain("WARNING");
	complain.complain("ERROR");
	complain.complain("test");
}
