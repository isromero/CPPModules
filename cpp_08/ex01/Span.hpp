/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:53:29 by isromero          #+#    #+#             */
/*   Updated: 2024/06/19 21:15:01 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class Span
{
public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int n);
	int shortestSpan() const;
	int largestSpan() const;
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

private:
	unsigned int _N;
	std::vector<int> _vec;
};

#endif
