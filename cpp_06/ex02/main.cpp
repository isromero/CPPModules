/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:05:59 by isromero          #+#    #+#             */
/*   Updated: 2024/05/25 14:02:40 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base *p)
{
	std::cout << p->getName() << std::endl;
}

void identify(Base &p)
{
	std::cout << p.getName() << std::endl;
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // Inicializamos el generador de números aleatorio
	// En el caso de no hacerlo siempre que ejecutemos el programa se genera siempre la misma secuencia

	Base *p = NULL;

	switch (rand() % 3)
	{
	case 0:
		p = new A();
		break;
	case 1:
		p = new B();
		break;
	case 2:
		p = new C();
	default:
		break;
	}
	identify(p);
	identify(*p);

	delete p;
	return (0);
}
