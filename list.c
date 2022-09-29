#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
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
Node *__find_node(List *list, int index){
    Node *buff = NULL;
    int i = 0;
    if(index < (list->size / 2)){
        for(buff = list->head; i != index; buff = buff->next) i++;
        return buff;
    }
    else{
        for(buff = list->tail; i != index; buff = buff->prev) i++;
        return buff;
    }
}

void add_item(List *list){
    Node *item = (Node*)malloc(sizeof(Node));
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

void print_list(List *list){
    if(list->size == 0){
        return;
    }
    int i = 0;
    Node *buff = list->head;
    printf("List:%p\tHead:%p\tTail:%p\n", list, list->head, list->tail);
    printf("#\tp\t\tprev\t\tnext\n");
    for(buff = list->head; buff != NULL; buff = buff->next){
        printf("%d.\t%p\t%p\t%p\n", i, buff, buff->prev, buff->next);
    }
}

void remove_item(List *list, int index){
    Node *buff;
    buff = __find_node(list, index);
    buff->prev->next = buff->next;
    buff->next->prev = buff->prev;
    list->size--;
}

void delete_item(List *list, int index){
    Node *buff;
    buff = __find_node(list, index);
    remove_item(list, index);
    free(buff);
}

int main(){
    List *list = (List*)malloc(sizeof(List));
    init_list(list);
    add_item(list);
    add_item(list);
    add_item(list);
    delete_item(list, 1);
    print_list(list);
    return 0;
}
