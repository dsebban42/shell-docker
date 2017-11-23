/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdeloccur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 16:11:14 by didier            #+#    #+#             */
/*   Updated: 2016/10/28 14:52:41 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_deloccur(char **str, int oc)
{
	while (str[0][++oc])
	{
		str[0][oc - 1] = str[0][oc];
	}
	str[0][--oc] = 0;
}
