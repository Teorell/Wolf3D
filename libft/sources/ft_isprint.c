/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:55:54 by jblack-b          #+#    #+#             */
/*   Updated: 2018/11/28 15:59:07 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	if ((040 <= c && c <= 0176))
		return (1);
	else
		return (0);
}
