/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:44:09 by isromero          #+#    #+#             */
/*   Updated: 2024/06/17 20:44:09 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(2), _vec(0) {}

Span::Span(unsigned int N) : _N(N), _vec(0) {}

Span::Span(const Span &other) : _N(other._N), _vec(other._N) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_vec = other._vec;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (this->_vec.size() < this->_N)
		_vec.push_back(n);
	else
		throw std::exception();
}

int Span::shortestSpan() const
{
	if (this->_vec.size() < 2)
		throw std::logic_error("Not enough elements to calculate the span");

	int minDist = INT_MAX;

	for (std::vector<int>::const_iterator it1 = this->_vec.begin(); it1 != this->_vec.end(); ++it1)
	{
		for (std::vector<int>::const_iterator it2 = it1 + 1; it2 != this->_vec.end(); ++it2)
		{
			int dist = std::abs(*it2 - *it1);
			if (dist < minDist)
				minDist = dist;
		}
	}

	return (minDist);
}

int Span::largestSpan() const
{
	if (this->_vec.size() < 2)
		throw std::logic_error("Not enough elements to calculate the span");
	return (std::distance(std::min_element(this->_vec.begin(), this->_vec.end()), std::max_element(this->_vec.begin(), this->_vec.end())));
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > static_cast<int>(this->_N - this->_vec.size()))
		throw std::logic_error("Not enough space to add the range");
	this->_vec.insert(this->_vec.end(), begin, end);
}
