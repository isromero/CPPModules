/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:59:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/16 21:20:12 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
public:
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static void convert(std::string const &literal);

private:
	ScalarConverter();

	static bool isChar(std::string const &literal);
	static bool isInt(std::string const &literal);
	static bool isFloat(std::string const &literal);
	static bool isDouble(std::string const &literal);
};

#endif
