/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:35:20 by matoledo          #+#    #+#             */
/*   Updated: 2026/01/31 17:35:03 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class Contact
{
	public:
		int			phoneNumber;
		std::string	firstName;
		std::string	lastName;
		std::string nickname;
		std::string	darkestSecret;
		
		Contact () { };
		Contact (int pn, std::string fn, std::string ln, std::string nn, std::string ds)
		{
			phoneNumber = pn;
			firstName = fn;
			lastName = ln;
			nickname = nn;
			darkestSecret = ds;
		};
};

class PhoneBook 
{
	public:
		int			size;
		Contact		contacts[8];
		
		PhoneBook() { 
			size = 0;
		};

		void	AddContact(Contact contact)
		{
			int	i;

			i = 0;
			if (size < 8)
			{
				contacts[size] = contact;
				size++;				
			}
			else
			{
				while (i < size - 1)
				{
					contacts[i] = contacts[i + 1];
					i++;
				}
				contacts[i] = contact;
			}
		}

		void	SearchContact()
		{
			int index;

			DisplayAllContacts();
			while (1)
			{
				std::cout << "Elige el ínice que quieres ver\n";
				if (std::cin >> index)
					break ;
				std::cout << "Respuesta incorrecta\n";
				std::cin.clear();
        		std::cin.ignore(10000, '\n');
			}
			DisplayContact(index);
		}
	private:
		void	DisplayContact(int index)
		{
			std::cout << "Phone number: " << contacts[index].phoneNumber << "\n"
					  << "first name: " << contacts[index].firstName << "\n"
					  << "last name: " << contacts[index].lastName << "\n"
					  << "nickname: " << contacts[index].nickname << "\n"
					  << "darkest secret: " << contacts[index].darkestSecret << "\n";
		}
		
		std::string	WriteWord(std::string string)
		{
			if (string.length() <= 10)
				return (string);
			return (string.substr(0, 9) + '.');
		}

		void	DisplayAllContacts()
		{
			int	i;

			i = 0;
			std::cout << std::setw(10) << WriteWord("index") << " | "
					  << std::setw(10) << WriteWord("first name") << " | "
					  << std::setw(10) << WriteWord("last name") << " | "
					  << std::setw(10) << WriteWord("nickname") << " |\n";
			while (i < size)
			{
				std::cout << std::setw(10) << i << " | "
				          << std::setw(10) << WriteWord(contacts[i].firstName) << " | "
				          << std::setw(10) << WriteWord(contacts[i].lastName) << " | "
				          << std::setw(10) << WriteWord(contacts[i].nickname) << " |\n";
				i++;
			}
		}
};

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