/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:08:35 by matoledo          #+#    #+#             */
/*   Updated: 2026/01/28 19:08:38 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

std::string	UpperCaser(std::string word)
{
	std::string	return_word;
	int			i;

	i = 0;
	while (word[i])
	{
		return_word[i] = toupper(word[i]);
		std::cout << return_word[i];
		i++;
	}
	return (return_word);
}

int main(int argc, char *argv[])
{
    int i;

	i = 1;
	if (argc > 1)
	{
		while (i <= argc - 1)
		{
			std::cout << UpperCaser(argv[i]);
			i++;
		}
		std::cout << "\n";
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return (0);
}