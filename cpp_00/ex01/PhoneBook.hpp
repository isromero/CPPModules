/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:37:13 by isromero          #+#    #+#             */
/*   Updated: 2023/09/03 20:37:13 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
public:
  Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}
  Contact(const std::string &first, const std::string &last, const std::string &nick,
          const std::string &phone, const std::string &secret)
      : firstName(first), lastName(last), nickname(nick), phoneNumber(phone), darkestSecret(secret) {}

  std::string getFirstName() const { return firstName; }
  std::string getLastName() const { return lastName; }
  std::string getNickname() const { return nickname; }
  std::string getPhoneNumber() const { return phoneNumber; }
  std::string getDarkestSecret() const { return darkestSecret; }

  void setFirstName(const std::string &first) { firstName = first; }
  void setLastName(const std::string &last) { lastName = last; }
  void setNickname(const std::string &nick) { nickname = nick; }
  void setPhoneNumber(const std::string &phone) { phoneNumber = phone; }
  void setDarkestSecret(const std::string &secret) { darkestSecret = secret; }

private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
};


class PhoneBook {
  public:
    PhoneBook() : currentContactIndex(0) {}
    void Add();
    void PrintContacts();
    void PrintSpecificContact(int i);
    void Search();

    int getCurrentContactIndex() const { return currentContactIndex; }

  private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int currentContactIndex;
};

#endif