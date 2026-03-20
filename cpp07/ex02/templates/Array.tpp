/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:29:22 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/17 16:57:09 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__ARRAY_TPP__
# define	__ARRAY_TPP__

// Constructors/Destructor =====================================================
template <typename Type>
Array<Type>::Array(void):
	_array(new Type[0]),
	_size(0) {}

template <typename Type>
Array<Type>::Array(const unsigned int &n):
	_array(new Type[n]),
	_size(n) {}
	
template <typename Type>
Array<Type>::Array(const Array &copy):
	_array(new Type[copy._size]),
	_size(copy._size)
{
	for (unsigned int i = 0; i < this->_size; ++i)
	{
		this->_array[i] = copy._array[i];
	}
}

template <typename Type>
Array<Type>::~Array(void)
{
	delete[] this->_array;
}


// Operator overloads ==========================================================
template	<typename Type>
Array<Type>		&Array<Type>::operator=(const Array<Type> &assign)
{
	if (this != &assign)
	{
		delete[] this->_array;
		
		this->_size = assign._size;
		this->_array = new Type[this->_size];
	
		for (unsigned int i = 0; i < this->_size; ++i)
		{
			this->_array[i] = assign._array[i];
		}
	}
	return (*this);
}

template	<typename Type>
Type		&Array<Type>::operator[](const unsigned int &i)
{
	if (i >= this->_size)
		throw (std::exception());
	return (this->_array[i]);
}

template	<typename Type>
const Type		&Array<Type>::operator[](const unsigned int &i) const
{
	if (i >= this->_size)
		throw (std::exception());
	return (this->_array[i]);
}

template	<typename Type>
std::ostream	&operator<<(std::ostream &out, Array<Type> &array)
{
	for (unsigned int i = 0; i < array.size(); ++i)
	{
		out << array[i] << '\n';
	}
	return (out);
}

// Member functions ============================================================
template		<typename Type>
unsigned int	Array<Type>::size(void) const
{
	return (this->_size);
}

#endif
