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

const int SubjList::compare_name(std::string temp1, std::string temp2)const{
    return (temp1.compare(temp2));
}

int SubjList::search_element(Base *temp, std::string str){
    if(compare_name(temp->GetName(), str) == 0)
        return true;
    else
        return false;
}

Base *SubjList::search(std::string str)const{
    Node *temp = this->GetHead();
    int i = 0;
    while(temp){
        if(static_cast<Base*>(temp)->GetName().compare(str) == 0){
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

void SubjList::sort(){
    if(this && this->Size() > 1){
        while(1){
            int i = 0;
            for(Node *temp = this->Head(); temp != NULL;){
                if(temp->GetNext() == NULL){
                    break;
                }
                int res = compare_name(static_cast<Base*>(temp)->GetSystem(), static_cast<Base*>(temp->GetNext())->GetSystem());
                int res_orb = static_cast<Base*>(temp)->GetOrb_d() > static_cast<Base*>(temp->GetNext())->GetOrb_d();
                if(res > 0 || (res_orb == true && !res)){
                    push_back(temp->GetNext());
                    i++;
                }
                else{
                    temp = temp->GetNext();
                }
            }
            if(i == 0){
                break;
            }
        }
    }
}

void SubjList::print_solar()const{
    for(Star *solar = static_cast<Star*>(this->GetHead()); solar; solar = static_cast<Star*>(solar->GetNext())){
        if(solar->GetType() == TypeObject::isStar){
        
            int planets = 0;
            Planet **arr = (Planet**)malloc(sizeof(Planet) * this->GetSize());
            Planet *temp = static_cast<Planet*>(this->GetHead());
            Planet *last_planet = NULL;
            for(int i = 0; i < this->GetSize(); i++){
                if(temp->GetType() == TypeObject::isPlanet){
                    if(compare_name(solar->GetName(), static_cast<Planet*>(temp)->GetSystem()) == 0){
                        arr[planets] = static_cast<Planet*>(temp);
                        planets++;
                        last_planet = temp;
                    }
                }
                temp = static_cast<Planet*>(temp->GetNext());
            }
            if(planets >= 2){
                for(int i = 0; i < planets; i++){
                    for(int k = 0; k < (planets - 1); k++){
                        if(arr[k]->GetOrb_d() > arr[k+1]->GetOrb_d()){
                            Planet *buff = arr[k];
                            arr[k] = arr[k+1];
                            arr[k+1] = buff;
                        }
                    }
                }
            }
            else{
                arr[0] = static_cast<Planet*> (last_planet);
            }

                solar->Print();
                for(int i = 0; i < this->GetSize(); i++){
                    if(arr[i] != NULL){
                        static_cast<Base*>(arr[i])->Print();
                        printf("\n");
                    }
                    else
                        break;
                }
                printf("-------------------------------\n");
                free(arr);
        }
    }
}

void SubjList::print_one(TypeObject type)const{
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