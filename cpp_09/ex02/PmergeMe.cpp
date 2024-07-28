/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:48:11 by isromero          #+#    #+#             */
/*   Updated: 2024/07/28 14:06:35 by isromero         ###   ########.fr       */
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

template <typename Container>
Container PmergeMe::parseArgs(int argc, char **argv)
{
	Container numbers;
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		std::stringstream ss(arg);
		int num;
		char extra;

		// Debe ser un número entero válido y no debe haber ningún carácter adicional
		if (!(ss >> num) || ss.get(extra))
			throw std::invalid_argument("Error: Invalid number '" + arg + "'. Each argument must be a single number.");
		else if (num < 0) // Solo números positivos
			throw std::invalid_argument("Error: Invalid number '" + arg + "'. Each number must be positive.");

		numbers.push_back(num);
	}
	return (numbers);
}

template <typename Container>
int PmergeMe::binarySearch(const Container &S, int T)
{
	int left = 0;
	int right = S.size() - 1;
	int middle;

	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (S[middle] == T)
			return middle;
		else if (S[middle] < T)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return (left); // Devuelve la posición donde se debe insertar el elemento
}

// Inserción de un par de elementos en el vector de forma ordenada por el valor mayor
template <typename PairContainer>
void PmergeMe::insertPair(const typename PairContainer::value_type &element, PairContainer &sortedPairs)
{
	typename PairContainer::iterator it = std::lower_bound(sortedPairs.begin(), sortedPairs.end(), element);
	sortedPairs.insert(it, element);
}

// Ordenación de los pares de elementos por el valor mayor
template <typename PairContainer>
void PmergeMe::insertionSortPairs(PairContainer &pairs, int n, PairContainer &sortedPairs)
{
	if (n < 0)
		return;
	insertionSortPairs(pairs, n - 1, sortedPairs);
	insertPair(pairs[n], sortedPairs);
}

// Algoritmo de ordenación Ford-Johnson
template <typename Container, typename PairContainer>
Container PmergeMe::fordJohnsonSort(Container &numbers)
{
	// Paso 1: Crear los pares de elementos
	PairContainer pairs;
	for (size_t i = 0; i < numbers.size() - 1; i += 2)
	{
			if (numbers[i] < numbers[i + 1])
					pairs.push_back(std::make_pair(numbers[i], numbers[i + 1]));
			else
					pairs.push_back(std::make_pair(numbers[i + 1], numbers[i]));
	}

	int lastSingle = -1;
	if (numbers.size() % 2 != 0)
		lastSingle = numbers.back();

	// Paso 3: Ordenar los pares por su mayor valor de manera ascendente y recursiva. Creando la secuencia S de los mayores valores
	PairContainer X;
	insertionSortPairs(pairs, pairs.size() - 1, X);
	Container S;
	for (size_t i = 0; i < X.size(); ++i)
		S.push_back(X[i].second);

	// Paso 4: Insertar al principio de S el menor valor del primer par (el primero)
	S.insert(S.begin(), X[0].first);
	X.erase(X.begin());

	// Paso 5: Insertar los elementos restantes de los pares de X en S utilizando binary search
	Container Xnopairs;
	for (size_t i = 0; i < X.size(); ++i)
		Xnopairs.push_back(X[i].first);
	for (size_t i = 0; i < Xnopairs.size(); ++i)
	{
		int insertPos = binarySearch(S, Xnopairs[i]);
		S.insert(S.begin() + insertPos, Xnopairs[i]);
	}

	// Inserción del último elemento individual, si existe
	if (lastSingle != -1)
	{
		int insertPos = binarySearch(S, lastSingle);
		S.insert(S.begin() + insertPos, lastSingle);
	}

	return (S);
}

template <typename Container>
void PmergeMe::printSorts(const Container &numbers, const Container &sortedNumbers)
{
	std::cout << "Before: ";
	for (size_t i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < sortedNumbers.size(); ++i)
		std::cout << sortedNumbers[i] << " ";
	std::cout << std::endl;
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