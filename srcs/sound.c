/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <lsandor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:14:24 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/13 21:11:57 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_sound(t_wolf *w)
{
	w->sdl->wav_spec = ft_safe_malloc(sizeof(SDL_AudioSpec) * 2);
	w->sdl->wav_buffer = ft_safe_malloc(sizeof(Uint8 *) * 2);
	w->sdl->wav_length = ft_safe_malloc(sizeof(Uint32) * 2);
	w->sdl->audio_device = ft_safe_malloc(sizeof(SDL_AudioDeviceID) * 2);
	SDL_LoadWAV("Sounds/pistol.wav", &w->sdl->wav_spec[0],
	&w->sdl->wav_buffer[0], &w->sdl->wav_length[0]);
	SDL_LoadWAV("Sounds/qliqc-7567m.wav", &w->sdl->wav_spec[1],
	&w->sdl->wav_buffer[1], &w->sdl->wav_length[1]);
	w->sdl->audio_device[0] = SDL_OpenAudioDevice(NULL, 0,
	&w->sdl->wav_spec[0], NULL, 0);
	w->sdl->audio_device[1] = SDL_OpenAudioDevice(NULL, 0,
	&w->sdl->wav_spec[1], NULL, 0);
}

void	ft_load_sound(t_wolf *w)
{
	w->t.sound_old_time = w->t.sound_time;
	w->t.sound_time = SDL_GetTicks();
	w->t.change_of_time = (w->t.sound_time - w->t.sound_old_time);
	w->t.sound_sum_time += w->t.change_of_time;
	if (w->t.sound_sum_time >= w->t.play_time && w->sdl->i == 1)
	{
		w->t.sound_sum_time = 0;
		SDL_QueueAudio(w->sdl->audio_device[1], w->sdl->wav_buffer[1],
		w->sdl->wav_length[1]);
		SDL_PauseAudioDevice(w->sdl->audio_device[1], 0);
	}
}

void	ft_play_shot(t_wolf *w)
{
	if (w->t.flag == 1)
	{
		SDL_QueueAudio(w->sdl->audio_device[0], w->sdl->wav_buffer[0],
		w->sdl->wav_length[0]);
		SDL_PauseAudioDevice(w->sdl->audio_device[0], 0);
		w->t.flag = 0;
	}
	w->anim.start_animation = 1;
}
