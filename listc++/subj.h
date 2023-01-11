#pragma once
#include "list.h"

enum class TypeObject
{
    None,
    isStar,
    isPlanet
};

class Base :public Node{
    private:
        std::string name;
        double mass;
        double d;
    protected:
        TypeObject type;
        Base(TypeObject type);
    public:
        Base *create(TypeObject type);
        void Print();
        const int Menu();
        void Input();
        TypeObject GetType()const;
};

class SubjList :public List{
    public:
        void sort();
        void search(std::string str)const;
        void Print()const;
    private:
        const int compare(Base *temp1, Base *temp2);
        int search_element(Base *temp, std::string str);
};