/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:39:21 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/09/17 13:52:24 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf/libft/includes/libft.h"

# define FLAG_ROOM	0
# define FLAG_START	1
# define FLAG_END	2

typedef struct		s_room
{
	char			*name;
	int 			id;
	int 			p;
	char			*ant;
	struct s_room	*next;
	struct s_room	*prev;
	struct s_room	**l_up;
	struct s_room	**l_down;
}					t_room;

t_room				*new_room(char *src_string, t_room *next, t_room *prev);

#endif
