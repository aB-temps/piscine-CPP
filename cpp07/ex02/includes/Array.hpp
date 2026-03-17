/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/17 16:57:45 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__ARRAY_HPP__
# define	__ARRAY_HPP__

template <typename Type>
class	Array
{
	public:
		Array(void);
		~Array(void);
		Array(const Array &copy);

		Array				&operator=(const Array &assign);
		Type				operator[](const unsigned int &i);

		const unsigned int	size(void) const;

	private:
		Type				*_array;
		unsigned int		_size;
};

#endif
