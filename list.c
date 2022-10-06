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
        i = list->size;
        for(buff = list->tail; i != index; buff = buff->prev) i--;
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
        i++;
        printf("%d.\t%p\t%p\t%p\n", i, buff, buff->prev, buff->next);
    }
}

void remove_item(List *list, int index){
    Node *buff;
    printf("%d", index);
    buff = __find_node(list, index);
    if(buff->prev != NULL){
        buff->prev->next = buff->next;
    }
    if(buff->next != NULL){
        buff->next->prev = buff->prev;
    }
    list->size--;
}

void delete_item(List *list, int index){
    Node *buff;
    buff = __find_node(list, index);
    remove_item(list, index);
    free(buff);
}

void insert(List *list, int index, Node *buff){
    Node *temp = __find_node(list, index);
    temp->prev->next = buff;
    buff->prev = temp->prev;
    buff->next = temp;
}

void clear(List *list){
    int i = 0;
    for(Node *temp = list->head; temp != NULL; temp = temp->next)
        delete_item(list, ++i);
    
}

int main(){
    List *list = (List*)malloc(sizeof(List));
    init_list(list);
    while(1){
        int index;
        int var = 0;
        printf(" 1.add item\n \
2.delete item\n \
3.print list\n \
4.find node\n \
5.insert node\n \
6.clear \n \
                ");
        scanf("%d", &var);
        switch (var)
        {
        case 1:
            add_item(list);
            break;
        case 2:
            printf("Enter index, that you want to delete:");
            scanf("%d", &index);
            delete_item(list, index);
            break;
        case 3:
            print_list(list);
            break;
        case 4:
            printf("Enter index, that you want to print:");
            scanf("%d", &index);
            Node *buff = __find_node(list, index);
            printf("p\t\tprev\t\tnext\n");
            printf("%p\t%p\t%p\n", buff, buff->prev, buff->next);
            break;
        case 5:
            printf("Enter index, in what you what to insert item:");
            scanf("%d", &index);
            buff = (Node*) malloc(sizeof(Node));
            insert(list, index, buff);
            break;
        case 6:
            clear(list);
            break;
        default:
            break;
        }
    }
    return 0;
}
