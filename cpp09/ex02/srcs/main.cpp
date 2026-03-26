/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:41:55 by kporceil          #+#    #+#             */
/*   Updated: 2026/03/26 13:42:24 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>

int
main (int argc, char **argv)
{
  try
    {
      PmergeMe pm (argc, argv);
      pm.sort ();
    }
  catch (std::exception const &e)
    {
      std::cerr << e.what () << std::endl;
      return (1);
    }
  return (0);
}
