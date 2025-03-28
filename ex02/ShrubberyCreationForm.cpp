/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:16:12 by maustel           #+#    #+#             */
/*   Updated: 2025/03/28 11:25:14 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//--------------------------------------------------------------canonical
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("DefaultTarget")
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other)
{
	if (this != &other)
		this->_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
			this->_target = other._target;
	}
	return (*this);
}

//--------------------------------------------------------------member functions

void ShrubberyCreationForm::performExecution() const
{
	std::string		filename = this->_target + "_shrubbery";
	std::ofstream file(filename);

	if (file.is_open())
	{
		file << "       /^\\             *                   -\n";
		file << "     /     \\          ***                 ---\n";
		file << "   {|       |}       *****               -----\n";
		file << "    \\       /       *******             -------\n";
		file << "      \\\\ //        *********           ---------\n";
		file << "        |         ***********         -----------\n";
		file << "       -|-       *************       -------------\n";
		file << "      // \\\\            |                   |       \n";
		file <<"            *                   -\n";
        file <<"           ***                 ---\n";
        file <<"          *****               -----\n";
        file <<"         *******             -------\n";
        file <<"        *********           ---------\n";
        file <<"       ***********         -----------\n";
        file <<"      *************       -------------\n";
        file <<"            |                   |\n";
		std::cout << BLU << this->_target << " shrubbery has been created" << RESET << std::endl;

	}
	else
	{
		std::cerr << RED << "Error: couldn't open file" << RESET << std::endl;
	}
	file.close();
}
