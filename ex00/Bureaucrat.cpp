/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:03:43 by maustel           #+#    #+#             */
/*   Updated: 2025/03/25 11:34:42 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//-------------------------------------------canonical----------------------------

Bureaucrat::Bureaucrat():_name(NULL), _grade(150)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name), _grade(grade)
{
	this->checkGrade();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_grade = other._grade;
	std::cout << "Assignment operator: Name cannot be changed since it is constant. " << this->_name << " stays the same." << std::endl;
	return (*this);
}

//---------------------------------------------member functions----------------------------

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw (GradeTooHighException());
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw (GradeTooLowException());
	else
		this->_grade++;
}

void Bureaucrat::checkGrade()
{
	if (this->_grade > 150)
		throw (GradeTooLowException());
	else if (this->_grade < 1)
		throw (GradeTooHighException());
}

//----------------------------------------------exceptions-----------------------------------------
const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Error: Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Error: Grade too low!");
}

//----------------------------------------------others-----------------------------------------

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}
