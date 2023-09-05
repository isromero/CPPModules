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
#include "Contact.hpp"

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