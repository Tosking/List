#include "list.h"

int main(){
    List list;
    Node *temp1 = new Node;
    Node *temp2 = new Node;
    list.add(temp1);
    list.add(temp2);
    list.add(new Node);
    list.insert(1, new Node);
    //list.insert(0, new Node);
    list.Print();

    return 0;
}