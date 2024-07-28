/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:19:11 by isromero          #+#    #+#             */
/*   Updated: 2024/07/28 12:06:25 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int binarySearch(const std::vector<int> &S, int T)
{
	int L = 0;
	int R = S.size() - 1;
	while (L <= R)
	{
		int M = (L + R) / 2;
		if (S[M] < T)
			L = M + 1;
		else if (S[M] > T)
			R = M - 1;
	}
	return (L); // L es la posición donde T debería ser insertado en S
}

// Inserción de un par de elementos en el vector de forma ordenada por el valor mayor
void insertPair(const std::pair<int, int> &element, std::vector<std::pair<int, int> > &sortedPairs)
{
	size_t insertPos = 0;
	while (insertPos < sortedPairs.size() && sortedPairs[insertPos].second <= element.second)
		++insertPos;
	sortedPairs.insert(sortedPairs.begin() + insertPos, element);
}

// Ordenamiento recursivo de pares por su valor mayor
void insertionSortPairs(std::vector<std::pair<int, int> > &pairs, int n, std::vector<std::pair<int, int> > &sortedPairs)
{
	if (n < 0)
		return;
	insertionSortPairs(pairs, n - 1, sortedPairs);
	insertPair(pairs[n], sortedPairs);
}

// Función principal para el ordenamiento de Ford-Johnson
std::vector<int> fordJohnsonSort(std::vector<int> &numbers)
{
	// Paso 1: Formar pares y Paso 2: Ordenar pares
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < numbers.size() - 1; i += 2)
	{
		if (numbers[i] < numbers[i + 1])
			pairs.push_back(std::make_pair(numbers[i], numbers[i + 1]));
		else
			pairs.push_back(std::make_pair(numbers[i + 1], numbers[i]));
	}
	// Si hay un número sin par, lo manejamos al final
	int lastSingle = -1;
	if (numbers.size() % 2 != 0)
		lastSingle = numbers.back();

	// Paso 3: Ordenar los pares por su mayor valor de manera ascendente y recursiva. Creando la secuencia S de los mayores valores
	std::vector<std::pair<int, int> > X;
	insertionSortPairs(pairs, pairs.size() - 1, X);
	std::vector<int> S;
	for (size_t i = 0; i < X.size(); ++i)
		S.push_back(X[i].second);

	// Paso 4: Insertar al principio de S el menor valor del primer par (el primero)
	S.insert(S.begin(), X[0].first);
	X.erase(X.begin());

	// Paso 5: Insertar los elementos restantes de los pares de X en S utilizando binary search
	std::vector<int> Xnopairs;
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

	return S;
}

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error. Try ./PmergeMe \"expression\"");

		std::vector<int> X;
		std::stringstream ss(argv[1]);
		int num;
		while (ss >> num)
			X.push_back(num);

		std::vector<int> sortedNumbers = fordJohnsonSort(X);

		for (size_t i = 0; i < sortedNumbers.size(); ++i)
			std::cout << sortedNumbers[i] << " ";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
