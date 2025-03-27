/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:35:55 by maustel           #+#    #+#             */
/*   Updated: 2025/03/27 10:35:55 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

# include "AForm.hpp"
# include <iostream>

class PresidentialPardonForm: public AForm
{
	private:
	std::string _target;
	public:
	//----------------------- canonical form -----------------------
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	//----------------------- member functions -----------------------
	void execute(Bureaucrat const & executor) const;
};

#endif
