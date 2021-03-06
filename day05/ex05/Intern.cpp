/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:46:05 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/09 17:18:51 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
// Constructor
Intern::Intern(void)
{
    return;
}
// Destructor
Intern::~Intern(void) {}

// Member functions
Form *Intern::robotomyRequestForm(std::string const &target)
{
    return new RobotomyRequestForm(target);
}
Form *Intern::shrubberyCreationForm(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}
Form *Intern::presidentialPardonForm(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(std::string form, std::string target)
{
    unsigned int i = 0;

    typedef Form *(Intern::*ChooseForm)(std::string const &target);
    ChooseForm createForm[3] = {
        &Intern::robotomyRequestForm,
        &Intern::shrubberyCreationForm,
        &Intern::presidentialPardonForm // PresidentialPardonForm(),
    };
    std::string commands[3] = {
        "robotomy request",
        "shrubbery request",
        "presidential pardon"};
    // try {

    while (i < (sizeof(commands) / sizeof(*commands)))
    {
        if (commands[i] == form)
        {
             std::cout << COLOR_GREEN << "Intern creates " << COLOR_RESET << std::endl
                << form << std::endl;
            return (this->*(createForm[i]))(target);
        }
        i++;
    }
    // Form *formulaire = new Form(0);
        // return formtmp;
    // }
    // catch (std::exception &e){
        // std::cout << e.what() << std::endl;
    // }
    std::cout << COLOR_RED << "Itern failed to create " << COLOR_RESET << form << std::endl;
    return (NULL);
}

// Operators
Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return *this;
}


Intern::NoFormAvailableException::NoFormAvailableException(void) throw()
{
    // std::cout << "Exeption Grade to Hight create " << std::endl;
	return;
}

Intern::NoFormAvailableException::NoFormAvailableException(NoFormAvailableException const &src) throw()
{
	*this = src;
	return;
}

Intern::NoFormAvailableException::~NoFormAvailableException(void) throw()
{
	return;
}

Intern::NoFormAvailableException &Intern::NoFormAvailableException::operator=(NoFormAvailableException const &rhs) throw() 
{
	(void)rhs;
	if (this != &rhs) {}
    // std::cout << "Exeption Grade egale " << std::endl;
	return (*this);
}
// Function WHAT for Hight
const char* Intern::NoFormAvailableException::what() const throw()
{
	return ("Intern Error: NO FORM AVAILAIBLE");
}


