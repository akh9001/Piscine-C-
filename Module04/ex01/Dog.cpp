/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:11:51 by akhalidy          #+#    #+#             */
/*   Updated: 2021/11/19 15:36:03 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	cout << "Dog::Default constructor called." << endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src)
{
	cout << "Dog::Copy constructor called." << endl;
	*this = src;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	cout << "Dog::Assignation operator called" << endl;
	Animal::operator=(rhs);
	delete this->_brain;
	this->_brain = new Brain();
	return(*this);
}

void	Dog::makeSound(void) const
{
	cout << "A " << this->type << " says Woof !!" << endl;
}

Dog::~Dog(void)
{
	cout << "Dog::Destructor called." << endl;
	delete this->_brain;
}
