/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:46:48 by isromero          #+#    #+#             */
/*   Updated: 2024/04/17 21:17:29 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const intNum) : _fixedPointValue(intNum << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floatingPointNum) : _fixedPointValue(roundf(floatingPointNum * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other._fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

// Hacemos que cada vez que utilicemos '<<' con la clase Fixed
// directamente ya esté transformado en float con toFloat().
// Evitando así acceder todo el rato a esa función en cada '<<'
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{

	os << fixed.toFloat();
	return (os);
}
