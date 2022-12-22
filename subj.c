#include "subj.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Star{
    struct Base base;
    float t;
    float size;
    float earth_d;
} Star;

typedef struct Planet {
    struct Base base;
    char* system;
    float orb_d;
} Planet;

void __clear_input(){
    while(getchar() != EOF){
        printf("1\n");
    }
}

void add(Base *data, AddChoose choose, TypeObject type){
    fflush(stdin);
    char *temp;
    switch(choose){
        case Name:
            printf("Name:");
            scanf("%s", &data->name);
            break;
        case Mass:
            printf("Mass:");
            scanf("%lf", &data->mass);
            break;
        case D:
            printf("Diameter:");
            scanf("%lf", &data->d);
            break;
        case ALL:
            for(int i = 0; i < Orb_d; i++){
                add(data, i, type);
            }
    }
    switch (type){
        case isStar:
            switch (choose){
                case Size:
                    printf("Size:");
                    scanf("%lf", &((Star*) data)->size);
                    break;
                case Earth_d:
                    printf("Distance to earth:");
                    scanf("%lf", &((Star*) data)->earth_d);
                    break;
                case T:
                    printf("Temperature:");
                    scanf("%lf", &((Star*) data)->t);
                    break;
            }
            break;
        case isPlanet:
            switch(choose){
                case Orb_d:
                    printf("Orbit diameter:");
                    scanf("%lf", ((Planet*) data)->orb_d);
                    break;
                case System:
                    printf("System:");
                    scanf("%s", temp);
                    strcpy(((Planet*) data)->system,temp);
                    break;
            }
            break;
    }
    
}

void print_list(List* list){
    Node *temp = list->head;
    if(temp == NULL){
        printf("**List is empty**\n");
        return;
    }
    for(int i = 0; i < list->size; i++){
        switch(((Base*) temp)->type){
            case isStar:
                printf("Name:%s\nType:Star\nMass:%lf\nDiameter:%lf\nSize:%lf\nDistance to Earth:%lf\nTemperature:%lf\n",
                ((Base*) temp)->name, ((Base*) temp)->mass, ((Base*) temp)->d, ((Star*) temp)->size, ((Star*) temp)->earth_d, ((Star*) temp)->t);
                break;
            case isPlanet:
                printf("Name:%s\nType:Planet\nMass:%lf\nDiameter:%lf\nOrbit diameter:%lf\nSystem:%s\n",
                ((Base*) temp)->name, ((Base*) temp)->mass, ((Base*) temp)->d, ((Planet*) temp)->orb_d, ((Planet*) temp)->system);
        }
        temp = temp->next;
    }
}

Base *create(TypeObject type, List* list){
    Base *base;
    switch(type)
    {
        case isStar:
            base = malloc(sizeof(Star));
            break;
        case isPlanet:
            base = malloc(sizeof(Planet));
            break;
    }
    base->type = type;
    add_item(list, (Node*) base);
    return base;
}