/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:51:59 by maustel           #+#    #+#             */
/*   Updated: 2025/03/25 16:11:37 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
	const std::string 	_name;
	int					_grade;

	public:
	//---------------------canonical-------------------------
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	//---------------------member functions-------------------------
	const std::string getName() const;
	int	getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void checkGrade();

	void signForm(Form& form);

	//---------------------exceptions-------------------------
	class GradeTooHighException: public std::exception
	{
		public:
		const char* what() const noexcept;
	};

	class GradeTooLowException: public std::exception
	{
		public:
		const char* what() const noexcept;
	};
};

//---------------------others-------------------------
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

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
