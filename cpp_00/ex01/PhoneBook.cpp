/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:25:16 by isromero          #+#    #+#             */
/*   Updated: 2024/04/05 21:27:34 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContacts(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
	if (_totalContacts == 8)
		std::cout << "PhoneBook is full. The oldest contact will be replaced." << std::endl;

	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	while (firstName.empty())
	{
		std::cout << "First name cannot be empty. Please enter first name: ";
		std::getline(std::cin, firstName);
	}

	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	while (lastName.empty())
	{
		std::cout << "Last name cannot be empty. Please enter last name: ";
		std::getline(std::cin, lastName);
	}

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	while (nickname.empty())
	{
		std::cout << "Nickname cannot be empty. Please enter nickname: ";
		std::getline(std::cin, nickname);
	}

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.empty())
	{
		std::cout << "Phone number cannot be empty. Please enter phone number: ";
		std::getline(std::cin, phoneNumber);
	}

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	while (darkestSecret.empty())
	{
		std::cout << "Darkest secret cannot be empty. Please enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
	}

	Contact newContact;
	newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);

	int index = _totalContacts % 8;
	_contacts[index] = newContact;
	if (_totalContacts < 8)
		_totalContacts++;
}

PhoneBook::searchContact(void) const
{
}
