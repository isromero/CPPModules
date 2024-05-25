/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:05:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/25 13:40:54 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include "Data.hpp"

int main()
{
	Data myData = {42, "Example"}; // Creando un objeto Data con valores iniciales
	Data *ptr = &myData;		   // Inicializando ptr para apuntar a myData y hacer todo en el stack (se puede hacer en el heap con new Data)

	std::cout << "Original pointer: " << ptr << std::endl;

	// Serializar el puntero a Data
	uintptr_t serializedData = Serialization::serialize(ptr);
	std::cout << "Serialized data: " << serializedData << std::endl;

	// Deserializar de vuelta a puntero a Data
	Data *deserializedPtr = Serialization::deserialize(serializedData);
	std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

	// Verificar que el puntero deserializado es igual al original
	if (ptr == deserializedPtr)
		std::cout << "Success: Deserialized pointer matches the original." << std::endl;
	else
		std::cout << "Error: Deserialized pointer does not match the original." << std::endl;

	return (0);
}
