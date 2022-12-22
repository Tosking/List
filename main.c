#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "subj.h"

int main(){
    List *list = (List*)malloc(sizeof(List));
    init_list(list);
    Base *temp;
    while(1){
        int index;
        int var = 0;
        printf(" 1.add item\n \
2.delete item\n \
3.print list\n \
4.find node\n \
5.insert node\n \
6.clear \n \
7.get_index \n \
                ");
        scanf("%d", &var);
        switch (var)
        {
        case 1:
            printf("Enter object type (1 - star, 2 - planet):");
            scanf("%d", &var);
            create(var, list);
            add((Base*) list->tail, ALL, var);
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
            if(buff == NULL){
                printf("%p", buff);
                break;
            }
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
        case 7:
            printf("Enter pointer:");
            List *pointer;
            scanf("%p", &pointer);
            printf("Index:%d\n", get_index(list, pointer));
        default:
            break;
        }
    }
}