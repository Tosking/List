#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    int size;
    Node *head;
    Node *tail;
} List;

void init_list(List *list);
Node *__find_node(List *list, int index);
void add_item(List *list, Node *item);
void print_list(List *list);
Node *remove_item(List *list, int index);
void delete_item(List *list, int index);
void insert_item(List *list, int index, Node *buff);
void clear(List *list);
int get_index(List *list, Node *pointer);
void push_back(List *list, Node *item);

