#include <iostream>
#include <string>
#include "subj.h"

class Star :public Base{
    private:
        double t;
        double size;
        double earth_d;
    public:
        Star();
        void Print();
        void Input();
};

class Planet :public Base{
    private:
        std::string system;
        double orb_d;
    public:
        Planet();
        void Print();
        void Input();
};