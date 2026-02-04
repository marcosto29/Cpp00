/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:30:12 by matoledo          #+#    #+#             */
/*   Updated: 2026/02/04 16:35:15 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    size = 0;
};

void PhoneBook::AddContact(Contact contact)
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

void PhoneBook::SearchContact()
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

void PhoneBook::DisplayContact(int index)
{
    std::cout << "Phone number: " << contacts[index].phoneNumber << "\n"
                << "first name: " << contacts[index].firstName << "\n"
                << "last name: " << contacts[index].lastName << "\n"
                << "nickname: " << contacts[index].nickname << "\n"
                << "darkest secret: " << contacts[index].darkestSecret << "\n";
}

std::string PhoneBook::WriteWord(std::string string)
{
    if (string.length() <= 10)
        return (string);
    return (string.substr(0, 9) + '.');
}

void PhoneBook::DisplayAllContacts()
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
