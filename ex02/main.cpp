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
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
	std::cout << MAG << "[---------- sign form tests ----------]" << RESET << std::endl;
	std::cout << YEL << "[---------- Shrubbery ----------]" << RESET << std::endl;

	Bureaucrat HighB("HighB", 6);
	Bureaucrat LowB("LowB", 150);
	ShrubberyCreationForm shrubbery("Eichhoernchen");
	HighB.executeForm(shrubbery);
	HighB.signForm(shrubbery);
	HighB.executeForm(shrubbery);
	LowB.executeForm(shrubbery);

	std::cout << YEL << "[---------- Robotomy ----------]" << RESET << std::endl;
	RobotomyRequestForm robot("Streichholzschaechtelchen");
	HighB.executeForm(robot);
	HighB.signForm(robot);
	HighB.executeForm(robot);
	LowB.executeForm(robot);

	std::cout << YEL << "[---------- Presidential ----------]" << RESET << std::endl;
	PresidentialPardonForm president("Specht");
	HighB.executeForm(president);
	HighB.signForm(president);
	HighB.executeForm(president);
	std::cout << "incrementing grade of " << HighB.getName() << std::endl;
	HighB.incrementGrade();
	HighB.executeForm(president);

	std::cout << MAG << "[---------- copy tests ----------]" << RESET << std::endl;
	ShrubberyCreationForm New;
	ShrubberyCreationForm copy(shrubbery);
	std::cout << copy;
	copy = New;
	std::cout << copy;
	HighB.signForm(New);
	std::cout << New;
	std::cout << copy;
	return (0);
}
