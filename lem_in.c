/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:07:20 by kbethany          #+#    #+#             */
/*   Updated: 2019/09/13 14:10:23 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_data	mk_data(char *name)
{
	t_data *data;
	size_t size;

	size = sizeof(*data);
	data = (t_data *)malloc(size);
	bzero(data, size);
	data->name = strdup(name);
	return (*data);
}

t_node	*mk_node(char *name, short links_number)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(*node));
	node->data = mk_data(name);
	node->data.links_number = links_number;
	node->links = (t_node **)malloc(sizeof(*node) * links_number);
	return (node);
}

int main(void)
{
	t_node *node;
	t_node *node1;
	t_node *node2;
	t_data *data;

	node = mk_node("roflan", 2);
	node1 = mk_node("ebalo", 1);
	node2 = mk_node("pominki", 1);
	node->links[0] = node1;
	node->links[1] = node2;
	printf("%s->%s\n->%s\n", node->data.name, node->links[0]->data.name,
		 node->links[1]->data.name);
	return (0);
}
