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

static void lines(t_node *a, int i, t_node *b)
{
	a->links[i] = b;
}

int main(void)
{
	t_node *node1;
	t_node *node2;
	t_node *node3;
	t_node *node4;
	t_node *node5;
	t_node *node6;
	t_node *node7;
	t_node *node8;
	int 		i;

	i = 0;
	node1 = mk_node("1", 2);
	node2 = mk_node("2", 2);
	node3 = mk_node("3", 2);
	node4 = mk_node("4", 2);
	node5 = mk_node("5", 2);
	node6 = mk_node("6", 2);
	node6 = mk_node("7", 2);
	node6 = mk_node("8", 0);

	lines(node1, 0, node2);
	lines(node1, 1, node3);
	lines(node2, 0, node4);
	lines(node2, 1, node5);
	lines(node3, 0, node4);
	lines(node3, 1, node5);
	lines(node4, 0, node6);
	lines(node4, 1, node7);
	lines(node5, 0, node6);
	lines(node5, 1, node7);
	lines(node6, 0, node8);
	lines(node7, 0, node8);

	printf("%s->%s\n     ->%s\n", node1->data.name, node1->links[0]->data.name,
	node1->links[1]->data.name);
 	printf("%s->%s\n     ->%s\n", node2->data.name, node2->links[0]->data.name,
	node2->links[1]->data.name);
	printf("%s->%s\n     ->%s\n", node3->data.name, node3->links[0]->data.name,
	node3->links[1]->data.name);
	printf("%s->%s\n     ->%s\n", node4->data.name, node4->links[0]->data.name,
	node4->links[1]->data.name);
 	printf("%s->%s\n     ->%s\n", node5->data.name, node5->links[0]->data.name,
	node5->links[1]->data.name);
	printf("%s->%s\n", node6->data.name, node6->links[0]->data.name);
	printf("%s->%s\n", node7->data.name, node7->links[0]->data.name);
	return (0);
}
