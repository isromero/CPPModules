/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:59:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/21 21:04:41 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T c(a);
	a = b;
	b = c;
}

template <typename T>
const T &min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
	return (a > b) ? a : b;
}

#endif
