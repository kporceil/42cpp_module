/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:53:32 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/23 02:19:45 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		int		_nbContacts;
		Contact	_contacts[9];
	public:
		PhoneBook(void);
		
		void	addContact(void);
		void	displayContact(int id);
		void	displayList(void);
		int		getContactNb(void);

		~PhoneBook(void);
};

#endif
