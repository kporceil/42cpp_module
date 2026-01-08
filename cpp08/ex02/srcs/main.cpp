/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:44:54 by kporceil          #+#    #+#             */
/*   Updated: 2026/01/08 18:47:21 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		std::cout << "===== MUTANT STACK OUTPUT =====" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::cout << "===== STD::LIST OUTPUT =====" << std::endl;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "===== CONST ITERATOR TEST (MUTANT STACK) =====" << std::endl;
		MutantStack<int> mstack;
		mstack.push(42);
		mstack.push(21);
		mstack.push(84);
		mstack.push(100);

		const MutantStack<int>& const_ref = mstack;
		MutantStack<int>::const_iterator it = const_ref.begin();
		MutantStack<int>::const_iterator ite = const_ref.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "===== CONST ITERATOR TEST (STD::LIST) =====" << std::endl;
		std::list<int> lst;
		lst.push_back(42);
		lst.push_back(21);
		lst.push_back(84);
		lst.push_back(100);

		const std::list<int>& const_ref = lst;
		std::list<int>::const_iterator it = const_ref.begin();
		std::list<int>::const_iterator ite = const_ref.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "===== REVERSE ITERATOR TEST (MUTANT STACK) =====" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();

		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "===== REVERSE ITERATOR TEST (STD::LIST) =====" << std::endl;
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);

		std::list<int>::reverse_iterator rit = lst.rbegin();
		std::list<int>::reverse_iterator rite = lst.rend();

		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "===== CONST REVERSE ITERATOR TEST (MUTANT STACK) =====" << std::endl;
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(20);
		mstack.push(30);

		const MutantStack<int>& const_ref = mstack;
		MutantStack<int>::const_reverse_iterator rit = const_ref.rbegin();
		MutantStack<int>::const_reverse_iterator rite = const_ref.rend();

		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "===== CONST REVERSE ITERATOR TEST (STD::LIST) =====" << std::endl;
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);

		const std::list<int>& const_ref = lst;
		std::list<int>::const_reverse_iterator rit = const_ref.rbegin();
		std::list<int>::const_reverse_iterator rite = const_ref.rend();

		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}
	return 0;
}
