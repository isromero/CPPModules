/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:44:16 by isromero          #+#    #+#             */
/*   Updated: 2024/07/28 16:56:38 by isromero         ###   ########.fr       */
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

/* Definición de las funciones template porque el ejercicio no indica que podamos subir archivo PmergeMe.tpp */

// Función comparadora para `std::lower_bound`
template <typename T>
bool comparePairs(const std::pair<T, T> &a, const std::pair<T, T> &b)
{
	return a.second < b.second; // Ordena los pares basándose en `second`
}

// Inserción de un par de elementos en el vector de forma ordenada por el valor mayor
template <typename PairContainer>
void PmergeMe::insertPair(const typename PairContainer::value_type &element, PairContainer &sortedPairs)
{
	typename PairContainer::iterator it = std::lower_bound(sortedPairs.begin(), sortedPairs.end(), element, comparePairs<typename PairContainer::value_type::first_type>);
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

#endif
