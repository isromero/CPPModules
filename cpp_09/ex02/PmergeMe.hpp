/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:44:16 by isromero          #+#    #+#             */
/*   Updated: 2024/07/28 14:03:41 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <sstream>
#include <sys/time.h>
#include <iomanip>
#include <deque>
class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	template <typename Container>
	static Container parseArgs(int argc, char **argv);

	template <typename Container>
	int binarySearch(const Container &S, int T);

	template <typename PairContainer>
	void insertPair(const typename PairContainer::value_type &element, PairContainer &sortedPairs);

	template <typename PairContainer>
	void insertionSortPairs(PairContainer &pairs, int n, PairContainer &sortedPairs);

	template <typename Container, typename PairContainer>
	Container fordJohnsonSort(Container &numbers);

	template <typename Container>
	void printSorts(const Container &numbers, const Container &sortedNumbers);

	void printTimes(const struct timeval &begin, const struct timeval &end, size_t size, const std::string &containerType);

private:
	std::string _expression;
};

#include "PmergeMe.cpp"

#endif
