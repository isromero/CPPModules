/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:05:59 by isromero          #+#    #+#             */
/*   Updated: 2024/07/14 17:35:20 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void identify(Base *p) // Cuando falla un cast con punteros devuelve NULL por lo que no tiene sentido hacer un try-catch
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p) // Cuando falla un cast con referencias devuelve una excepción por lo que es necesario hacer un try-catch
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

Base *generate(void)
{
	switch (std::rand() % 3) // Genera un número aleatorio entre 0 y 2
	{
	case (0):
		return (new A());
		break;
	case (1):
		return (new B());
		break;
	case (2):
		return (new C());
		break;
	default:
		return (new A());
		break;
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(time(0))); // Inicializamos el generador de números aleatorio
											   // En el caso de no hacerlo siempre que ejecutemos el programa se genera siempre la misma secuencia
	for (int i = 0; i < 10; i++)
	{
		Base *p = generate();
		std::cout << "Test " << i + 1 << ":" << std::endl;
		identify(p);
		identify(*p);
		delete p;
		std::cout << std::endl;
	}
	return (0);
}
