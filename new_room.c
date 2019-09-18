/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:51:25 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/09/17 13:55:04 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static char		*find_room_name(char *src)
{
	char	*name;
	char	len;
	char	i;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len] && src[len] != ' ' && len != 50)
		len++;
	if (len == 50)
		return (NULL);
	if (!(name = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		name[i] = src[i];
	name[i] = '\0';
	return (name);
}

static t_room	*kill_room_return_null(t_room *node)
{
	if (node)
	{
		if (node->src_string)
			free(node->src_string);
		if (node->name)
			free(node->name);
		free(node);
	}
	return (NULL);
}

t_room			*new_room(char *src_string, t_room *next, t_room *prev)
{
	t_room	*dst;

	if (!src_string)
		return (NULL);
	if (!(dst = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	ft_bzero(dst, sizeof(t_room));
	dst->src_string = src_string;
	if (!(dst->name = find_room_name(src_string)))
		return (kill_room_return_null(dst));
	dst->next = next;
	dst->prev = prev;
	return (dst);
}

void min_weight_pass(t_room *start, t_room *end)
{
	int i;
	int j;

	j = 2;
	while (start->links_up)
	{
		i = 0;
		while(start->links_up)
		{
			if (start->links_up[i]->pass == 0)
			{
				start->links_up[i]->pass = j;
				start = start->links_up[i];
			}
			else
				i++;
		}
	}
}

void 	min_pass(t_room *start, t_room *end)
{
	int min;
	int n;
	int i;

	while (end->links_down)
	{
		i = 0;
		min = end->id + 1;
		while (end->links_down[i])
		{
			if (end->links_down[i]->id <= min)
			{
				min = end->links_down[i]->id;
				n = i;
			}
			i++;
		}
		end = end->links_down[n];
		end->pass = 1;
	}
}

int 	pass_finder(t_room * s, int j, t_room *end)
{
	int i;

	i = 0;
	while (s->links_up[i])
	{
		if (s->links_up[i]->pass == 0)
		{
			s->links_up[i]->pass = j;
			s = s->links_up[i];
			i = 0;
		}
		else
			i++;
	}
	if (s == end)
		return (1);
	return (0);
}

void  alg(t_room *start, t_room *end)
{
  int i;
	int j;
  t_room *tmp;

	start->id = 0;
	tmp = start;
	while (start->next)
	{
		i = 0;
		while (start->links_up[i])
		{
			start->links_up[i]->id = start->id + 1;
			i++;
		}
		start = start->next;
	}
	min_pass(tmp, end);
	j = 2;
	while (tmp->next)
	{
		if (pass_finder(tmp, j, end))
			j++;
		else
			ne_tuda(tmp, j);
		while (tmp->pass != j && tmp->pass != 0)
		tmp = tmp->next;
	}
	if (j == 2)
}

int main()
{
  t_room *n1;
  t_room *n2;
  t_room *n3;
  t_room *n4;
  t_room *n5;

  t_room *a1;
  t_room *a2;
  t_room *a3;
  t_room *a4;
  t_room *a5;

  n1 = new_room("n1 4 1", n2, 0);
  n2 = new_room("n2 3 2", n3, n1);
  n3 = new_room("n3 2 2", n4, n2);
  n4 = new_room("n4 1 2", n5, n3);
  n5 = new_room("n5 4 3", 0, n4);

	n1->pass = 0;
	n2->pass = 0;
	n3->pass = 0;
	n4->pass = 0;
	n5->pass = 0;

  a1 = new_room("a1 2 1", a2, 0);
  a2 = new_room("a2 3 2", a3, a1);
  a3 = new_room("a3 2 2", a4, a2);
  a4 = new_room("a4 1 2", a5, a3);
  a5 = new_room("a5 2 3", 0, a4);

	a1->pass = 0;
	a2->pass = 0;
	a3->pass = 0;
	a4->pass = 0;
	a5->pass = 0;

  n1->links_up[0] = n5;
  n1->links_up[1] = n2;
  n1->links_up[2] = NULL;
  n2->links_up[0] = n5;
  n2->links_up[1] = n3;
  n2->links_up[2] = NULL;
  n3->links_up[0] = n4;
  n3->links_up[1] = NULL;
  n4->links_up[0] = n5;
  n4->links_up[1] = NULL;
	n5->links_up[0] = n1;
	n5->links_up[1] = n2;
	n5->links_up[2] = n4;
	n5->links_up[3] = NULL;
	a1->links_up[0] = a2;
  a1->links_up[1] = a3;
  a1->links_up[2] = a4;
  a1->links_up[3] = NULL;
  a2->links_up[0] = a5;
  a2->links_up[1] = NULL;
  a3->links_up[0] = a5;
  a3->links_up[1] = NULL;
  a4->links_up[0] = a5;
  a4->links_up[1] = NULL;
	a5->links_up[0] = a2;
	a5->links_up[1] = a3;
	a5->links_up[2] = a4;
	a5->links_up[3] = NULL;
	n5->links_down[0] = n1;
	n5->links_down[1] = n2;
	n5->links_down[2] = n4;
	n5->links_down[3] = NULL;
	n4->links_down[0] = n3;
	n4->links_down[1] = NULL;
	n3->links_down[0] = n2;
	n3->links_down[1] = NULL;
	n2->links_down[0] = n1;
	n2->links_down[1] = NULL;
	a5->links_down[0] = a2;
	a5->links_down[1] = a3;
	a5->links_down[2] = a4;
	a5->links_down[3] = NULL;
	a4->links_down[0] = a1;
	a4->links_down[1] = NULL;
	a3->links_down[0] = a1;
	a3->links_down[1] = NULL;
	a2->links_down[0] = a1;
	n2->links_down[1] = NULL;

  return (0);
}
