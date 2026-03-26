/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 09:51:51 by kporceil          #+#    #+#             */
/*   Updated: 2026/03/26 09:53:18 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <iostream>

int
main (int argc, char **argv)
{
  if (argc != 2)
    {
      std::cout << "Usage: ./RPN \"expression\"" << std::endl;
      return (1);
    }
  try
    {
      std::cout << RPN (argv[1]) << std::endl;
    }
  catch (std::exception &e)
    {
      std::cerr << e.what () << std::endl;
      return (1);
    }
  return (0);
}
