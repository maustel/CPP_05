/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:36:40 by maustel           #+#    #+#             */
/*   Updated: 2025/03/25 10:36:40 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <iostream>

class Form
{
	private:
	const std::string _name;
	bool _is_signed;
	const int _grade_sign;
	const int _grade_execute;

	public:
	Form(const std::string name, int grade_sign, int grade_ex);
	~Form();
	Form(const Form& other);
	Form& operator=(const Form& other);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
