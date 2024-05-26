/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:25:14 by isromero          #+#    #+#             */
/*   Updated: 2024/05/26 14:05:47 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") {}

Contact::~Contact() {}

void Contact::setContact(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber, const std::string &darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

const std::string &Contact::getFirstName() const
{
	return (this->_firstName);
}

const std::string &Contact::getLastName() const
{
	return (this->_lastName);
}

const std::string &Contact::getNickname() const
{
	return (this->_nickname);
}
