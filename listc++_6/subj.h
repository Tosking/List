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
        std::string GetName()const;
};

class SubjList :public List{
    public:
        void sort();
        void print_solar()const;
        Base *search(std::string str)const;
        void delete_item(Base *temp);
        void Print()const;
        void print_one(TypeObject type)const;
    private:
        const int compare_name(std::string temp1, std::string temp2)const;
        int search_element(Base *temp, std::string str);
};

Base *create(TypeObject type);