/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:32:21 by akhalidy          #+#    #+#             */
/*   Updated: 2021/12/01 20:26:59 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::HighException::HighException(string const &name)
{
	_name = name;
}

const char *Form::HighException::what(void) const throw()
{
	return ("Form::GradeTooHighException.");
}

Form::LowException::LowException(string const &name)
{
	_name = name;
}

const char *Form::LowException::what(void) const throw()
{
	return ("Form::GradeTooLowException.");
}

Form::Unsigned::Unsigned(string const &name)
{
	_name = name;
}

const char *Form::Unsigned::what(void) const throw()
{
	return (string("Form::Unsigned " + _name + ".").c_str());
}

Form::Illegal::Illegal(string const &name)
{
	_name = name;
}

const char *Form::Illegal::what(void) const throw()
{
	string	str;

	str = "Form::Bureaucrat isn't legitimate to execute " + _name;
	return (str.c_str());
}

Form::Form(void) : _name("imposter"), _signed(false), _signGrade(150),
	_execGrade(150), _target("undefined")
{
	cout << "Form::Default constructor called." << endl;
}

Form::Form(string const &name, string const &target, int signGrade, int execGrade) : _name(name),
		_signed(false), _signGrade(signGrade), _execGrade(execGrade), _target(target)
{
	cout << "Form::Parameterized constructor called." << endl;
	if (signGrade < 1 || execGrade < 1)
		throw(HighException(get_name()));
	else if (signGrade > 150 || execGrade > 150)
		throw(LowException(get_name()));
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed),
		_signGrade(src._signGrade), _execGrade(src._execGrade)
{
	cout << "Form::Copy Constructor called." << endl;
}

Form	&Form::operator=(const Form &rhs)
{
	cout << "Form::Assignement called." << endl;
	_signed = rhs._signed;
	return (*this);
}

string	Form::get_name(void) const
{
	return (_name);	
}

bool			Form::get_signed(void) const
{
	return (_signed);	
}

int		Form::get_signGrade(void) const
{
	return (_signGrade);	
}

int		Form::get_execGrade(void) const
{
	return (_execGrade);	
}	

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	bureaucrat.signForm(*this);
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw(LowException(get_name()));
}

ostream		&operator<<(ostream &out, const Form &rhs)
{
	string	tmp;

	tmp = rhs.get_signed() ? " is" : " isn't";
	out << "Form_name : " << rhs.get_name() << tmp;
	out << " signed. " << endl;
	out << rhs.get_signGrade() << " is the grade required to sign it. ";
	out << rhs.get_execGrade() << " is the grade required to execute it." << endl;
	return (out);
}

string	Form::get_target(void) const
{
	return (_target);
}

void	Form::set_signed(bool value)
{
	_signed = value;
}

void	Form::set_target(string const & target)
{
	_target = target;
}

Form::~Form(void)
{
	cout << "Form::Destructor called." << endl;
}
