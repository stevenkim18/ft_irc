/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:15:55 by qfeuilla          #+#    #+#             */
/*   Updated: 2020/09/22 22:32:11 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"
#include <iostream>

Command		*parse(std::string cmd) {
	std::vector<std::string>	container;
	size_t						last = 0;
	size_t						i;

	for (i = 0; i < cmd.length(); i++) {	
		if (cmd[i] == ' ') {
			container.push_back(std::string(&cmd[last], &cmd[i]));
			while (cmd[i] == ' ') 
				i++;
			last = i;
		}
	}
	if (last < i - 1)
		container.push_back(std::string(&cmd[last], &cmd[i - 1]));
		// ! removing the "- 1" part seems to solve the problem (when using netcat as a client)
	return (new Command(container, std::string(&cmd[0], &cmd[cmd.length() - 1])));
}

std::vector<std::string>	parse_comma(std::string cmd) {
	std::vector<std::string>	container;
	size_t						last = 0;
	size_t						i;

	for (i = 0; i < cmd.length(); i++) {	
		if (cmd[i] == ',') {
			container.push_back(std::string(&cmd[last], &cmd[i]));
			while (cmd[i] == ',') 
				i++;
			last = i;
		}
	}
	if (last < i)
		container.push_back(std::string(&cmd[last], &cmd[i]));
	return container;
}