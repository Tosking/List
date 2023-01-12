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
    public:
        Base();
        virtual TypeObject GetType()const = 0;
        virtual double GetOrb_d()const = 0;
        virtual std::string GetSystem()const = 0;
        virtual void Print();
        virtual void Input();
        const bool operator >(const Base &temp)const;
        const bool operator ==(const TypeObject type)const;
        const bool operator ==(const std::string str)const;
        std::string GetName()const;
};

class SubjList :public List{
    public:
        void sort();
        Base *search(std::string str)const;
        void delete_item(Base *temp);
        void Print()const;
        void print_one(TypeObject type)const;
    private:
        int search_element(Base *temp, std::string str);
        Node& operator[](const size_t index);
};

Base *create(TypeObject type);