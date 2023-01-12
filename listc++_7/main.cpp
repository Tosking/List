#include "subj.h"
#include <iostream>
#include <string>

int main(){
    SubjList list;
    while(1){
        int var = 0;
        std::string str;
        std::cout << "1.Add Item" << std::endl
                << "2.Delete Item" << std::endl
                << "3.Sort list" << std::endl
                << "4.Search Item" << std::endl
                << "5.Print List" << std::endl
                << "6.Clear List" << std::endl
                << "7.Type one type items" << std::endl;
        std::cin >> var;
        switch(var){
            case 1:{
                TypeObject type;
                int i = 0;
                std::cout << "Enter object type (1 - star, 2 - planet):" << std::endl;
                std::cin >> i;
                type = static_cast<TypeObject>(i);
                Base *temp = create(type);
                temp->Input();
                list.add(static_cast<Node*>(temp));
                break;
            }
            case 2:{
                std::cout << "Enter item name that you want to delete:";
                std::cin >> str;
                list.delete_item(list.search(str));
                break;
            }
            case 3:{
                list.sort();
                break;
            }
            case 4:{
                std::cout << "Enter item name that you want to find:";
                std::cin >> str;
                (list.search(str))->Print();
                break;
            }
            case 6:{
                list.clear();
                break;
            }
            case 7:{
                TypeObject type;
                int i = 0;
                std::cout << "Enter object type (1 - star, 2 - planet):" << std::endl;
                std::cin >> i;
                type = static_cast<TypeObject>(i);
                list.print_one(type);
            }
            case 5:
                list.Print();
                break;
            default:
                break;

        }
    }

    return 0;
}