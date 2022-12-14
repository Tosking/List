#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void init_list(List *list){
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}
Node *__find_node(List *list, int index){
    Node *buff = NULL;
    if(index >= list->size || index < 0){
        return NULL;
    }
    int i = 0;
    if(index < (list->size / 2)){
        for(buff = list->head; i != index; buff = buff->next) i++;
        return buff;
    }
    else{
        i = list->size - 1;
        for(buff = list->tail; i != index; buff = buff->prev) i--;
        return buff;
    }
}

void add_item(List *list, Node *item){
    if(list->size != 0){
        item->prev = list->tail;
        list->tail->next = item;
        list->tail = item;
    }
    else{
        list->head = item;
        list->tail = item;
    }
    list->size++;
    item->next = NULL;
}

void print(List *list){
    if(list->size == 0){
        return;
    }
    int i = 0;
    Node *buff = list->head;
    printf("List:%p\tHead:%p\tTail:%p\n", list, list->head, list->tail);
    printf("#\tp\t\tprev\t\tnext\n");
    for(buff = list->head; buff != NULL; buff = buff->next){
        printf("%d.\t%p\t%p\t%p\n", i, buff, buff->prev, buff->next);
        i++;
    }
}

Node *remove_item(List *list, int index){
    Node *buff;
    buff = __find_node(list, index);
    if(buff == NULL){
        return NULL;
    }
    if(buff->prev != NULL){
        buff->prev->next = buff->next;
    }
    else {
        list->head = buff->next;
    }
    if(buff->next != NULL){
        buff->next->prev = buff->prev;
    }
    else {
        list->tail = buff->prev;
    }
    list->size--;
    return buff;
}

void delete_item(List *list, int index){
    Node *buff;
    free(remove_item(list, index));
}

void insert_item(List *list, int index, Node *buff){
    Node *temp = __find_node(list, index);
    if(temp == NULL){
        return;
    }
    if(temp->prev != NULL){
        temp->prev->next = buff;
    }
    else{
        list->head = buff;
    }
    buff->prev = temp->prev;
    temp->prev = buff;
    buff->next = temp;
    list->size++;
}

void clear(List *list){
    int i = 0;
    for(Node *temp = list->head; i < list->size; temp = temp->next){
        delete_item(list, i);
        i++;
        if(temp == NULL){
            break;
        }
        if(temp->next == NULL){
            break;
        }
    }
    list->size = 0;
}

int get_index(List *list, Node *pointer){
    int i = 0;
    for(Node *temp = list->head; i < list->size; temp = temp->next){
        if(pointer == temp){
            return i;
        }
        if(temp->next == NULL){
            break;
        }
        i++;
    }
}

void push_back(List *list, Node *item){
    Node *buf = item->prev;
    if(item == list->head)
        return;
    if(buf != list->head){
        buf->prev->next = item;
    }
    else
        list->head = item;
    if(item != list->tail)
        item->next->prev = item->prev;
    else
        list->tail = item->prev;
    item->prev = buf->prev;
    buf->next = item->next;
    item->next = buf;
    buf->prev = item;
}