/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <lsandor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:45:21 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/14 17:27:24 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_render(t_wolf *wolf)
{
	ft_animation_play(wolf);
	ft_bzero(wolf->sdl->text_buf, 4 * WIN_W * WIN_H);
	SDL_SetRenderDrawColor(wolf->sdl->m_renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(wolf->sdl->m_renderer);
	ft_multithreading(wolf);
	ft_draw_animation(wolf);
	SDL_UpdateTexture(wolf->sdl->tex, 0, wolf->sdl->text_buf, WIN_W * 4);
	SDL_RenderCopy(wolf->sdl->m_renderer, wolf->sdl->tex, NULL, NULL);
	SDL_RenderPresent(wolf->sdl->m_renderer);
}
