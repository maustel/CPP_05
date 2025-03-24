/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:51:59 by maustel           #+#    #+#             */
/*   Updated: 2025/03/24 17:10:49 by maustel          ###   ########.fr       */
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

#endif
