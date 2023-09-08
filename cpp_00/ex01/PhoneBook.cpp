/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:37:15 by isromero          #+#    #+#             */
/*   Updated: 2023/09/03 20:37:15 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::Add()
{
  Contact contact;
  std::string input;

  std::cout << "First Name: ";
  if (!std::getline(std::cin, input))
    return;

  contact.setFirstName(input);

  std::cout << "Last Name: ";
  if (!std::getline(std::cin, input))
    return;

  contact.setLastName(input);

  std::cout << "Nickname: ";
  if (!std::getline(std::cin, input))
    return;

  contact.setNickname(input);

  std::cout << "Phone Number: ";
  if (!std::getline(std::cin, input))
    return;

  contact.setPhoneNumber(input);

  std::cout << "Darkest Secret: ";
  if (!std::getline(std::cin, input))
    return;

  contact.setDarkestSecret(input);

  if (currentContactIndex < maxContacts)
  {
    contact.setIndex(currentContactIndex);
    contacts[currentContactIndex] = contact;
    currentContactIndex++;
  }
  else
  {
    contact.setIndex(currentContactIndex % maxContacts);
    contacts[currentContactIndex % maxContacts] = contact;
    currentContactIndex++;
  }
}

void PhoneBook::PrintContacts()
{
  std::cout << std::setw(10) << "index"
            << " | "
            << std::setw(10) << "first name"
            << " | "
            << std::setw(10) << "last name"
            << " | "
            << std::setw(10) << "last name"
            << " | " << std::endl;

  for (int i = 0; i < maxContacts; i++)
  {
    const Contact &contact = contacts[i];

    if (contact.getIndex() >= 0)
    {
      int index = contact.getIndex();
      std::string firstName = contact.getFirstName();
      std::string lastName = contact.getLastName();
      std::string nickname = contact.getNickname();

      if (firstName.length() > 10)
        firstName = firstName.substr(0, 9) + ".";
      if (lastName.length() > 10)
        lastName = lastName.substr(0, 9) + ".";
      if (nickname.length() > 10)
        nickname = nickname.substr(0, 9) + ".";

      std::cout << std::setw(10) << std::right << index << " | "
                << std::setw(10) << std::right << firstName << " | "
                << std::setw(10) << std::right << lastName << " | "
                << std::setw(10) << std::right << nickname << std::endl;
    }
  }
}

void PhoneBook::PrintSpecificContact(int i)
{
  const Contact &contact = contacts[i];

  if (i >= 0 && i <= currentContactIndex)
  {
    std::cout << "First Name: " << contact.getFirstName() << std::endl
              << "Last Name: " << contact.getLastName() << std::endl
              << "Nickname: " << contact.getNickname() << std::endl
              << "Phone Number: " << contact.getPhoneNumber() << std::endl
              << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
  }
  else
    std::cerr << "The index of the Contact doesn't exist" << std::endl;
  std::cin.clear();
  std::cin.ignore(1000, '\n');
}

void PhoneBook::Search()
{
  Contact contact;
  int i = 0;

  std::cout << "You are going to search a specific contact" << std::endl;
  std::cout << "This is your agenda right now:" << std::endl;
  PrintContacts();
  std::cout << "Insert the index of the contact that you want to search: ";

  if (!(std::cin >> i))
  {
    std::cout << "Invalid input. Please enter a valid index." << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }
  else if (i >= 0 && i <= currentContactIndex)
    PrintSpecificContact(i);
  else
  {
    std::cout << "Invalid index. The contact does not exist." << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }
}
