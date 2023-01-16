#include <iostream>
#include <array>
#include "rod.hpp"
#include <list>

class Pass
{
    int age{};
    std::string name{};
public:
    Pass(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    int getAge(){  
        return age;
    }

    std::string getName(){
        return name;
    }

    bool isPriority(){
        return age >= 65;
    }

    void setAge(int age){
        this->age = age;
    }

    void setName(std::string name){
        this->name = name;
    }

    std::string toString(){
        return name + " " + std::to_string(age);
    }
};

class Topic
{
    std::array<Pass, NULL> normalSeats;
    std::array<Pass, NULL> prioritySeats;
public:
    static int findFree(std::array<Pass, NULL> list){
        for (int i = 0; i < list.size(); i++)
            if (list[i].getName() == "")
                return i;
        return -1;
    }

    static int findName(std::array<Pass, NULL> list, std::string name){
        for (int i = 0; i < list.size(); i++)
            if (list[i].getName() == name)
                return i;
        return -1;
    }
    
    static bool insert(std::array<Pass, NULL> list, Pass pass){
        int index = findFree(list);
        if (index == -1)
            return false;
        list[index] = pass;
        return true;
    }

    static bool remove(std::array<Pass, NULL> list, std::string name){
        int index = findName(list, name);
        if (index == -1)
            return false;
        list[index] = Pass("", 0);
        return true;
    }
};

int main()
{
    
}
