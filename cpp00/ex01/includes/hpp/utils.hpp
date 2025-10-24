/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:18:41 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/08 18:19:31 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# define CONF_EXIT			"Are you sure to exit ? All your contacts will be lost forever."
# define CONF_REP_CONTACT	"Would you like to replace the oldest contact ?"
# define CONF_NOT_IN_RANGE	"Not in range. Would you like to add a new contact ?"

bool	ask_confirmation(std::string message);
bool	str_is(std::string str, int (*check)(int));
int		put_stream_error(int state, const char *func, const char *calling_func);

#endif
