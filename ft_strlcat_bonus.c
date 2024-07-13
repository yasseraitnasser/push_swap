/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:15:44 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/23 21:45:10 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = 0 ;
	dstlen = 0;
	while (src[srclen])
		srclen++;
	while (dst[dstlen])
		dstlen++;
	if (dstsize == 0)
		return (srclen);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (src[i] && dstlen + i < dstsize - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
