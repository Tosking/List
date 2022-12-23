#include "subj.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Star{
    Base base;
    float t;
    float size;
    float earth_d;
} Star;

typedef struct Planet {
    Base base;
    char* system;
    float orb_d;
} Planet;

void __clear_input(){
    while(getchar() != EOF){
        printf("1\n");
    }
}

void insert_name(Base *data){
    scanf("%s", &data->name);
}
void insert_mass(Base *data){
    scanf("%lf", &data->mass);
}
void insert_d(Base *data){
    scanf("%lf", &data->d);
}
void insert_size(Star *data){
    scanf("%lf", &data->size);
}
void insert_earth_d(Star *data){
    scanf("%lf", &data->earth_d);
}
void insert_t(Star *data){
    scanf("%lf", &data->t);
}
void insert_orb_d(Planet *data){
    scanf("%lf", &data->orb_d);
}
void insert_system(Planet *data){
    scanf("%s", &data->system);
}

void insert(Base *data, AddChoose choose, TypeObject type){
    fflush(stdin);
    char *temp;
    switch(choose){
        case Name:
            printf("Name:");
            insert_name(data);
            break;
        case Mass:
            printf("Mass:");
            insert_mass(data);
            break;
        case D:
            printf("Diameter:");
            insert_d(data);
            break;
        case ALL:
            for(int i = 0; i < Orb_d; i++){
                insert(data, i, type);
            }
    }
    switch (type){
        case isStar:
            switch (choose){
                case Size:
                    printf("Size:");
                    insert_size((Star*) data);
                    break;
                case Earth_d:
                    printf("Distance to earth:");
                    insert_earth_d((Star*) data);
                    break;
                case T:
                    printf("Temperature:");
                    insert_t((Star*) data);
                    break;
            }
            break;
        case isPlanet:
            switch(choose){
                case Orb_d:
                    printf("Orbit diameter:");
                    insert_orb_d((Planet*) data);
                    break;
                case System:
                    printf("System:");
                    insert_system((Planet*) data);
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