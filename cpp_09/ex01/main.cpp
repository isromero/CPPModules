/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:53:22 by isromero          #+#    #+#             */
/*   Updated: 2024/07/01 21:33:35 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Documentation how to do RPN simplified for a stack: https://mathworld.wolfram.com/ReversePolishNotation.html
// #include "RPN.hpp"

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <sstream>

void isValidRPN(std::string expression)
{
	int i = 0;
	while (expression[i])
	{
		if (expression[i] == ' ' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
			i++;
		if ((expression[i] >= '0' && expression[i] <= '9') && (expression[i + 1] >= '0' && expression[i + 1] <= '9'))
			throw std::invalid_argument("Error. Invalid expression format. Numbers have to be less than 10.");
		else if ((expression[i] >= '0' && expression[i] <= '9') && (expression[i + 1] != ' ' && expression[i + 1] != '\0'))
			throw std::invalid_argument("Error. Invalid expression format. Ensure there are spaces between numbers and operators.");
		i++;
	}
}

int main(int argc, char **argv)
{
	// 1. Si un valor aparece en la expresión se hace push al stack
	// 2. Si un operador aparece se hace pop de los dos items anteriores y se hace push del resultado
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error. Try ./RPN \"expression\"");

		isValidRPN(argv[1]);
		std::stack<int> sk;

		std::string expression = argv[1];
		std::stringstream ss(expression);
		std::string token;

		while (getline(ss, token, ' '))
		{
			if ((token == "+" || token == "-" || token == "*" || token == "/"))
			{
				if (sk.size() < 2)
					throw std::runtime_error("Error. Not enough operands for operation");

				int a = sk.top();
				sk.pop();
				int b = sk.top();
				sk.pop();
				if (token == "+")
					sk.push(b + a);
				else if (token == "-")
					sk.push(b - a);
				else if (token == "*")
					sk.push(b * a);
				else if (token == "/")
				{
					if (a == 0)
						throw std::invalid_argument("Error. Division by zero");
					else
						sk.push(b / a);
				}
			}
			else if ((token[1] >= '0' && token[1] <= '9') && token[0] == '-')
				sk.push(-1 * (token[1] - '0'));
			else
				sk.push(token[0] - '0');
		}

		if (sk.size() != 1) // Si hay más de un elemento en el stack todavía, la expresión no es válida
			throw std::invalid_argument("Error. Invalid expression");
		std::cout << sk.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
