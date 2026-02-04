/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:35:20 by matoledo          #+#    #+#             */
/*   Updated: 2026/02/04 16:35:25 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

template <typename T>

T AddValue(std::string request)
{
    T value;

    while (true)
    {
        std::cout << request;
        if (std::cin >> value)
            break;
        std::cout << "Entrada inválida\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return value;
}

Contact	CreateContact()
{
	int			phoneNumber;
	std::string	firstName;
	std::string	lastName;
	std::string nickname;
	std::string	darkestSecret;

	phoneNumber = AddValue<int>("Introduce tu número de telefono\n");
	firstName = AddValue<std::string>("Introduce tu nombre\n");
	lastName = AddValue<std::string>("Introduce tu apellido\n");
	nickname = AddValue<std::string>("Introduce tu mote\n");
	darkestSecret = AddValue<std::string>("Introduce tu secreto más oscuro\n");
	
	Contact contact(phoneNumber, firstName, lastName, nickname, darkestSecret);
	std::cout << "Contacto añadido al telefono\n";
	return (contact);
}

int	main(int argc, char *argv[])
{
	std::string	command;
	PhoneBook	Phone;
	while (1)
	{
		std::cout << "¿Que quieres hacer?: Añadir (ADD), Buscar (SEARCH), Salir (EXIT)\n";
		std::cin >> command;
		if (command == "ADD")
			Phone.AddContact(CreateContact());
		if (command == "SEARCH")
			Phone.SearchContact();
		if (command == "EXIT")
			break ;
	}
	return (0);
}