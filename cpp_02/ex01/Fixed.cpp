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

int Fixed::getRawBits() const
{
  return this->value;
}

void Fixed::setRawBits(int raw)
{
  this->value = raw;
}

float Fixed::toFloat(void) const
{
  return static_cast<float>(this->getRawBits()) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
  return this->value >> fractionalBits;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &value)
{
  return stream << value.toFloat();
}
