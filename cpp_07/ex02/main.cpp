/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:05:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/29 21:29:55 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<std::string> str(1);
	str[0] = "hola";
	std::cout << "str: " << str[0] << std::endl;

	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i;
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "arr[" << i << "]: " << arr[i] << std::endl;

	Array<std::string> str2(2);
	str2[0] = str[0];
	str2[1] = "adios";
	std::cout << "str2[0]: " << str2[0] << std::endl;
	std::cout << "str2[1]: " << str2[1] << std::endl;
	std::cout << "str[0] no ha cambiado: " << str[0] << std::endl;

	Array<std::string> str_cpy(str2);
	std::cout << "str_cpy[0]: " << str_cpy[0] << std::endl;

	str[0] = "cambio";
	std::cout << "str[0] ha cambiado: " << str[0] << std::endl;
	std::cout << "str_cpy[0] no ha cambiado: " << str_cpy[0] << std::endl;
	std::cout << "str2[0] no ha cambiado: " << str2[0] << std::endl;
	return (0);
}
