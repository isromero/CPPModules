/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:01:35 by isromero          #+#    #+#             */
/*   Updated: 2024/05/21 21:18:57 by isromero         ###   ########.fr       */
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

bool ScalarConverter::isInt(const std::string &literal)
{
	errno = 0; // Reset errno para detectar overflow/underflow
	char *end;
	std::strtoll(literal.c_str(), &end, 10);

	if (errno == ERANGE || *end != '\0')
		return (false);
	return (true);
}

bool ScalarConverter::isFloat(std::string const &literal)
{
	errno = 0;
	std::string checkLiteral = literal;
	if (checkLiteral.back() == 'f' && checkLiteral.size() > 1)
		checkLiteral.pop_back();
	else
		return (false); // Si no tiene una f al final no es float aunque puede ser double
	char *end;
	std::strtof(checkLiteral.c_str(), &end);

	// Check si ha habido algún error en la conversión como overflow/underflow o si la string no termina con el '\0'
	if (errno == ERANGE || *end != '\0')
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	errno = 0;
	char *end;
	std::strtod(literal.c_str(), &end);

	// Check si ha habido algún error en la conversión como overflow/underflow o si la string no termina con el '\0'
	if (errno == ERANGE || *end != '\0')
		return (false);
	return (true);
}

void ScalarConverter::convert(std::string const &literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (ScalarConverter::isChar(literal))
	{
		char charValue = literal[0];
		std::cout << "char: " << static_cast<char>(charValue) << std::endl;
		std::cout << "int: " << static_cast<int>(charValue) << std::endl;
		std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(charValue) << ".0" << std::endl;
	}
	else if (ScalarConverter::isInt(literal))
	{
		long long int intValue = std::stoll(literal);
		if ((intValue >= 0 && intValue <= 31) || intValue == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (intValue >= 32 && intValue < 127)
			std::cout << "char: " << static_cast<char>(intValue) << std::endl;
		else
			std::cout << "char: Impossible" << std::endl;
		if (intValue < INT_MIN || intValue > INT_MAX)
			std::cout << "int: Impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(intValue) << std::endl;
		std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
	}
	else if (ScalarConverter::isFloat(literal))
	{
		float floatValue = std::stof(literal);
		if ((floatValue >= 0 && floatValue <= 31) || floatValue == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (floatValue >= 32 && floatValue < 127)
			std::cout << "char: " << static_cast<char>(floatValue) << std::endl;
		else
			std::cout << "char: Impossible" << std::endl;
		if (floatValue < INT_MIN || floatValue > INT_MAX)
			std::cout << "int: Impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
		if (floatValue - static_cast<int>(floatValue) == 0)
			std::cout << "float: " << static_cast<float>(floatValue) << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(floatValue) << "f" << std::endl;
		if (floatValue - static_cast<int>(floatValue) == 0)
			std::cout << "double: " << static_cast<double>(floatValue) << ".0" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
	}
	else if (ScalarConverter::isDouble(literal))
	{
		double doubleValue = std::stod(literal);
		if ((doubleValue >= 0 && doubleValue <= 31) || doubleValue == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (doubleValue >= 32 && doubleValue < 127)
			std::cout << "char: " << static_cast<char>(doubleValue) << std::endl;
		else
			std::cout << "char: Impossible" << std::endl;
		if (doubleValue < INT_MIN || doubleValue > INT_MAX)
			std::cout << "int: Impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
		if (doubleValue - static_cast<int>(doubleValue) == 0)
			std::cout << "float: " << static_cast<float>(doubleValue) << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
		if (doubleValue - static_cast<int>(doubleValue) == 0)
			std::cout << "double: " << static_cast<double>(doubleValue) << ".0" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(doubleValue) << std::endl;
	}
	else
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: Impossible" << std::endl;
		std::cout << "double: Impossible" << std::endl;
	}
}
