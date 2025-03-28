/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:44:01 by maustel           #+#    #+#             */
/*   Updated: 2025/03/27 10:16:29 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//--------------------------------------------------------------canonical
AForm::AForm():
	_name("DefaultAForm"),
	_is_signed(false),
	_grade_sign(150),
	_grade_execute(150)
{}

AForm::AForm(const std::string name, int grade_sign, int grade_ex):
	_name(name),
	_is_signed(false),
	_grade_sign(grade_sign),
	_grade_execute(grade_ex)
{}

AForm::~AForm()
{}

AForm::AForm(const AForm &other):
	_name(other._name),
	_is_signed(other._is_signed),
	_grade_sign(other._grade_sign),
	_grade_execute(other._grade_execute)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	std::cout << RED << "No assignment of const variables!" << RESET << std::endl;
	return (*this);
}

//--------------------------------------------------------------member functions
const std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSignedStatus() const
{
	return (this->_is_signed);
}

int AForm::getGradeSign() const
{
	return (this->_grade_sign);
}

int AForm::getGradeExecute() const
{
	return (this->_grade_execute);
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_sign)
		throw (GradeTooLowException());
	else
	{
		this->_is_signed = true;
		std::cout << GRN << bureaucrat.getName() << " has signed Aform " << this->getName() << RESET << std::endl;
	}
}

void AForm::checkGradeExec(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->_grade_execute)
		throw(GradeTooLowException());
}

void AForm::checkSigned() const
{
	if (!this->getSignedStatus())
		throw(FormNotSignedException());
}

void AForm::execute(Bureaucrat const& executor) const
{
	try
	{
		this->checkGradeExec(executor);
		this->checkSigned();
		this->performExecution();
		std::cout << GRN << executor.getName() << " executed " << this->getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << executor.getName() << " failed to execute form " << this->getName()
			<< " because of: " << e.what() << RESET << std::endl;
	}
}

//--------------------------------------------------------------exceptions
const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("AForm exception: bureaucrat grade too low!");
}

const char *AForm::FormNotSignedException::what() const noexcept
{
	return ("AForm exception: form is not signed yet!");
}

//--------------------------------------------------------------other
std::ostream &operator<<(std::ostream &os, const AForm& Aform)
{
	os << Aform.getName()
		<< " is " << (Aform.getSignedStatus() == true ? "signed" : "not signed")
		<< ", grade to sign " << Aform.getGradeSign()
		<< ", grade to execute " << Aform.getGradeExecute() << std::endl;
	return (os);
}
