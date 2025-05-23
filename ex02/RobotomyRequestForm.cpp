/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:10:57 by maustel           #+#    #+#             */
/*   Updated: 2025/03/28 10:10:57 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//--------------------------------------------------------------canonical
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("DefaultTarget")
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other)
{
	if (this != &other)
		this->_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
			this->_target = other._target;
	}
	return (*this);
}

//--------------------------------------------------------------member functions

void RobotomyRequestForm::performExecution() const
{
	std::cout << BLU << "<<<<<< DRILLING<>NOISE >>>>>>>" << RESET << std::endl;
	srand(time(0));
    if(rand() % 2 == 0)
        std::cout << BLU << this->_target << " has been robotomized successfully!" << RESET << std::endl;
    else
        std::cout << BLU << this->_target << " robotomy failed"  << RESET << std::endl;
}
