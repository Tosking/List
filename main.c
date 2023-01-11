#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "subj.h"

int main(){
    List *list = (List*)malloc(sizeof(List));
    init_list(list);
    Base *temp;
    while(1){
        fflush(stdin);
        char buff[100];
        int index;
        int var = 0;
        printf(" 1.add item\n \
2.delete item\n \
3.print list\n \
4.search\n \
5.sort\n \
6.clear \n \
7.get_index \n \
8.sort by solar system\n \
9.print one type objects\n \
                ");
        scanf("%d", &var);
        switch (var)
        {
        case 1:
            printf("Enter object type (1 - star, 2 - planet):");
            scanf("%d", &var);
            create(var, list);
            insert((Base*) list->tail, ALL, var);
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
            printf("Enter name of a object, that you want to print:");
            scanf("%s", &buff);
            search(list, buff);
            break;
        case 5:
            sort(list);
            break;
        case 6:
            clear(list);
            break;
        case 7:
            printf("Enter pointer:");
            Node *pointer;
            scanf("%p", &pointer);
            printf("Index:%d\n", get_index(list, pointer));
        case 8:
            print_solar(list);
        case 9:
            printf("Enter object type (1 - star, 2 - planet):");
            scanf("%s", &buff);
            print_one(list, buff);
        default:
            break;
        }
    }
}