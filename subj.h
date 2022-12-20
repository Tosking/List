#pragma once
#include "list.h"

typedef enum TypeObject
{
    None,
    isStar,
    isPlanet
} TypeObject;

typedef struct Base
{
    TypeObject type;
    struct Node;
    char name[50];
    double mass;
    double d;
} Base;

typedef enum AddChoose {
    Name,
    Mass,
    D,
    T,
    Size,
    Earth_d,
    System,
    Orb_d,
    ALL
}AddChoose;


void add(Base *data, AddChoose choose, TypeObject type);
Base *create(TypeObject type, List* list);
void add_star(List *list);
void print_list(List* list);

