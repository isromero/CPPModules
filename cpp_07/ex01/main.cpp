/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:05:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/28 20:39:17 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int arrInts[] = {1, 2, 3, 4, 5};

	iter(arrInts, 5, printArray);

	float arrFloats[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(arrFloats, 5, printArray);

	std::string arrStrings[] = {"one", "two", "three", "four", "five"};
	iter(arrStrings, 5, printArray);

	double arrDoubles[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(arrDoubles, 5, printArray);

	return (0);
}
