#pragma once
#include <iostream>
class List;

class Node{
    private:
        Node *next;
        Node *prev;
        List* list;
    public:
        Node();
        ~Node();
        Node *GetNext() const;
        friend class List;
};

class List{
    private:
        Node *head;
        Node *tail;
        size_t size;
    public:
        List();
        ~List();
        void add(Node* temp);
        Node* GetNode(const size_t index);
        const int GetSize()const;
        Node* GetHead()const;
        void insert(size_t index, Node* temp);
        void clear();
        const size_t Size();
        Node *remove(const size_t index);
        Node *remove_node(Node *node);
        void push_back(Node *item);
        void Print();
    protected:
        Node *Head()const;
};