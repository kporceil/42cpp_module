/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:36:21 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/23 02:32:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;
	public:
		Contact(void);

		const std::string&	getFirstName(void) const;
		const std::string&	getLastName(void) const;
		const std::string&	getNickName(void) const;
		const std::string&	getPhoneNumber(void) const;
		const std::string&	getDarkestSecret(void) const;

		void			setFirstName(std::string& FirstName);
		void			setLastName(std::string& LastName);
		void			setNickName(std::string& NickName);
		void			setPhoneNumber(std::string& PhoneNumber);
		void			setDarkestSecret(std::string& DarkestSecret);
};

#endif
