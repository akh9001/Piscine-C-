/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:29:50 by akhalidy          #+#    #+#             */
/*   Updated: 2021/10/04 15:31:48 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	char	buff[500];
	int		age;
	char	permission;

	std::cout << "Hello Asmaa!" <<std::endl;
	std::cout << "Input a world : ";
	std::cin >> buff >> age >> permission;
	std::cout << "You entered: [" << buff << "]"<< "[" << age << "]"<< "[" << permission << "]"<< std::endl;
}
