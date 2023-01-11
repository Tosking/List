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
    struct Node base;
    TypeObject type;
    char name[50];
    double mass;
    double d;
} Base;

typedef struct Star
{
    struct Base base;
    double t;
    double size;
    double earth_d;
} Star;

typedef struct Planet 
{
    struct Base base;
    char system[50];
    double orb_d;
} Planet;

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


void insert(Base *data, AddChoose choose, TypeObject type);
Base *create(TypeObject type, List* list);
void add_star(List *list);
void print_item(Base *data, AddChoose choose);
void print_list(List *list);
void sort(List* list);
void search(List* list, const char *str);
void print_solar(List* list);
void print_one(List* list, TypeObject type);

