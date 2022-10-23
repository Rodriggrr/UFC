#include <iostream>
#include <sstream>
#include <memory>
#include <auxiliar.hpp>

class Person {
    std::string name; //atributo
    int age;
public:
    Person(std::string name = "", int age = 0) {
        this->name = name;
        this->age = age;
    }

    int getAge() {
        return age; 
    }
    std::string getName() {
        return name;
    }
    std::string str() {
        std::ostringstream oss;
        oss << name << ":" << age;
        return oss.str();
    }
};

std::ostream& operator<<(std::ostream& os, Person& p) {
    return os << p.str();
}

class Motorcycle {
    std::shared_ptr<Person> person {nullptr}; //agregação
    int time {0};
    int power {1};

public:
    Motorcycle(int power = 1) {
        this->power = power;
    }


    bool insertPerson(std::shared_ptr<Person> p) {
        if(person == nullptr){
            person = p;
            return true;
        }
        std::cout << "fail: busy motorcycle\n";
        return false;
    }

    std::string honk() {
        std::string honk = "P";
        for(int i = 0; i < power; i++)
            honk += "e";
        honk += "m";
        return honk;
    }

    std::shared_ptr<Person> removePerson() {
        if(person != nullptr){
            auto p = person;
            person = nullptr;
            return  p;
        }
        std::cout << "fail: empty motorcycle\n";
        return nullptr;
    }

    void buyTime(int time) {
        this->time += time;
    }

    void drive(int time) {
        if(person == nullptr)
            std::cout << "fail: empty motorcycle\n";
        else if (this->time == 0)
            std::cout << "fail: buy time first\n";
        else if (this->time < time) {
            std::cout << "fail: time finished after " << this->time <<" minutes\n";
            this->time = 0;
        }
        else if (person->getAge() > 10)
            std::cout << "fail: too old to drive\n";
        else
            this->time -= time;
        return;
    }

    std::string str() const{
        std::ostringstream os;
        os << "power:" << power << ", time:" << time;
        os << ", person:(" << (person == nullptr ? "empty" : person->str()) << ")";
        return os.str();
    }
};

std::ostream& operator<<(std::ostream& os, const Motorcycle& m) {
    return os << m.str();
}


int main() {
    auxiliar::Chain chain;
    auxiliar::Param param;

    Motorcycle m(1);


    auto __int = [&](int index) { return auxiliar::to<int>(param[index]); };

    chain["show"]  = [&]() { auxiliar::show << m; };
    chain["leave"] = [&]() { 
        auto person = m.removePerson(); 
        if (person != nullptr) {
            auxiliar::show << *person;
        }
    };
    chain["honk"]  = [&]() { auxiliar::show << m.honk(); };
    chain["init"]  = [&]() { m = Motorcycle(__int(1));};
    chain["enter"] = [&]() { m.insertPerson(std::make_shared<Person>(param[1], __int(2))); };
    chain["buy"]   = [&]() { m.buyTime(__int(1)); };
    chain["drive"] = [&]() { m.drive  (__int(1)); };

    auxiliar::execute(chain, param);
}