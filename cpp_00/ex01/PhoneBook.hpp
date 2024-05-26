/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:25:19 by isromero          #+#    #+#             */
/*   Updated: 2024/05/26 14:23:49 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact() const;

private:
	Contact _contacts[8];
	int _totalContacts;
	int _index;
};

#endif
