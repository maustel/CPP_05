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
	Bureaucrat David("David", 150);
	std::cout << David;

	//-----------------------------------copy constructer / Assignment operator tests
	std::cout << MAG << "[copy constructer / Assignment operator tests]" << RESET << std::endl;
	Bureaucrat Other(David);
	Bureaucrat Walter("Walter", 1);
	std::cout << Other;
	std::cout << Walter;
	Other = Walter;
	std::cout << Other;
	// ----------------------------------increment works
	try
	{
		std::cout << MAG << "[Trying to increment grade David]" << RESET << std::endl;
		David.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET <<  std::endl;
	}
	std::cout << David;

	// ----------------------------------decrement works
	try
	{
		std::cout << MAG << "[Trying to decrement grade David]" << RESET << std::endl;
		David.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << David;

	// ----------------------------------decrement works NOT
	try
	{
		std::cout << MAG << "[Trying to decrement grade David]" << RESET << std::endl;
		David.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	//------------------------------------constructor works not
	try
	{
		std::cout << MAG << "[Trying to create MadameHigh]" << RESET << std::endl;
		Bureaucrat MadameHigh("MadameHigh", 0);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	//------------------------------------constructor works not
	try
	{
		std::cout << MAG << "[Trying to create MadameLow]" << RESET << std::endl;
		Bureaucrat MadameLow("MadameLow", 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return (0);
}
