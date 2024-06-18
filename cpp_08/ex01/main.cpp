/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:53:22 by isromero          #+#    #+#             */
/*   Updated: 2024/06/18 21:33:47 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(30000);

	try
	{
		for (int i = 0; i < 15000; i++)
			sp.addNumber(i);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.largestSpan() << std::endl;

		std::vector<int> v(15000);
		for (int i = 0; i < 15000; i++)
			v[i] = i;
		sp.addRange(v.begin(), v.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.largestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
