/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:54:50 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 08:40:02 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	// Creación de 100 animales como pide en el enunciado, 50 Cats y 50 Dogs y liberación de memoria
	Animal **animals = new Animal *[100];
	for (int i = 0; i < 50; ++i)
		animals[i] = new Dog();
	for (int i = 50; i < 100; ++i)
		animals[i] = new Cat();
	for (int i = 0; i < 100; ++i)
		delete animals[i];
	delete[] animals;

	// Verificación de copias profundas
	/* // Creación del Cat original y cambio de una idea
	Cat originalCat;
	originalCat.changeIdea("I love sleeping", 0);
	std::cout << "Original Cat's Brain after changing one idea:" << std::endl;
	originalCat.printBrain();

	// Creación de copiedCat usando el constructor de copia
	Cat copiedCat = originalCat;
	std::cout << "Copied Cat's Brain after copy constructor:" << std::endl;
	copiedCat.printBrain();

	// Cambio de una idea en el originalCat para demostrar que las copias son profundas
	originalCat.changeIdea("I love eating", 0);
	std::cout << "Original Cat's Brain after changing another idea:" << std::endl;
	originalCat.printBrain();
	std::cout << "Copied Cat's Brain after changing original idea:" << std::endl;
	copiedCat.printBrain();

	// Creación de otro Cat usando el constructor por defecto usando el operador de asignación
	Cat anotherCat;
	anotherCat = originalCat;
	std::cout << "Another Cat's Brain after assignment operator:" << std::endl;
	anotherCat.printBrain();

	// Cambio de una idea en anotherCat para demostrar independencia
	anotherCat.changeIdea("I love climbing", 0);
	std::cout << "Another Cat's Brain after changing one idea:" << std::endl;
	anotherCat.printBrain();
	std::cout << "Original Cat's Brain after changing another idea:" << std::endl;
	originalCat.printBrain();

	// Verificación final de los estados para confirmar independencia completa.
	std::cout << "Final State of Original Cat's Brain:" << std::endl;
	originalCat.printBrain();
	std::cout << "Final State of Copied Cat's Brain:" << std::endl;
	copiedCat.printBrain();
	std::cout << "Final State of = Operator Cat's Brain:" << std::endl;
	anotherCat.printBrain(); */
	return (0);
}
