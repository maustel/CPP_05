/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:36:40 by maustel           #+#    #+#             */
/*   Updated: 2025/03/25 10:36:40 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_HPP__
# define __AFORM_HPP__

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
	const std::string	_name;
	bool				_is_signed;
	const int			_grade_sign;
	const int			_grade_execute;

	public:
	//---------------------canonical-------------------------
	AForm();
	AForm(const std::string name, int grade_sign, int grade_ex);
	~AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);

	//---------------------getters-------------------------
	const std::string getName() const;
	bool getSignedStatus() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	//---------------------setters-------------------------
	// void setSignedStatus(bool);

	//---------------------other members-------------------------
	void checkGradeExec(const Bureaucrat& bureaucrat) const;
	void checkSigned() const;
	void beSigned(Bureaucrat& bureaucrat);
	void execute(Bureaucrat const& executor) const;
	virtual void performExecution() const = 0;

	//---------------------exceptions-------------------------
	class GradeTooLowException: public std::exception
	{
		public:
		const char* what() const noexcept;
	};

	class FormNotSignedException: public std::exception
	{
		public:
		const char* what() const noexcept;
	};
};

//---------------------other functions-------------------------
std::ostream& operator<<(std::ostream& os, const AForm& Aform);

// colors
#define BLK "\e[0;30m"    // Black
#define RED "\e[0;31m"    // Red
#define GRN "\e[0;32m"    // Green
#define YEL "\e[0;33m"    // Yellow
#define BLU "\e[0;34m"    // Blue
#define MAG "\e[0;35m"    // Magenta
#define CYN "\e[0;36m"    // Cyan
#define WHT "\e[0;37m"    // White
#define RESET "\e[0m"	 // Reset color

#endif
