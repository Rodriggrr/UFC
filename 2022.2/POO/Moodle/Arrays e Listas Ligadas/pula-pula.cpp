#include <iostream>
#include <algorithm>// find
#include <list>
#include <sstream>
#include <memory>
#include <aux.hpp>

class Kid {
private:
    std::string name;
public:
    int age;
    Kid(std::string name, int age) {
        this->age = age;
        this->name = name;
    }
    int getAge() {
        return age;
    }
    std::string getName() {
        return name;
    }
    std::string str() {
        return name + ":" + std::to_string(age);
    }
};

using PtrKid = std::shared_ptr<Kid>;

std::ostream& operator<<(std::ostream& os,  PtrKid kid) {
    return (os << kid->str());
}

class Trampoline {
    std::list<PtrKid> waiting;
    std::list<PtrKid> playing;
    
    
    PtrKid removeFromList(std::string name, std::list<PtrKid>& lista) {
        std::list<PtrKid>::iterator it = std::find_if(lista.begin(), lista.end(), [name](PtrKid kid) { return kid->getName() == name; });
        if(it != lista.end())
            lista.erase(it);
        return nullptr;
    }
public:
    Trampoline() {
        waiting = std::list<PtrKid>();
        playing = std::list<PtrKid>();
    }
    
    void arrive(PtrKid kid) {
        waiting.push_front(kid);
    }

    void enter() {
        if (waiting.size() > 0) {
            playing.push_front(waiting.back());
            waiting.pop_back();
        }
    }

    void leave() {
        if (playing.size() > 0) {
            waiting.push_front(playing.back());
            playing.pop_back();
        }
    }

    PtrKid removeKid(std::string name) {
        if (playing.size() > 0){
            removeFromList(name, playing);
            removeFromList(name, waiting);
        }
        return nullptr;
    }
    std::string str() {
        std::string out;
        out += '[';
        for(auto i = waiting.begin(); i == waiting.end(); i++){
            if(i != waiting.begin())
                out += ", ";
            out += (*i)->str();
        }
        return out;
    }
};

int main() {
    aux::Chain chain;
    aux::Param param;
    Trampoline tr;
    chain["arrive"] = [&]() { tr.arrive(std::make_shared<Kid>(param[1], aux::to<int>(param[2]))); };
    chain["enter"]  = [&]() { tr.enter(); };
    chain["leave"]  = [&]() { tr.leave(); };
    chain["remove"] = [&]() { tr.removeKid(param[1]); };
    chain["show"]   = [&]() { std::cout << tr.str() << std::endl; };

    aux::execute(chain, param);
}