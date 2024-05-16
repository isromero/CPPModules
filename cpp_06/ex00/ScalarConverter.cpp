/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:01:35 by isromero          #+#    #+#             */
/*   Updated: 2024/05/16 21:22:03 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isChar(std::string const &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]));
}

bool ScalarConverter::isInt(std::string const &literal)
{
	// Declara un puntero a char. Este será utilizado por strtol para apuntar
	// al primer carácter no convertible de la cadena.
	char *p;

	// Convierte la cadena 'literal' a un número entero (long int).
	// - line.c_str(): Obtiene un puntero const char* a los datos internos de la cadena 'literal'.
	// - &p: La dirección del puntero 'p' se pasa a strtol. strtol actualiza este puntero
	//   para que apunte al primer carácter en 'literal' que no pudo ser convertido a un número.
	// - 10: Especifica la base en la que se interpreta el número (base decimal).
	strtol(literal.c_str(), &p, 10);

	// Verifica si el primer carácter no convertible es el carácter nulo ('\0').
	// Esto significa que toda la cadena fue convertida con éxito a un número entero.
	// Si *p == 0, significa que 'p' apunta al carácter nulo, indicando el final de la cadena.
	return (*p == 0);
}

void ScalarConverter::convert(std::string const &literal)
{
	if (ScalarConverter::isChar(literal))
	{
		char charValue = literal[0];
		std::cout << "char: " << static_cast<char>(charValue) << std::endl;
		std::cout << "int: " << static_cast<int>(charValue) << std::endl;
		std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(charValue) << ".0" << std::endl;
	}
	else if (ScalarConverter::isInt(literal))
	{
		int intValue = std::stoi(literal);
		std::cout << "char: " << static_cast<char>(intValue) << std::endl;
		std::cout << "int: " << static_cast<int>(intValue) << std::endl;
		std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
	}
}
