/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:45:05 by kporceil          #+#    #+#             */
/*   Updated: 2026/03/26 09:33:37 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::string const& datas)
{
	parseCsv(datas);
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& cpy) :
	m_prices(cpy.m_prices)
{}

BitcoinExchange&
BitcoinExchange::operator=(BitcoinExchange const& cpy)
{
	if (this != &cpy)
		m_prices = cpy.m_prices;
	return (*this);
}

bool
DateCmp::operator()(std::string const& a, std::string const& b) const
{
	size_t		aEnd = a.find('-');
	size_t		bEnd = b.find('-');
	std::string aYear = a.substr(0, aEnd);
	std::string bYear = b.substr(0, bEnd);

	if (aYear.size() != bYear.size())
		return (aYear.size() < bYear.size());
	if (aYear != bYear)
		return (aYear < bYear);
	return (a.substr(aEnd) < b.substr(bEnd));
}

double
BitcoinExchange::getValueAtDate(std::string const& date)
{
	std::string normalized = formatDate(date);
	std::map<std::string, double, DateCmp>::iterator it =
		m_prices.upper_bound(normalized);
	if (it-- == m_prices.begin())
		throw(std::out_of_range(""));
	return (it->second);
}

void
BitcoinExchange::parseCsv(std::string csv)
{
	std::ifstream file(csv.c_str());
	if (!file.is_open())
		throw(std::runtime_error("Error: could not open file: " + csv));

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t sep = line.find(',');
		if (sep == std::string::npos)
			continue;
		std::string date = line.substr(0, sep);
		std::string price = line.substr(sep + 1);
		if (!isValidDate(date))
			continue;
		char*  end;
		double value = strtod(price.c_str(), &end);
		if (*end != '\0')
			continue;
		m_prices[formatDate(date)] = value;
	}
}

static int
strMod(std::string const& s, int mod)
{
	int result = 0;
	for (size_t i = 0; i < s.size(); i++)
		result = (result * 10 + (s[i] - '0')) % mod;
	return (result);
}

int
BitcoinExchange::isValidDate(std::string const& date)
{
	size_t firstSep = date.find('-');
	if (firstSep == std::string::npos || firstSep == 0)
		return (0);

	for (size_t i = 0; i < firstSep; i++)
		if (!isdigit(date[i]))
			return (0);

	if (date.size() != firstSep + 6)
		return (0);
	if (date[firstSep + 3] != '-')
		return (0);
	for (size_t i = firstSep + 1; i < date.size(); i++)
		if (i != firstSep + 3 && !isdigit(date[i]))
			return (0);

	int month = atoi(date.substr(firstSep + 1, 2).c_str());
	int day = atoi(date.substr(firstSep + 4, 2).c_str());

	if (month < 1 || month > 12 || day < 1)
		return (0);

	std::string year = date.substr(0, firstSep);
	size_t		fnz = year.find_first_not_of('0');
	year = (fnz != std::string::npos) ? year.substr(fnz) : "0";

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((strMod(year, 4) == 0 && strMod(year, 100) != 0) ||
		strMod(year, 400) == 0)
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return (0);

	return (1);
}

std::string
BitcoinExchange::formatDate(std::string const& date)
{
	size_t		sep = date.find('-');
	std::string year = date.substr(0, sep);
	size_t		fnz = year.find_first_not_of('0');
	year = (fnz != std::string::npos) ? year.substr(fnz) : "0";
	return (year + date.substr(sep));
}

void
BitcoinExchange::processInput(std::string const& input)
{
	std::ifstream file(input.c_str());
	if (!file.is_open())
		throw(std::runtime_error("Error: could not open file: " + input));

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, sep);
		std::string value = line.substr(sep + 3);
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		char*  end;
		double amount = strtod(value.c_str(), &end);
		if (*end != '\0')
		{
			std::cout << "Error: bad input => " << value << std::endl;
			continue;
		}
		if (amount < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (amount > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		try
		{
			std::cout << date << " => " << amount << " = "
					  << amount * getValueAtDate(date) << std::endl;
		}
		catch (std::out_of_range const&)
		{
			std::cout << "Error: bad input => " << date << std::endl;
		}
	}
}
