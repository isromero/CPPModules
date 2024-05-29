/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:50:27 by isromero          #+#    #+#             */
/*   Updated: 2024/05/29 21:20:30 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _array(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_array = new T[other._size];
		this->_size = other._size;
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
T &Array<T>::operator[](unsigned int index) const
{
	// Se handlea la excepción desde el main, aquí solo de lanza la excepción
	if (index >= this->_size)
		throw std::out_of_range("Index is out of bounds");
	return this->_array[index];
}
