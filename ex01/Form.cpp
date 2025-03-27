/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:44:01 by maustel           #+#    #+#             */
/*   Updated: 2025/03/27 14:54:16 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//--------------------------------------------------------------canonical
Form::Form():
	_name("DefaultForm"),
	_is_signed(false),
	_grade_sign(150),
	_grade_execute(150)
{}

Form::Form(const std::string name, int grade_sign, int grade_ex):
	_name(name),
	_is_signed(false),
	_grade_sign(grade_sign),
	_grade_execute(grade_ex)
{}

Form::~Form()
{}

Form::Form(const Form &other):
	_name(other._name),
	_is_signed(other._is_signed),
	_grade_sign(other._grade_sign),
	_grade_execute(other._grade_execute)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	std::cout << RED << "No assignment of const variables!" << RESET << std::endl;
	return (*this);
}

//--------------------------------------------------------------member functions
const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSignedStatus() const
{
	return (this->_is_signed);
}

int Form::getGradeSign() const
{
	return (this->_grade_sign);
}

int Form::getGradeExecute() const
{
	return (this->_grade_execute);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_sign)
		throw (GradeTooLowException());
	else
	{
		this->_is_signed = true;
		std::cout << GRN << bureaucrat.getName() << " has signed form " << this->getName() << RESET << std::endl;
	}
}

//--------------------------------------------------------------exceptions
const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Form exception: bureaucrat grade too low!");
}

//--------------------------------------------------------------other
std::ostream &operator<<(std::ostream &os, const Form& form)
{
	os << form.getName()
		<< " is " << (form.getSignedStatus() == true ? "signed" : "not signed")
		<< ", grade to sign " << form.getGradeSign()
		<< ", grade to execute " << form.getGradeExecute() << std::endl;
	return (os);
}
