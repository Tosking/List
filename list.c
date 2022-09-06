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
Node *__find_node(List *list, int index){
    Node *buff = NULL;
    if(index < (list->size / 2)){
        for(buff = list->head; buff->index != index; buff = buff->next);
        return buff;
    }
    else{
        for(buff = list->tail; buff->index != index; buff = buff->prev);
        return buff;
    }
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
    printf("List:%p\tHead:%p\tTail:%p\n", list, list->head, list->tail);
    printf("#\t\tp\t\tprev\t\tnext\n");
    for(buff = list->head; buff != NULL; buff = buff->next){
        printf("%d.\t%d\t%p\t%p\t%p\n", buff->index, buff->data, buff, buff->prev, buff->next);
    }
}

int get_data(List *list, int index){
    Node *buff;
    buff = __find_node(list, index);
    if(buff != NULL){
        return buff->data;
    }
    else{
        return 0;
    }
}

void remove_item(List *list, int index){
    Node *buff;
    buff = __find_node(list, index);
    buff->prev->next = buff->next;
    buff->next->prev = buff->prev;
    list->size--;
    for(buff = buff->next; buff != NULL; buff = buff->next)
        buff->index--;
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
    add_item(list, 10);
    add_item(list, 20);
    add_item(list, 30);
    delete_item(list, 1);
    print_list(list);
    int x = get_data(list, 1);
    printf("%d", x);
    return 0;
}
