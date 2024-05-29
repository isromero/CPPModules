/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:59:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/21 21:04:41 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array<T> &other);
	Array &operator=(const Array<T> &other);
	T &operator[](unsigned int index) const;
	~Array();

	unsigned int size() const;

private:
	T *_array;
	unsigned int _size;
};

#include "Array.tpp" // Necesario ponerlo al final para que el compilador pueda tener acceso completo a las definiciones de template

#endif
