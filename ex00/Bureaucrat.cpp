/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:03:43 by maustel           #+#    #+#             */
/*   Updated: 2025/03/20 17:23:29 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//-------------------------------------------canonical----------------------------

Bureaucrat::Bureaucrat():_name(NULL), _grade(150)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name), _grade(grade)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_grade = other._grade;
	std::cout << "Assignment operator: Name cannot be changed." << this->_name << " stays the same." << std::endl;
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
	this->_grade--;
	//DO SOME CHECKS AND THROW ERROR
}

void Bureaucrat::decrementGrade()
{
	this->_grade++;
	//DO SOME CHECKS AND THROW ERROR
}

//----------------------------------------------others-----------------------------------------

std::ostream &operator<<(std::__1::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
}
