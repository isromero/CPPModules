/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:25:19 by isromero          #+#    #+#             */
/*   Updated: 2024/04/08 16:02:37 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void addContact(void);
	void searchContact(void) const;

private:
	Contact _contacts[8];
	int _totalContacts;
};

#endif
