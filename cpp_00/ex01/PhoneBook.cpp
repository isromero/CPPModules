/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:25:16 by isromero          #+#    #+#             */
/*   Updated: 2024/04/08 15:45:31 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _totalContacts(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(void)
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

	int index = _totalContacts % 8;
	_contacts[index] = newContact;
	if (_totalContacts < 8)
		_totalContacts++;
}

void PhoneBook::searchContact(void) const
{
}
