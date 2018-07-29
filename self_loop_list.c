#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	node *next;
};

int N = 0;
node *list = NULL;
node *pcur = NULL;

bool is_7_num(unsigned int num)
{
	if (num % 7 == 0)
		return true;
	while (num)
	{
		if (7 == num % 10)
			return true;
		num /= 10;
	}

	return false;
}

void game_set(unsigned int num)
{
	node *p = NULL, *tmp = NULL;
	p = (node *)malloc(sizeof(node));
	p->data = 0;
	p->next = p;

	list = pcur =  p;

	for (int i = 1; i <= num; i++)
	{
		tmp = (node *)malloc(sizeof(node));
		tmp->data = i;

		tmp->next = list;
		p->next = tmp;

		p = tmp;
		N++;
	}
}

void delete_node(node *pcur)
{
	node *tmp = list;
	while (tmp->next != pcur)
		tmp = tmp->next;
	tmp->next = pcur->next;
	free(pcur);
}

unsigned int game_play(unsigned int in_num)
{
	unsigned res = 0;
	while (N)
	{
		if (pcur == list)
			pcur = pcur->next;

		if (is_7_num(in_num))
		{
			res = pcur->data;
			node *tmp = pcur;
			pcur = pcur->next;
			delete_node(tmp);
			N--;
			break;
		}
		in_num++;
		
		pcur = pcur->next;
	}
	return res;
}

void game_over()
{
	node *p = list;
	if (!list) return;
	while(N--)
	{
		node *tmp = p;
		p = p->next;
		free(tmp);
	}
	free(list);
	N = 0;
	list = NULL;
	pcur = NULL;
}


int  main()
{
	//JOSEPHUS(13, 4, 3);

	int a, b, c, d;
	game_set(4);
	a = game_play(1);
	b = game_play(2); 
	c = game_play(3); 
	d = game_play(5);
	printf("%d %d %d %d \n",a,b,c,d);
	game_over();

	game_set(4);
	a = game_play(1);
	b = game_play(2);
	c = game_play(3);
	d = game_play(5);
	printf("%d %d %d %d \n", a, b, c, d);

	return 0;
}