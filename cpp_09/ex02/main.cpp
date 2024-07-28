/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:19:11 by isromero          #+#    #+#             */
/*   Updated: 2024/07/28 16:56:46 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Usage: ./fordJohnsonSort <int1> <int2> ... <intN>");

		/* STD::VECTOR */
		// Empieza a medir el tiempo
		struct timeval beginVector, endVector;
		gettimeofday(&beginVector, 0);

		PmergeMe pmmVector;
		std::vector<int> vector = pmmVector.parseArgs<std::vector<int> >(argc, argv);
		std::vector<int> sortedVector = pmmVector.fordJohnsonSort<std::vector<int>, std::vector<std::pair<int, int> > >(vector);

		// Para de medir el tiempo y muestra los resultados calculados
		gettimeofday(&endVector, 0);
		pmmVector.printSorts(vector, sortedVector);
		pmmVector.printTimes(beginVector, endVector, vector.size(), "std::vector");

		/* STD::DEQUE */
		struct timeval beginDeque, endDeque;
		gettimeofday(&beginDeque, 0);

		PmergeMe pmmDeque;
		std::deque<int> deque = pmmDeque.parseArgs<std::deque<int> >(argc, argv);
		std::deque<int> sortedDeque = pmmDeque.fordJohnsonSort<std::deque<int>, std::deque<std::pair<int, int> > >(deque);

		gettimeofday(&endDeque, 0);

		gettimeofday(&endDeque, 0);
		pmmDeque.printTimes(beginDeque, endDeque, deque.size(), "std::deque");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
