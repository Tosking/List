#include "list.h"
Node *Node::GetNext() const{
    return next;
}

Node::Node(){
    next = nullptr;
    prev = nullptr;
    list = nullptr;
}

Node::~Node()noexcept{
    list->remove_node(this);
}

List::List(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

List::~List(){
    clear();
}

const size_t List::Size(){
    return size;
}

Node *List::Head()const{
    return head;
}

const int List::GetSize()const{
    return size;
}

Node* List::GetHead()const{
    return head;
}

void List::clear(){
    if(this){
        Node* temp = head;
        Node* next = nullptr;
        while(temp){
            next = temp->next;
            delete temp;
            temp = next;
        }
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
}

Node *List::GetNode(const size_t index){
    if(index < size && index >= 0){
        Node *temp = head;
        int i = 0;
        while(temp && i < index){
            temp = temp->next;
            i++;
        }
        return temp;
    }
    return nullptr;
}

Node *List::remove_node(Node *node){
    if(node && this){
        if(node->prev)
            node->prev->next = node->next;
        else
            if(node->next != nullptr)
                head = node->next;
        if(node->next)
            node->next->prev = node->prev;
        else
            if(node->prev != nullptr)
                tail = node->prev;
        size--;
        node->list = nullptr;
        return node;
    }
    else return nullptr;
}

void List::add(Node *node){
    if(this && !node->list && node){
        node->list = this;
        node->prev = tail;
        if(!head)
            head = node;
        else
            node->prev->next = node;
        tail = node;
        size++;
    }
}

void List::insert(size_t index, Node *node){
    Node *temp = GetNode(index);
    if(index < size && index >= 0){
        if(!index){
            head = node;
            node->next = temp;
        }
        else {
            temp->prev->next = node;
            node->prev = temp->prev;
        }
        if(index == size)
            tail = node;
        else {
            node->next = temp;
            temp->prev = node;
        }
        size++;
    }
}

void List::Print(){
    std::cout << "List:" << this << "\t"
            << "Head:" << head << "\t"
            << "Tail:" << tail << std::endl;
    
    Node *temp = head;
    for(int i = 0; temp; i++, temp = temp->next){
        std::cout << i << "\t" << temp << "\t" << temp->prev << "\t" << temp->next << std::endl;
    }
}

void List::push_back(Node *item){
    Node *buf = item->prev;
    if(item == head)
        return;
    if(buf != head){
        buf->prev->next = item;
    }
    else
        head = item;
    if(item != tail)
        item->next->prev = item->prev;
    else
        tail = item->prev;
    item->prev = buf->prev;
    buf->next = item->next;
    item->next = buf;
    buf->prev = item;
}