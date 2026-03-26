/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:15:44 by kporceil          #+#    #+#             */
/*   Updated: 2026/03/26 13:40:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <climits>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <vector>

class PmergeMe
{
private:
  std::vector<int> m_vec;
  std::deque<int> m_deq;

  void parseArgs (int argc, char **argv);
  void sortVector ();
  void sortDeque ();

  static std::vector<int> buildInsertionOrder (int n);

  template <typename Container> static void fordJohnson (Container &c);

  template <typename Container> static void print (const Container &c);

public:
  PmergeMe (int argc, char **argv);
  PmergeMe (PmergeMe const &cpy);
  ~PmergeMe ();

  PmergeMe &operator= (PmergeMe const &cpy);

  void sort ();
};

template <typename Container>
void
PmergeMe::fordJohnson (Container &c)
{
  typedef std::pair<int, int> IntPair;

  size_t n = c.size ();
  if (n <= 1)
    return;
  bool hasStraggler = (n % 2 != 0);
  int straggler = 0;
  if (hasStraggler)
    {
      straggler = c.back ();
      c.pop_back ();
      --n;
    }

  size_t half = n / 2;

  std::vector<IntPair> pairs (half);
  for (size_t i = 0; i < half; ++i)
    {
      int a = c[2 * i];
      int b = c[2 * i + 1];
      if (a < b)
        std::swap (a, b);
      pairs[i] = IntPair (a, b);
    }

  Container largers (half);
  for (size_t i = 0; i < half; ++i)
    {
      largers[i] = pairs[i].first;
    }

  fordJohnson (largers);

  std::multimap<int, int> valToSmall;
  for (size_t i = 0; i < half; ++i)
    {
      valToSmall.insert (IntPair (pairs[i].first, pairs[i].second));
    }
  std::vector<IntPair> sortedPairs (half);
  for (size_t i = 0; i < half; ++i)
    {
      std::multimap<int, int>::iterator it = valToSmall.find (largers[i]);
      sortedPairs[i] = IntPair (it->first, it->second);
      valToSmall.erase (it);
    }

  Container chain;
  chain.push_back (sortedPairs[0].second);
  for (size_t i = 0; i < half; ++i)
    {
      chain.push_back (sortedPairs[i].first);
    }

  size_t pendingSize = half - 1;
  std::vector<int> insertionOrder = buildInsertionOrder (pendingSize);

  for (size_t i = 0; i < insertionOrder.size (); ++i)
    {
      int idx = insertionOrder[i];
      int val = sortedPairs[idx + 1].second;

      int upperBoundVal = sortedPairs[idx + 1].first;
      typename Container::iterator end_it
          = std::upper_bound (chain.begin (), chain.end (), upperBoundVal);
      typename Container::iterator pos
          = std::lower_bound (chain.begin (), end_it, val);
      chain.insert (pos, val);
    }

  if (hasStraggler)
    {
      typename Container::iterator pos
          = std::lower_bound (chain.begin (), chain.end (), straggler);
      chain.insert (pos, straggler);
    }
  c = chain;
}

template <typename Container>
void
PmergeMe::print (const Container &c)
{
  typename Container::const_iterator it = c.begin ();
  for (; it != c.end (); ++it)
    {
      std::cout << *it << " ";
    }
  std::cout << "\n";
}

#endif
