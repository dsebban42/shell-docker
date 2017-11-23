/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 20:13:53 by dsebban           #+#    #+#             */
/*   Updated: 2016/08/08 20:50:04 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static uintmax_t	length(void *content, short c)
{
	if (c == 0)
		return ((unsigned int)content);
	if (c == 1)
		return ((unsigned char)content);
	if (c == 2)
		return ((unsigned short)content);
	if (c == 3)
		return ((unsigned long int)content);
	if (c == 4)
		return ((unsigned long long)content);
	if (c == 5)
		return ((uintmax_t)content);
	if (c == 6)
		return ((size_t)content);
	return ((uintmax_t)content);
}

static int			ft_count_word(size_t value)
{
	int i;

	i = 0;
	while (value > 0)
	{
		value /= 16;
		i++;
	}
	return (i);
}

void				ft_dec_to_hex(void *content, short c, char **ct_str)
{
	uintmax_t	dec;
	int			whide;
	char		*sum;

	dec = length(content, c);
	whide = 0;
	sum = NULL;
	if (content == NULL || dec == 0)
		return ((void)ft_strcat(*ct_str, "0"));
	whide = ft_count_word(dec);
	if ((sum = ft_strnew(whide + 1)) == NULL)
		return ;
	sum[whide] = '\0';
	while (dec > 0)
	{
		whide--;
		if (((sum[whide] = (dec % 16) + 48)) > 57)
			sum[whide] += 39;
		dec /= 16;
	}
	*ct_str = ft_strcat(*ct_str, sum);
	free(sum);
}
