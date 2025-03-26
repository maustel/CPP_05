/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:18:50 by maustel           #+#    #+#             */
/*   Updated: 2025/03/24 17:18:50 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
	//-----------------------------------constructor works
	std::cout << MAG << "[---------- Constructer tests ----------]" << RESET << std::endl;

	Bureaucrat David("David", 150);
	std::cout << David;

	Form DocA("DocA", 1, 1);
	std::cout << DocA;

	Form Default;
	std::cout << Default;
	std::cout << std::endl;

	//-----------------------------------copy constructer / Assignment operator tests
	std::cout << MAG << "[---------- copy constructer / Assignment operator tests ----------]" << RESET << std::endl;

	Form Other(DocA);
	std::cout << Other;

	Other = Default;
	std::cout << Other;
	std::cout << std::endl;

	// ----------------------------------sign form works
	std::cout << MAG << "[---------- sign form test works ----------]" << RESET << std::endl;

	David.signForm(Default);
	std::cout << Default;
	std::cout << std::endl;
	
	// ----------------------------------sign form works NOT
	std::cout << MAG << "[---------- sign form test works NOT ----------]" << RESET << std::endl;

	David.signForm(DocA);
	std::cout << DocA;
	std::cout << std::endl;

	return (0);
}
