/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:29:03 by isromero          #+#    #+#             */
/*   Updated: 2023/09/05 12:29:03 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
public:
  Contact() : index(-1), firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

  int         getIndex() const { return index; }
  std::string getFirstName() const { return firstName; }
  std::string getLastName() const { return lastName; }
  std::string getNickname() const { return nickname; }
  std::string getPhoneNumber() const { return phoneNumber; }
  std::string getDarkestSecret() const { return darkestSecret; }

  void setIndex(int i) { index = i; }
  void setFirstName(const std::string &first) { firstName = first; }
  void setLastName(const std::string &last) { lastName = last; }
  void setNickname(const std::string &nick) { nickname = nick; }
  void setPhoneNumber(const std::string &phone) { phoneNumber = phone; }
  void setDarkestSecret(const std::string &secret) { darkestSecret = secret; }

private:
  int         index;
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
};

#endif