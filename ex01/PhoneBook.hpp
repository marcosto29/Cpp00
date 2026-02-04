/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:27:42 by matoledo          #+#    #+#             */
/*   Updated: 2026/02/04 16:35:20 by matoledo         ###   ########.fr       */
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

		Contact ();
		Contact (int pn, std::string fn, std::string ln, std::string nn, std::string ds);
};

class PhoneBook 
{
	public:
		int			size;
		Contact		contacts[8];
		
		PhoneBook();
		void	AddContact(Contact contact);
		void	SearchContact();
	private:
		void	DisplayContact(int index);
		std::string	WriteWord(std::string string);
		void	DisplayAllContacts();
};
