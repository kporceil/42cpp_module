/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:37:36 by kporceil          #+#    #+#             */
/*   Updated: 2026/03/26 13:41:50 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>

PmergeMe::PmergeMe (int argc, char **argv)
{
  if (argc < 2)
    throw (std::runtime_error ("Wrong arguments"));
  parseArgs (argc, argv);
}

PmergeMe::PmergeMe (PmergeMe const &cpy) : m_vec (cpy.m_vec), m_deq (cpy.m_deq)
{
}

PmergeMe::~PmergeMe () {}

PmergeMe &
PmergeMe::operator= (PmergeMe const &cpy)
{
  if (this != &cpy)
    {
      m_vec = cpy.m_vec;
      m_deq = cpy.m_deq;
    }
  return (*this);
}

void
PmergeMe::parseArgs (int argc, char **argv)
{
  for (int i = 1; i < argc; ++i)
    {
      std::string token (argv[i]);
      if (token.empty ())
        throw (std::runtime_error ("Invalid args"));
      for (size_t j = 0; j < token.size (); ++j)
        {
          if (!std::isdigit (token[j]))
            throw (std::runtime_error ("Args can only be numeric"));
        }
      long val = std::strtol (token.c_str (), NULL, 10);
      if (val > INT_MAX || val < INT_MIN || errno == ERANGE)
        throw (std::runtime_error ("Arguments need to be integer"));
      m_vec.push_back (val);
      m_deq.push_back (val);
    }
}

void
PmergeMe::sort ()
{
  std::cout << "Before: ";
  print (m_vec);

  std::clock_t startVec = std::clock ();
  sortVector ();
  std::clock_t endVec = std::clock ();
  double timeVec
      = static_cast<double> (endVec - startVec) / CLOCKS_PER_SEC * 1e6;

  std::clock_t startDeq = std::clock ();
  sortDeque ();
  std::clock_t endDeq = std::clock ();
  double timeDeq
      = static_cast<double> (endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

  std::cout << "After: ";
  print (m_deq);

  for (size_t i = 0; i < m_vec.size (); ++i)
    {
      if (i > 0 && m_vec[i] < m_vec[i - 1])
        {
          std::cout << "vector not sorted" << std::endl;
          break;
        }
      if (i == m_vec.size () - 1)
        {
          std::cout << "vector sorted" << std::endl;
        }
    }

  for (size_t i = 0; i < m_deq.size (); ++i)
    {
      if (i > 0 && m_deq[i] < m_deq[i - 1])
        {
          std::cout << "deque not sorted" << std::endl;
          break;
        }
      if (i == m_deq.size () - 1)
        {
          std::cout << "deque sorted" << std::endl;
        }
    }

  std::cout << "Time to process a range of " << m_vec.size ()
            << " elements with std::vector : " << timeVec << "us\n";
  std::cout << "Time to process a range of " << m_deq.size ()
            << " elements with std::deque : " << timeDeq << "us\n";
}

void
PmergeMe::sortVector ()
{
  fordJohnson (m_vec);
}

void
PmergeMe::sortDeque ()
{
  fordJohnson (m_deq);
}

std::vector<int>
PmergeMe::buildInsertionOrder (int n)
{
  std::vector<int> order;
  if (n <= 0)
    return (order);
  std::vector<int> t;
  t.push_back (1);
  t.push_back (3);
  while (t.back () < n + 1)
    {
      int sz = t.size ();
      t.push_back ((1 << (sz + 1)) - t[sz - 1]);
    }
  for (int k = 1; k < static_cast<int> (t.size ()); ++k)
    {
      int b_high = std::min (t[k], n + 1);
      int b_low = t[k - 1] + 1;
      for (int b = b_high; b >= b_low; --b)
        {
          int pending_idx = b - 2;
          if (pending_idx >= 0 && pending_idx < n)
            order.push_back (pending_idx);
        }
      if (b_low > n + 1)
        break;
    }
  return (order);
}
