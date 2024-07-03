/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:48:11 by isromero          #+#    #+#             */
/*   Updated: 2024/04/27 11:06:32 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _sk(), _expression("1 1 +")
{
}

RPN::RPN(const std::string &expression) : _sk(), _expression(expression)
{
}

RPN::RPN(const RPN &other) : _sk(other._sk), _expression(other._expression)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_sk = other._sk;
		_expression = other._expression;
	}
	return (*this);
}

RPN::~RPN()
{
}

void RPN::isValidRPN()
{
	int i = 0;
	while (this->_expression[i])
	{
		if (this->_expression[i] == ' ' || this->_expression[i] == '+' || this->_expression[i] == '-' || this->_expression[i] == '*' || this->_expression[i] == '/')
			i++;
		if ((this->_expression[i] >= '0' && this->_expression[i] <= '9') && (this->_expression[i + 1] >= '0' && this->_expression[i + 1] <= '9'))
			throw std::invalid_argument("Error. Invalid expression format. Numbers have to be less than 10.");
		else if ((this->_expression[i] >= '0' && this->_expression[i] <= '9') && (this->_expression[i + 1] != ' ' && this->_expression[i + 1] != '\0'))
			throw std::invalid_argument("Error. Invalid expression format. Ensure there are spaces between numbers and operators.");
		i++;
	}
}

void RPN::executeRPN()
{
	// 1. Si un valor aparece en la expresión se hace push al stack
	// 2. Si un operador aparece se hace pop de los dos items anteriores y se hace push del resultado
	std::stringstream ss(this->_expression);
	std::string token;

	while (getline(ss, token, ' '))
	{
		if ((token == "+" || token == "-" || token == "*" || token == "/"))
		{
			if (this->_sk.size() < 2)
				throw std::invalid_argument("Error. Not enough operands for operation");

			int a = this->_sk.top();
			this->_sk.pop();
			int b = this->_sk.top();
			this->_sk.pop();
			if (token == "+")
				this->_sk.push(b + a);
			else if (token == "-")
				this->_sk.push(b - a);
			else if (token == "*")
				this->_sk.push(b * a);
			else if (token == "/")
			{
				if (a == 0)
					throw std::invalid_argument("Error. Division by zero");
				else
					this->_sk.push(b / a);
			}
		}
		else if ((token[1] >= '0' && token[1] <= '9') && token[0] == '-')
			this->_sk.push(-1 * (token[1] - '0'));
		else
			this->_sk.push(token[0] - '0');
	}
	if (this->_sk.size() != 1) // Si hay más de un elemento en el stack todavía, la expresión no es válida
		throw std::invalid_argument("Error. Invalid expression");
	std::cout << this->_sk.top() << std::endl;
}
