/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:42:15 by kporceil          #+#    #+#             */
/*   Updated: 2026/03/26 09:33:50 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

struct DateCmp
{
	bool operator()(std::string const& a, std::string const& b) const;
};

class BitcoinExchange
{
private:
	std::map<std::string, double, DateCmp> m_prices;

	double		getValueAtDate(std::string const& date);
	void		parseCsv(std::string csv);
	int			isValidDate(std::string const& date);
	std::string formatDate(std::string const& date);

public:
	BitcoinExchange();
	BitcoinExchange(std::string const& datas);
	BitcoinExchange(BitcoinExchange const& cpy);
	~BitcoinExchange();

	BitcoinExchange& operator=(BitcoinExchange const& cpy);

	void processInput(std::string const& input);
};

#endif
