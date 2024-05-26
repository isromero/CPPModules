/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:25:16 by isromero          #+#    #+#             */
/*   Updated: 2024/05/26 14:29:25 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _totalContacts(0), _index(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
	if (_totalContacts == 8)
		std::cout << "PhoneBook is full. The oldest contact will be replaced." << std::endl;

	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	while (firstName.empty())
	{
		std::cout << "First Name cannot be empty. Please enter First Name: ";
		std::getline(std::cin, firstName);
	}

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	while (lastName.empty())
	{
		std::cout << "Last Name cannot be empty. Please enter Last Name: ";
		std::getline(std::cin, lastName);
	}

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	while (nickname.empty())
	{
		std::cout << "Nickname cannot be empty. Please enter Nickname: ";
		std::getline(std::cin, nickname);
	}

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.empty())
	{
		std::cout << "Phone Number cannot be empty. Please enter Phone Number: ";
		std::getline(std::cin, phoneNumber);
	}

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);
	while (darkestSecret.empty())
	{
		std::cout << "Darkest Secret cannot be empty. Please enter Darkest Secret: ";
		std::getline(std::cin, darkestSecret);
	}

	Contact newContact;
	newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);

	_contacts[this->_index] = newContact;
	this->_index = (this->_index + 1) % 8;

	if (_totalContacts < 8)
		_totalContacts++;
}

void PhoneBook::searchContact() const
{
	if (_totalContacts > 0)
	{
		std::cout << std::setw(10) << "Index"
				  << "|";
		std::cout << std::setw(10) << "First Name"
				  << "|";
		std::cout << std::setw(10) << "Last Name"
				  << "|";
		std::cout << std::setw(10) << "Nickname" << std::endl;
		for (int i = 0; i < _totalContacts; i++)
		{
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << _contacts[i].getFirstName() << "|";
			std::cout << std::setw(10) << _contacts[i].getLastName() << "|";
			std::cout << std::setw(10) << _contacts[i].getNickname() << std::endl;
		}

		std::string input;
		std::cout << "Enter the index of the contact you want to see: ";
		std::getline(std::cin, input);
		while (input.empty())
		{
			std::cout << "Index cannot be empty. Please enter the index of the contact you want to see: ";
			std::getline(std::cin, input);
		}

		int index;
		if (std::isdigit(input[0]))
			index = atoi(input.c_str());
		else
			index = -1;

		if (index >= 0 && index < _totalContacts)
		{
			std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
			std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
			std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
		}
		else
			std::cout << "Invalid index" << std::endl;
	}
	else
		std::cout << "No contacts to show" << std::endl;
}
