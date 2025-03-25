/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:51:59 by maustel           #+#    #+#             */
/*   Updated: 2025/03/25 10:31:00 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
	const std::string 	_name;
	int					_grade;

	public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	const std::string getName() const;
	int	getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void checkGrade();

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
