/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:54:50 by isromero          #+#    #+#             */
/*   Updated: 2024/04/28 14:46:43 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	/* const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;

	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *j2 = new WrongCat();

	j2->makeSound(); // No emite su sonido ya que no utilizamos virtual en WrongAnimal
					 // Y a través de puntero/referencia el polimorfismo es necesario.
					 // Por lo que si no utilizas virtual nunca funcionará así.
	meta2->makeSound();

	delete j2;
	delete meta2;

	Cat notPolymorphismCat; // Sin virtual podríamos acceder si no es
							// un puntero, sino el objeto en sí mismo a
							// su propia función

	notPolymorphismCat.makeSound(); */

	Animal **animals = new Animal *[100];

	for (int i = 0; i < 50; i++)
		animals[i] = new Dog();
	for (int i = 50; i < 100; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 100; i++)
		delete animals[i];
	delete[] animals;
	return (0);
}
