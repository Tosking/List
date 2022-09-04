#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    size_t size;
    Node *head;
    Node *tail;
} List;

void init_list(List *list){
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

void add_item(List *list, int value){
    Node *item = (Node*)malloc(sizeof(Node));
    if(list->size != 0){
        item->prev = list->tail;
        list->tail->next = item;
    }
    else{
        list->head = item;
        list->tail = item;
    }
    list->size++;
    item->next = NULL;
    item->data = value;
}

void print_list(List *list){
    if(list->size == 0){
        return;
    }
    Node *buff = list->head;
    printf("%d\n", buff->data);
    while(buff != list->tail){
        printf("%d\n", buff->data);
        buff = buff->next;
    }
}

void main(){
    List *list;
    init_list(list);
    add_item(list, 10);
    print_list(list);
}