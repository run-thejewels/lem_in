/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:28:48 by kbethany          #+#    #+#             */
/*   Updated: 2019/09/07 19:51:15 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include "ft_printf/include/head.h"

typedef struct		s_data
{
	char						*name;
	short						links_number;
	short						to_start;
	short						to_finish;
}									t_data;

typedef struct		s_node
{
	t_data					data;
	struct	s_node	**links;
	int 						top;
	int 						count;
}									t_node;

t_data	mk_data(char *name);
t_node	*mk_node(char *name, short links_number);

#endif
