/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:04:52 by isromero          #+#    #+#             */
/*   Updated: 2023/09/14 21:04:52 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator=(const Fixed &other)
{
    this->value = other.value;
    return *this;
}

int Fixed::getRawBits() const
{
    return this->value;
}

void Fixed::setRawBits(int raw)
{
    this->value = raw;
}