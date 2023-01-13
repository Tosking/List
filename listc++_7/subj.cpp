#include <iostream>
#include <string>
#include <cstring>
#include "subj.h"

class Star :public Base{
    private:
        double t;
        double size;
        double earth_d;
    public:
        Star();
        TypeObject GetType()const;
        double GetOrb_d()const;
        std::string GetSystem()const;
        void Print();
        void Input();
};

class Planet :public Base{
    private:
        std::string system;
        double orb_d;
        const int compare_orb_d(Planet *temp1, Planet *temp2)const;
    public:
        Planet();
        TypeObject GetType()const;
        std::string GetSystem()const;
        double GetOrb_d()const;
        void Print();
        void Input();
};

std::string Planet::GetSystem()const{
    return system;
}

double Planet::GetOrb_d()const{
    return orb_d;
}

std::string Base::GetName()const{
    return name;
}

Base& SubjList::operator[](const size_t index){
    return *static_cast<Base*>(GetNode(index));
}

const bool Base::operator ==(const TypeObject type)const{
    return GetType() == type;
}

const bool Base::operator ==(const std::string str)const{
    return GetName().compare(str);
}

Base::Base(){}
Planet::Planet():Base(){}
Star::Star():Base(){}

TypeObject Planet::GetType()const{
    return TypeObject::isPlanet;
}

TypeObject Star::GetType()const{
    return TypeObject::isStar;
}

double Star::GetOrb_d()const{
    return 0;
}

std::string Star::GetSystem()const{
    return Base::GetName();
}

Base *create(TypeObject type){
    Base *temp = nullptr;
    switch (type)
    {
    case TypeObject::isPlanet:
        temp = new Planet;
        temp = static_cast<Planet*>(temp);
        break;

    case TypeObject::isStar:
        temp = new Star;
        temp = static_cast<Planet*>(temp);
        break;
    default:
        break;
    }
    return temp;
}

void Base::Print(){
    if(this){
        std::cout << "Name:" << name << std::endl
            << "Mass:" << mass << std::endl
            << "Diameter:" << d << std::endl;
    }
}

void SubjList::Print()const{
    if(this){
        if(this->Head())
            for(Node *base = Head(); base; base = base->GetNext())
                static_cast<Base*>(base)->Print();
        else
            std::cout << "List is empty" << std::endl;
    }
}

void Base::Input(){
    std::cout << std::endl;
    std::cout << "Enter name:" << std::endl;
    std::cin >> name;
    std::cout << "Enter mass:" << std::endl;
    std::cin >> mass;
    std::cout << "Enter diameter:" << std::endl;
    std::cin >> d;
    
}

void Star::Print(){
    Base::Print();
    std::cout << "Temperature:" << t << std::endl
    << "Size:" << size << std::endl
    << "Earth Distance:" << earth_d << std::endl;
    std::cout << std::endl;
}

void Planet::Print(){
    Base::Print();
    std::cout << "System:" << system << std::endl
    << "Orbit diameter:" << orb_d << std::endl;
    std::cout << std::endl;
}

void Star::Input(){
    Base::Input();
    std::cout << "Enter Temperature:" << std::endl;
    std::cin >> t;
    std::cout << "Enter Size:" << std::endl;
    std::cin >> size;
    std::cout << "Enter Earth Distance:" << std::endl;
    std::cin >> earth_d;
}

void Planet::Input(){
    Base::Input();
    std::cout << "Enter System:" << std::endl;
    std::cin >> system;
    std::cout << "Enter Orbit diameter:" << std::endl;
    std::cin >> orb_d;
}

int SubjList::search_element(Base *temp, std::string str){
    if((*temp == str) == 0)
        return true;
    else
        return false;
}

Base *SubjList::search(std::string str)const{
    Node *temp = this->GetHead();
    int i = 0;
    while(temp){
        if((*static_cast<Base*>(temp) == str) == 0){
            return static_cast<Base*>(temp);
        }
        temp = temp->GetNext();
        i++;
    }
    return nullptr;
}

void SubjList::delete_item(Base *temp){
    delete temp;
}

const bool Base::operator >(const Base &temp)const{
    int res = GetSystem().compare(temp.GetSystem());
    int res_orb = GetOrb_d() > temp.GetOrb_d();
    return (res > 0 || (!res && res_orb == true));
}

void SubjList::sort(){
    if(this && this->Size() > 1){
        int n = GetSize();
        SubjList L = *this;
        for(int i = 0; i < n - 1; i++){
            for(int k = i + 1; k < n; k++){
                if(L[i] > L[k]){
                    push_back(static_cast<Node*>(&L[k]));
                }
            }
        }
    }
}

void SubjList::Print(TypeObject type)const{
    if(this){
        switch (type)
        {
        case TypeObject::isPlanet:{
            Planet *temp = static_cast<Planet*>(this->GetHead());
            while(temp){
                if(temp->GetType() == type){
                    temp->Print();
                    std::cout << std::endl;
                }
                temp = static_cast<Planet*>(temp->GetNext());
            }
            break;
        }
        case TypeObject::isStar:{
            Star *temp = static_cast<Star*>(this->GetHead());
            while(temp){
                if(temp->GetType() == type){
                    temp->Print();
                    std::cout << std::endl;
                }
                temp = static_cast<Star*>(temp->GetNext());
            }
        }
        default:
            break;
        }
    }
}