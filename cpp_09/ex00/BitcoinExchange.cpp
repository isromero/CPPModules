/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:48:11 by isromero          #+#    #+#             */
/*   Updated: 2024/04/27 11:06:32 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &csvFilename, const std::string &inputFilename) : _csvFilename(csvFilename), _inputFilename(inputFilename)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _csvFilename(other._csvFilename), _inputFilename(other._inputFilename), _csvData(other._csvData), _inputData(other._inputData)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_csvData = other._csvData;
		this->_inputData = other._inputData;
		this->_csvFilename = other._csvFilename;
		this->_inputFilename = other._inputFilename;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool isLeapYear(unsigned int year)
{
	return ((!year % 4) && (year % 100)) || !(year % 400);
}

bool BitcoinExchange::_validateDate(unsigned int year, unsigned int month, unsigned int day)
{
	unsigned int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (!year || !month || !day || month > 12)
		return (false);
	if (isLeapYear(year) && month == 2)
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return (false);
	return (true);
}

void BitcoinExchange::parseCsv()
{
	std::ifstream csv(this->_csvFilename.c_str());
	if (!csv.is_open())
		throw std::runtime_error("Error opening data.csv");

	std::string line;

	std::getline(csv, line); // Ignoramos la primera línea saltándola
	while (std::getline(csv, line))
	{
		std::stringstream ss(line); // Lo utilizamos para coger la línea y utilizarla como un stream(como si fuese un fichero)
		std::string date;			// key
		float exchange_rate = 0.0f; // value

		if (std::getline(ss, date, ','))
		{
			ss >> exchange_rate;
			this->_csvData.insert(std::pair<std::string, float>(date, exchange_rate));
		}
	}
	csv.close();
}

void BitcoinExchange::parseInput()
{
	std::ifstream input(this->_inputFilename.c_str());
	if (!input.is_open())
		throw std::runtime_error("Error opening: " + this->_inputFilename);

	std::string line;

	std::getline(input, line); // Ignoramos la primera línea saltándola
	while (std::getline(input, line))
	{
		std::stringstream ss(line);
		std::string date;
		float value = 0.0f;

		size_t pos = line.find(" | ");
		if (pos != std::string::npos) // Si find no encuentra nada devuelve std::string::npos
		{
			date = line.substr(0, pos);
			date.erase(std::remove(date.begin(), date.end(), ' '), date.end()); // Eliminamos los espacios en blanco

			std::string value_str = line.substr(pos + 3);

			value_str.erase(std::remove(value_str.begin(), value_str.end(), ' '), value_str.end());

			std::stringstream ss2(value_str);
			ss2 >> value;

			this->_inputData.insert(std::pair<std::string, float>(date, value));
		}
		else // En el caso de no tener el formato de | lo añadimos como "bad input"
			this->_inputData.insert(std::pair<std::string, float>("bad input", 0.0f));
	}
	input.close();
}

void BitcoinExchange::executeExchange()
{
	std::multimap<std::string, float>::iterator it;
	for (it = this->_inputData.begin(); it != this->_inputData.end(); it++)
	{
		std::string date = it->first;
		unsigned int year = std::atoi(date.substr(0, 4).c_str());
		unsigned int month = std::atoi(date.substr(5, 2).c_str());
		unsigned int day = std::atoi(date.substr(8, 2).c_str());
		if (it->first == "bad input")
			std::cerr << "Error: bad input" << std::endl; // Si no tiene el formato correcto ('date | value') la key está guardada como "bad input"
		else if (it->second < 0)
			std::cerr << "Error: not a positive number" << std::endl;
		else if (it->second > 1000)
			std::cerr << "Error: too large a number" << std::endl;
		else if (!this->_validateDate(year, month, day))
			std::cerr << "Error: invalid date" << std::endl;
		else if (this->_csvData.find(it->first) != this->_csvData.end()) // Si devuelve this->_csvData.end() significa que no hay coincidencia en fecha
		{
			std::cout << it->first << " => " << it->second << " = " << this->_csvData.find(it->first)->second * it->second << std::endl;
		}

		else if (this->_csvData.find(it->first) == this->_csvData.end()) // No hay coincidencia con fecha por lo que buscamos la más cercana
		{
			std::multimap<std::string, float>::iterator closest = this->_csvData.lower_bound(it->first);
			if (closest != this->_csvData.begin())
			{
				closest--; // Nos quedamos con la fecha más cercana anterior
				std::cout << it->first << "(Not found in db, closest: " << closest->first << ") => " << it->second << " = " << closest->second * it->second << std::endl;
			}
			else if (closest == this->_csvData.begin()) // Si no hay fecha anterior cogemos la más pequeña del csv
			{
				std::cout << it->first << "(Not found in db, closest: " << closest->first << ") => " << it->second << " = " << closest->second * it->second << std::endl;
			}
		}
	}
}
