/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:28:50 by matoledo          #+#    #+#             */
/*   Updated: 2026/02/04 16:31:30 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() { };

Contact::Contact(int pn, std::string fn, std::string ln, std::string nn, std::string ds)
{
    phoneNumber = pn;
    firstName = fn;
    lastName = ln;
    nickname = nn;
    darkestSecret = ds;
};