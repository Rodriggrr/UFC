/*
1) Fiz sozinho.

2) Aprendi melhor a usar shared_ptr, tentei fazer a dureza do grafite usando enum, porém não
tenho o conhecimento o suficiente sobre enum e não consegui.

3)Fiz em um pouco menos de 1 hora.
*/



#include <iostream>
#include <sstream>
#include <memory>  //sharedptr
#include <iomanip> //setprecision
#include <utility> //exchange
#include <auxiliar.hpp>


class Lead {
    float thickness;
    std::string hardness;
    int size;

public:
    Lead(float thickness, std::string hardness, int size) {
        this->thickness = thickness; 
        this->hardness = hardness;
        this-> size = size;
    }

    float getThickness() const {
        return thickness;
    }

    std::string getHardness() const {
        return hardness;
    }

    int getSize() const {
        return size;
    }

    void setSize(int size) {
        this->size = size;
    }
    
    std::string str() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) 
           << thickness << ":" << hardness << ":" << size;
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& ss, Lead gr) {
    return ss << gr.str();
}

struct Pencil {
    float thickness {0.f};
    std::shared_ptr<Lead> tip {nullptr};

    Pencil(float thickness = 0.0) {
        this->thickness = thickness;
    }

    bool insert(std::shared_ptr<Lead> grafite) {
        if(tip != nullptr){
            std::cout << "fail: ja existe grafite\n";
            return false;
        }
        
        else if(grafite->getThickness() != this->thickness){
            std::cout << "fail: calibre incompativel\n";
            return false;
        }
        
        else
            this->tip = grafite;
            
        return true;
    }

    std::shared_ptr<Lead> remove() {
        if(tip != nullptr)
            tip = nullptr;
        else
            std::cout << "fail: nao existe grafite\n";
        return tip;
    }

    void writePage() {
        if(tip == nullptr){
            std::cout << "fail: nao existe grafite\n";
            return;
        }
        if(this->tip->getSize() <= 10){
            std::cout << "fail: tamanho insuficiente\n";
            return;
        }
        
      
        if(tip->getHardness() == "HB")
            tip->setSize(tip->getSize() - 1);
            
        else if(tip->getHardness() == "2B")
            tip->setSize(tip->getSize() - 2);
            
        else if(tip->getHardness() == "4B")
            tip->setSize(tip->getSize() - 4);
            
        else
            tip->setSize(tip->getSize() - 6);
            
        if(this->tip->getSize() < 10){
            std::cout << "fail: folha incompleta\n";
            tip->setSize(10);
            return;
        }
    }

    std::string str() {
        std::stringstream ss;
        ss << "calibre: " << thickness << ", grafite: ";
        if (tip != nullptr)
            ss << "[" << *tip << "]";
        else
            ss << "null";
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& os, Pencil l) {
    return os << l.str();
}

int main() {
    auxiliar::Chain chain;
    auxiliar::Param ui;

    Pencil pencil;

    auto tofloat = auxiliar::to<float>;
    auto toint   = auxiliar::to<int>;

    chain["show"]   = [&]() { std::cout << pencil << std::endl; };
    chain["init"]   = [&]() { pencil = Pencil(tofloat(ui[1])); };
    chain["insert"] = [&]() { pencil.insert(std::make_shared<Lead>(tofloat(ui[1]), ui[2], toint(ui[3]))); };
    chain["remove"] = [&]() { pencil.remove(); };
    chain["write"]  = [&]() { pencil.writePage(); };

    auxiliar::execute(chain, ui);
}