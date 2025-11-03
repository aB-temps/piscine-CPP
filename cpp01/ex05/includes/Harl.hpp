/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:56:15 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/03 15:56:16 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma		once
#ifndef		__HARL_HPP__
# define	__HARL_HPP__

# include <string>

class	Harl
{
	public:
		Harl(void);
		void			complain(std::string level) ;


	private:
		enum			_e_Features
		{
			DEBUG,
			INFO,
			WARN,
			ERROR,
			FEATURE_QTY,
		};
		typedef	void		(Harl::*_FeaturesArray)(void);
		typedef	const char	*_FeatureKeysArray[FEATURE_QTY];
		_FeaturesArray		_features[FEATURE_QTY];
		_FeatureKeysArray	_featureKeys;
		void				_debug(void);
		void				_info(void);
		void				_warning(void);
		void				_error(void) ;
};

#endif
