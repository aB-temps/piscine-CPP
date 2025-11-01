/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_file.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:49:07 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/01 11:53:37 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma		once
#ifndef		__CLOSE_FILE_TPP__
# define	__CLOSE_FILE_TPP__

# include <iostream>
# include <fstream>

template <typename T>
void	close_file(T &file)
{
	if (file.is_open())
		file.close();
}

#endif
