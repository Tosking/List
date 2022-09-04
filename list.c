#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int index;
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
        item->index = list->tail->index + 1;
        item->prev = list->tail;
        list->tail->next = item;
        list->tail = item;
    }
    else{
        list->head = item;
        list->tail = item;
        item->index = 0;
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
        buff = buff->next;
        printf("%d\n", buff->data);
    }
}

int get_data(List *list, int index){
    Node *buff;
    if(index < (list->size / 2)){
        for(buff = list->head; buff->index != index; buff = buff->next);
        if(buff != NULL){
            return buff->data;
        }
        else{
            return 0;
        }
    }
    else{
        for(buff = list->tail; buff->index != index; buff = buff->prev);
        if(buff != NULL){
            return buff->data;
        }
        else{
            return 0;
        }
    }
}

int main(){
    List *list;
    init_list(list);
    add_item(list, 10);
    add_item(list, 20);
    add_item(list, 30);
    print_list(list);
    printf("\t%d", get_data(list, 1));
    return 0;
}