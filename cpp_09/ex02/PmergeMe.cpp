/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:48:11 by isromero          #+#    #+#             */
/*   Updated: 2024/07/28 16:55:02 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _expression(other._expression) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		_expression = other._expression;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::printTimes(const struct timeval &begin, const struct timeval &end, size_t size, const std::string &containerType)
{
	long int seconds = end.tv_sec - begin.tv_sec;
	long int microseconds = end.tv_usec - begin.tv_usec;
	double elapsed = seconds + microseconds * 1e-6;

	std::cout << std::fixed << std::setprecision(3);
	if (elapsed >= 1.0)
		std::cout << "Time to process a range of " << size << " elements with " << containerType << " " << elapsed << " s" << std::endl;
	else if (elapsed >= 1e-3)
		std::cout << "Time to process a range of " << size << " elements with " << containerType << " " << elapsed * 1e3 << " ms" << std::endl;
	else if (elapsed >= 1e-6)
		std::cout << "Time to process a range of " << size << " elements with " << containerType << " " << elapsed * 1e6 << " us" << std::endl;
	else
		std::cout << "Time to process a range of " << size << " elements with " << containerType << " " << elapsed * 1e9 << " ns" << std::endl;
}
