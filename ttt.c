/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:38:44 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/30 16:10:20 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	check_map(int p, int i, char *map)
{
	char	c = 'X';
	if (p == 2)
		c = 'O';
	if (i > 0 && i < 10)
	{
		if (i == 7 && map[2] == '7')
			map[2] = c;
		else if (i == 8 && map[6] == '8')
			map[6] = c;
		else if (i == 9 && map[10] == '9')
			map[10] = c;
		else if (i == 4 && map[28] == '4')
			map[28] = c;
		else if (i == 5 && map[32] == '5')
			map[32] = c;
		else if (i == 6 && map[36] == '6')
			map[36] = c;
		else if (i == 1 && map[54] == '1')
			map[54] = c;
		else if (i == 2 && map[58] == '2')
			map[58] = c;
		else if (i == 3 && map[62] == '3')
			map[62] = c;
		else
			return (0);
		return (1);
	}
	return (0);
}

int	check_win(char *map)
{
	if (map[2] == map[6] && map[6] == map[10])
		return (0);
	if (map[28] == map[32] && map[32] == map[36])
		return (0);
	if (map[54] == map[58] && map[58] == map[62])
		return (0);
	if (map[2] == map[28] && map[28] == map[54])
		return (0);
	if (map[6] == map[32] && map[32] == map[58])
		return (0);
	if (map[10] == map[36] && map[36] == map[62])
		return (0);
	if (map[2] == map[32] && map[32] == map[62])
		return (0);
	if (map[10] == map[32] && map[32] == map[54])
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int		r = 1;
		int		turn = 1;
		int		play = 0;
		char	*p1 = av[1];
		char	*p2 = av[2];
		char	*ap_s = "'s turn - choose a number on grid!";
		char	*ap = "' turn - choose a number on grid!";
		char	map[] = "\t 7 | 8 | 9 \n\t---+---+---\n\t 4 | 5 | 6 \n\t---+---+---\n\t 1 | 2 | 3 \n";

		system("clear");
		while (turn)
		{
			while (turn == 1)
			{
				if (p1[strlen(p1) - 1] == 's')
					printf("It is %s%s\n\n", p1, ap);
				else
					printf("It is %s%s\n\n", p1, ap_s);
				printf("%s\n%s is placing X in position: ", map, p1);
				scanf(" %d", &play);
				if (!check_map(turn, play, map))
				{
					system("clear");
					printf("Invalid input!\n\n");
				}
				else
				{
					if (!check_win(map))
					{
						system("clear");
						printf("\n\n%s\n", map);
						printf("%s WINS!!!\n", p1);
						turn = 0;
					}
					else
					{
						turn = 2;
						r++;
						system("clear");
					}
					if (r > 9)
					{
						printf("\n\n%s\n%s DREW WITH %s !!!\n", map, p1, p2);
						turn = 0;
					}
				}
			}
			while (turn == 2)
			{
				if (p2[strlen(p2) - 1] == 's')
					printf("It is %s%s\n\n", p2, ap);
				else
					printf("It is %s%s\n\n", p2, ap_s);
				printf("%s\n%s is placing O in position: ", map, p2);
				scanf(" %d", &play);
				if (!check_map(turn, play, map))
				{
					system("clear");
					printf("Invalid input!\n\n");
				}
				else
				{
					if (!check_win(map))
					{
						system("clear");
						printf("\n\n%s\n", map);
						printf("%s WINS!!!\n", p2);
						turn = 0;
					}
					else
					{
						turn = 1;
						r++;
						system("clear");
					}
				}
			}
		}
	}
	else
		printf("Please start game with: \"./ttt [player1] [player2]\"\n");
	return (0);
}
