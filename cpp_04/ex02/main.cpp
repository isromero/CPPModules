/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:54:50 by isromero          #+#    #+#             */
/*   Updated: 2024/05/02 09:08:57 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// Esto dará error de compilación:
	// AAnimal animal;

	// Esto dará también error:
	// AAnimal *animal = new AAnimal();

	// Dan error ya que estamos instanciando una clase abstracta, tiene un método puro virtual
	// (no tiene implementación propia) y no se puede instanciar directamente.

	// Lo que si podemos hacer ahora es instanciar a sus clases derivadas que si tienen implementación:
	AAnimal *dog = new Dog();
	AAnimal *cat = new Cat();

	dog->makeSound();
	cat->makeSound();
	return (0);
}
