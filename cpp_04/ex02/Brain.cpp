/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:54:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 08:20:18 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = "Default idea";
	std::cout << "Brain was created" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];
	std::cout << "Brain copy was created" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->_ideas[i] = other._ideas[i];
	}
	std::cout
		<< "Brain ideas: " << this->_ideas << " = "
		<< "Brain ideas: " << this->_ideas << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain was destroyed" << std::endl;
}

void Brain::changeIdea(const std::string &newIdea, int index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = newIdea;
}

void Brain::printBrain() const
{
	for (int i = 0; i < 100; ++i)
		std::cout << "Idea " << i << ": " << this->_ideas[i] << std::endl;
}
