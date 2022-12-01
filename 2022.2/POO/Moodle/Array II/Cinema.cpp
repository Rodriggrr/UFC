#include <iostream>
#include "rod.hpp"
#include <vector>
#include <memory>



class Client
{
    std::string fone;
    std::string id;

public:
    Client(std::string id, std::string fone){
        this->id = id;
        this->fone = fone;
    }

    std::string getFone() { return fone; }
    std::string getId() { return id; }
    void setFone(std::string fone) { this->fone = fone; }
    void setId(std::string id) { this->id = id; }

    std::string toString(){
        return "Id: " + id + " Fone: " + fone;
    }
};

using Ptr = std::shared_ptr<Client>;

class Sala
{
    std::vector<Ptr> cadeiras;
    
    bool verificarIndice(int indice){
        if(indice < 0 || indice > (int)cadeiras.size()){
            return false;
        }
        return true;
    }


    int procurar(std::string nome){
        for(int i = 0; i < (int)cadeiras.size(); i++){
            if(cadeiras[i]->getId() == nome && verificarIndice(i)){
                return i;
            }
        }
        return -1;
    }

public:
    Sala(int capacidade){
        cadeiras.resize(capacidade);
        rod::fill(cadeiras, nullptr);
    }
};

int main()
{
    Sala s(10);
    return 0;
}