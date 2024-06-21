/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:53:22 by isromero          #+#    #+#             */
/*   Updated: 2024/06/20 20:45:49 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		Span sp = Span(30000);

		try
		{
			std::cout << "---- Testing with 30000 elements ----" << std::endl;
			for (int i = 0; i < 15000; i++)
				sp.addNumber(i);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Largest span: " << sp.largestSpan() << std::endl;

			std::vector<int> v(15000);
			for (int i = 0; i < 15000; i++)
				v[i] = i;
			sp.addRange(v.begin(), v.end());
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Saldrá distancia 0 porque habrá duplicados y la distancia menor entre dos elementos iguales es 0
			std::cout << "Largest span: " << sp.largestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(1);

		try
		{
			std::cout << "---- Testing with 1 element ----" << std::endl;
			sp.addNumber(1);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Largest span: " << sp.largestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(2);

		try
		{
			std::cout << "---- Testing with 2 elements ----" << std::endl;
			sp.addNumber(1);
			sp.addNumber(3);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Largest span: " << sp.largestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(3);

		try
		{
			std::cout << "---- Testing with 3 elements ----" << std::endl;
			sp.addNumber(1);
			sp.addNumber(3);
			sp.addNumber(5);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Largest span: " << sp.largestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(4);

		try
		{
			std::cout << "---- Testing with 4 elements ----" << std::endl;
			sp.addNumber(1);
			sp.addNumber(3);
			sp.addNumber(5);
			sp.addNumber(7);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Largest span: " << sp.largestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(5);

		try
		{
			std::cout << "---- Testing with 5 elements ----" << std::endl;
			sp.addNumber(1);
			sp.addNumber(3);
			sp.addNumber(5);
			sp.addNumber(7);
			sp.addNumber(9);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Largest span: " << sp.largestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(2);

		try
		{
			std::cout << "---- Testing with INT_MAX ----" << std::endl;

			sp.addNumber(INT_MAX);
			sp.addNumber(0);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Largest span: " << sp.largestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(2);

		try
		{
			std::cout << "---- Testing with INT_MIN ----" << std::endl;

			sp.addNumber(INT_MIN + 1); // Le tengo que sumar 1 ya que el valor absoluto de INT_MIN es mayor que INT_MAX y printearía INT_MIN
			sp.addNumber(0);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Largest span: " << sp.largestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
