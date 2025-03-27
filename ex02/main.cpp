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
#include "ShrubberyCreationForm.hpp"

int main ()
{
	//-----------------------------------constructor works
	std::cout << MAG << "[---------- sign form test works ----------]" << RESET << std::endl;

	Bureaucrat David("David", 13);
	ShrubberyCreationForm shrubbery("tree");
	David.executeForm(shrubbery);
	// shrubbery.execute(David);
	David.signForm(shrubbery);
	David.executeForm(shrubbery);


	//-----------------------------------copy constructer / Assignment operator tests
	std::cout << MAG << "[---------- copy constructer / Assignment operator tests ----------]" << RESET << std::endl;


	// ----------------------------------sign form works


	// ----------------------------------sign form works NOT
	std::cout << MAG << "[---------- sign form test works NOT ----------]" << RESET << std::endl;


	return (0);
}
