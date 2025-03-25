/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:44:01 by maustel           #+#    #+#             */
/*   Updated: 2025/03/25 15:29:28 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//--------------------------------------------------------------canonical
Form::Form(const std::string name, int grade_sign, int grade_ex):
	_name(name),
	_grade_sign(grade_sign),
	_grade_execute(grade_ex),
	_is_signed(false)
{}

Form::~Form()
{}

Form::Form(const Form &other):
	_name(other._name),
	_grade_sign(other._grade_sign),
	_grade_execute(other._grade_execute),
	_is_signed(false)
{}

Form& Form::operator=(const Form& other)
{
	std::cout << RED << "No assignment of const variables and _is_signed flag!" << RESET << std::endl;
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

void Form::beSigned(const Bureaucrat& bureaucrat)
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
const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Error: Grade too high!");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Error: Grade too low!");
}

//--------------------------------------------------------------other
std::ostream& operator<<(std::ostream os, const Form& form)
{
	os << form.getName()
		<< " is " << (form.getSignedStatus() == true ? "signed" : "not signed")
		<< ", grade to sign " << form.getGradeSign()
		<< ", grade to execute " << form.getGradeExecute() << std::endl;
	return (os);
}
