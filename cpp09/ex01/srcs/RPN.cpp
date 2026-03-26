/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 09:57:38 by kporceil          #+#    #+#             */
/*   Updated: 2026/03/26 09:58:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <stdexcept>

typedef std::stack<int> RPNStack;

static void
perform_operation (RPNStack &stack, char token)
{
  if (stack.size () != 2)
    throw (std::runtime_error ("Wrong number in the stack"));
  int f_operand = stack.top ();
  stack.pop ();
  int s_operand = stack.top ();
  stack.pop ();

  switch (token)
    {
    case '+':
      stack.push (s_operand + f_operand);
      return;
    case '-':
      stack.push (s_operand - f_operand);
      return;
    case '*':
      stack.push (s_operand * f_operand);
      return;
    case '/':
      if (f_operand == 0)
        throw (std::runtime_error ("cannot divide by zero"));
      stack.push (s_operand / f_operand);
      return;
    default:
      throw (std::runtime_error ("Bad token"));
    }
}

long
RPN (std::string const &expr)
{
  RPNStack stack;
  std::stringstream ss (expr);
  char token;

  while ((ss >> token))
    {
      if (std::isdigit (token))
        {
          stack.push (token - '0');
        }
      else
        {
          perform_operation (stack, token);
        }
    }

  if (stack.size () != 1)
    throw (std::runtime_error ("Wrong number in the stack"));
  return (stack.top ());
}
