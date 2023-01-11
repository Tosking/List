#include "subj.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
            for(int i = 0; i <= Orb_d; i++){
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

void print_name(Base *temp) {
    printf("Name:%s\n", temp->name);
}

void print_type(Base *temp) {
    printf("Type:%lf\n", temp->name);
}

void print_mass(Base *temp) {
    printf("Mass:%lf\n", temp->mass);
}

void print_d(Base *temp) {
    printf("Diameter:%lf\n", temp->d);
}

void print_earth_d(Star *temp) {
    printf("Distance to Earth:%lf\n", temp->earth_d);
}

void print_size(Star *temp) {
    printf("Size:%lf\n", temp->size);
}

void print_t(Star *temp) {
    printf("Temperature:%lf\n", temp->t);
}

void print_system(Planet *temp) {
    printf("System:%s\n", temp->system);
}

void print_orb_d(Planet *temp) {
    printf("Orb diameter:%lf\n", temp->orb_d);
}

void print_item(Base *data, AddChoose choose){
    switch(choose){
        case Name:
            print_name(data);
            break;
        case Mass:
            print_mass(data);
            break;
        case D:
            print_d(data);
            break;
        case ALL:
            for(int i = 0; i <= Orb_d; i++){
                print_item(data, i);
            }
    }
    switch (data->type){
        case isStar:
            switch (choose){
                case Size:
                    print_size((Star*) data);
                    break;
                case Earth_d:
                    print_earth_d((Star*) data);
                    break;
                case T:
                    print_t((Star*) data);
                    break;
            }
            break;
        case isPlanet:
            switch(choose){
                case Orb_d:
                    print_orb_d((Planet*) data);
                    break;
                case System:
                    print_system((Planet*) data);
                    break;
            }
            break;
    }
    
}

void print_list(List *list){
    Node *temp = list->head;
    while(temp != NULL){
        print_item((Base*) temp, ALL);
        printf("\n");
        temp = temp->next;
    }
}

Base *create(TypeObject type, List* list){
    Base *base = NULL;
    switch(type)
    {
        case isStar:
            base = malloc(sizeof(Star));
            base->type = 1;
            break;
        case isPlanet:
            base = malloc(sizeof(Planet));
            printf("%d", sizeof(double));
            base->type = 2;
            break;
    }
    add_item(list, (Node*) base);
    return base;
}

int search_elements(Base* temp, const char *str){
    if(strstr(temp->name, str)){
        return 1;
    }
    else{
        return 0;
    }
}

void search(List* list, const char *str){
    Node *temp = list->head;
    while(temp != NULL){
        if(search_elements((Base *)temp, str)){
            print_item((Base *)temp, ALL);
        }
        temp = temp->next;
    }
}

void sort(List* list){
    int i = 0;
    for(Node *temp = list->head; temp != NULL; temp = temp->next){
        int k = 0;
        for(Node *itemp = temp->next; itemp != NULL; itemp = itemp->next){
            if(((Base*) temp)->d > ((Base*) itemp)->d){
                insert_item(list, i, itemp);
                delete_item(list, k);
                insert_item(list, k, temp);
                delete_item(list, i+1);
                temp = itemp;
                break;
            }
            k++;
        }
        i++;
    }
}