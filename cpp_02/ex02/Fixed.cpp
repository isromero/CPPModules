/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:46:48 by isromero          #+#    #+#             */
/*   Updated: 2024/04/22 21:20:27 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(int const intNum) : _fixedPointValue(intNum << _fractionalBits)
{
}

Fixed::Fixed(float const floatingPointNum) : _fixedPointValue(roundf(floatingPointNum * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		_fixedPointValue = rhs._fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fixedPointValue > rhs._fixedPointValue);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_fixedPointValue < rhs._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fixedPointValue >= rhs._fixedPointValue);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fixedPointValue <= rhs._fixedPointValue);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_fixedPointValue == rhs._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_fixedPointValue != rhs._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result._fixedPointValue = this->_fixedPointValue + rhs._fixedPointValue;
	return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result._fixedPointValue = this->_fixedPointValue - rhs._fixedPointValue;
	return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	result._fixedPointValue = (this->_fixedPointValue * rhs._fixedPointValue) >> this->_fractionalBits;
	return (result);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed result;
	if (rhs._fixedPointValue != 0)
		result._fixedPointValue = (this->_fixedPointValue << this->_fractionalBits) / rhs._fixedPointValue;
	else
		result._fixedPointValue = 0;
	return result;
}

Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedPointValue++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedPointValue--;
	return (temp);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return (lhs > rhs ? lhs : rhs);
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	return (lhs > rhs ? lhs : rhs);
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

float Fixed::toFloat() const
{
	return (static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits));
}

int Fixed::toInt() const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
