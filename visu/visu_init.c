/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:01:47 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/26 14:50:47 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/visu.h"

t_window		*window_init(void)
{
	t_window	*window;

	window = (t_window*)malloc(sizeof(t_window));
	WIN_QUIT = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0)
	{
		ft_printf("Init_Error: %s\n", SDL_GetError());
		return (NULL);
	}
	WIN_WIN = SDL_CreateWindow("Vizualizer", SDL_WINDOWPOS_UNDEFINED,\
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (WIN_WIN == NULL)
	{
		ft_printf("Init_Window_Error: %s\n", SDL_GetError());
		return (NULL);
	}
	WIN_REND = SDL_CreateRenderer(WIN_WIN, -1, SDL_RENDERER_ACCELERATED);
	if (WIN_REND == NULL)
	{
		ft_printf("Init_Renderer_Error: %s\n", SDL_GetError());
		return (NULL);
	}
	return (window);
}

t_prop			*prop_init(t_window *window)
{
	t_prop	*map;

	if (!(map = (t_prop*)malloc(sizeof(t_prop))))
		return (0);
	MAP_SCALE = 1;
	MAP_NODE_C = 7;
	MAP_COORDS = (int**)malloc(sizeof(int*) * 7);
	int i = 0;
	while (i < 7)
		MAP_COORDS[i++] = (int*)malloc(sizeof(int) * 2);
	MAP_COORDS[0][0] = 150;
	MAP_COORDS[0][1] = 500;
	MAP_COORDS[1][0] = 300;
	MAP_COORDS[1][1] = 250;
	MAP_COORDS[2][0] = 450;
	MAP_COORDS[2][1] = 750;
	MAP_COORDS[3][0] = 600;
	MAP_COORDS[3][1] = 250;
	MAP_COORDS[4][0] = 900;
	MAP_COORDS[4][1] = 250;
	MAP_COORDS[5][0] = 600;
	MAP_COORDS[5][1] = 500;
	MAP_COORDS[6][0] = 1050;
	MAP_COORDS[6][1] = 500;
	MAP_MATRIX = (char**)malloc(sizeof(char*) * 7);
	i = 0;
	while (i < 7)
		MAP_MATRIX[i++] = ft_strnew(7);
	ft_strcpy(MAP_MATRIX[0], "0110010");
	ft_strcpy(MAP_MATRIX[1], "0001000");
	ft_strcpy(MAP_MATRIX[2], "0000011");
	ft_strcpy(MAP_MATRIX[3], "0000100");
	ft_strcpy(MAP_MATRIX[4], "0000001");
	ft_strcpy(MAP_MATRIX[5], "0000001");
	ft_strcpy(MAP_MATRIX[6], "0000000");
	MAP_NAMES = (char**)malloc(sizeof(char*) * 7);
	i = 0;
	while (i < 7)
		MAP_NAMES[i++] = ft_strnew(50);
	ft_strcpy(MAP_NAMES[0], "start");
	ft_strcpy(MAP_NAMES[1], "1st");
	ft_strcpy(MAP_NAMES[2], "4th");
	ft_strcpy(MAP_NAMES[3], "2nd");
	ft_strcpy(MAP_NAMES[4], "3rd");
	ft_strcpy(MAP_NAMES[5], "5th");
	ft_strcpy(MAP_NAMES[6], "end");
	return (map);
}

t_rend			*rend_init(t_window *window, t_prop *map)
{
	t_rend	*render;

	if (!(render = (t_rend*)malloc(sizeof(t_rend))))
		return (0);
	ANTS_END = 0;
	ANTS_COU = 4;
	ANTS_START = ANTS_COU;
	FR_CUR = 0;
	FR_LIMIT = 100;
	ST_CUR = 0;
	ST_LAST = 3;
	POS_START = 0;
	POS_END = 6;
	STATES = (int**)malloc(sizeof(int*) * ANTS_COU);
	int i = 0;
	int stages_count = 4;
	while (i < ANTS_COU)
		STATES[i++] = (int*)malloc(sizeof(int) * stages_count);
	STATES[0][0] = 1;
	STATES[0][1] = 2;
	STATES[0][2] = 5;
	STATES[0][3] = -1;
	STATES[1][0] = 3;
	STATES[1][1] = 6;
	STATES[1][2] = 6;
	STATES[1][3] = 2;
	STATES[2][0] = 4;
	STATES[2][1] = -1;
	STATES[2][2] = -1;
	STATES[2][3] = 6;
	STATES[3][0] = 6;
	STATES[3][1] = -1;
	STATES[3][2] = -1;
	STATES[3][3] = -1;
	T_MOVE = (t_move*)malloc(sizeof(t_move) * ANTS_COU);
	T_MOVE[0].x = MAP_COORDS[POS_START][0];
	T_MOVE[0].y = MAP_COORDS[POS_START][1];
	T_MOVE[1].x = MAP_COORDS[POS_START][0];
	T_MOVE[1].y = MAP_COORDS[POS_START][1];
	T_MOVE[2].x = MAP_COORDS[POS_START][0];
	T_MOVE[2].y = MAP_COORDS[POS_START][1];
	T_MOVE[3].x = MAP_COORDS[POS_START][0];
	T_MOVE[3].y = MAP_COORDS[POS_START][1];
	return (render);
}