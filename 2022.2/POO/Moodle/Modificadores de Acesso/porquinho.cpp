/*
1) Fiz a partir dos aprendizados da aula do dia 15/9 em relação
à atividade. Fiz sozinho.

2) Aprendi muito sobre lógica de iteradores usando 'this->', e 
aprendi a interpretar um código que não foi feito por mim. 

3) Demorei da metade da aula de POO até o fim, e terminei em casa.
Foi mais ou menos uma hora e meia. Demorei mais pra entender o código e
como me eram pedidas as funções, já que havia faltado no dia anterior.
Depois de entender, fiz até que bem rápido.


GITHUB: Código não funcional sem o arquivo AUX.CPP, disponível apenas no Moodle2.
Dessa forma, código abaixo utilizado apenas como recordação e para fins de aprendizado.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <aux.hpp>

enum Coin {M10, M25, M50, M100};
struct CoinDef {
    float value;
    int volume;
};

CoinDef getDef(Coin coin) {
    switch (coin) {
        case M10: return {0.1, 1};
        case M25: return {0.25, 2};
        case M50: return {0.50, 3};
        case M100: return {1, 4};
    }
    return {0, 0};
}


class Item {
    std::string label;
    int volume;
public:
    Item(std::string label, int volume) {
        this->label = label;
        this->volume = volume;
    }
    int getVolume() const {
        return volume;
    }
    std::string getLabel() const {
        return label; 
    }
    void setVolume(int volume) {
        this->volume = volume;
    }
    void setLabel(std::string label) {
        this->label = label;
    }
    std::string str() const {
        return getLabel();
    }
};

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return os << item.str();
}

class Pig {
    std::vector<std::string> itens;
    double value {0};
    int volume {0};
    int volumeMax {0};
    bool broken {false};

public:
    Pig(int volumeMax = 0) {
        this->volumeMax = volumeMax;
    }
    
    bool addCoin(Coin coin) {
        int volAux = volume + getDef(coin).volume;
        if(volAux < volumeMax && !broken){
            value += getDef(coin).value;
            volume = volAux;
            return true;
        }
        std::cout << ((this->broken) ? "fail: the pig is broken\n" : "fail: the pig is full\n"); 
        return false;
    }

    bool addItem(Item item) {
        int volAux = volume + item.getVolume();
        if(volAux <= volumeMax && !broken)
        {
            itens.push_back(item.str());
            volume = volAux;
            return true;
        }
        
        std::cout << ((this->broken) ? "fail: the pig is broken\n" : "fail: the pig is full\n");
        return false;
    }

    bool breakPig() {
        broken = true;
        this->volume = 0;
        return true;
    }

    double getCoins() {
        if(broken){
            double coinAux = this->value;
            this->value = 0;
            return coinAux;
        }
        std::cout << "fail: you must break the pig first\n";
        return 0;
    }

    std::string getItens() {
        if(broken){
            std::stringstream ss;
            ss << aux::fmt(this->itens);
            itens.clear();
            return ss.str();
        }
        return "fail: you must break the pig first\n[]";
    }

    std::string str() const {
        std::stringstream ss;
        ss << aux::fmt(this->itens) << " : "
           << aux::fmt(value) << "$ : "
           << volume <<  "/" << volumeMax << " : " 
           <<  (broken ? "broken" : "unbroken");
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& os, const Pig& pig) {
    return os << pig.str();
}

int main() {
    aux::Chain chain;
    aux::Param par;

    Pig pig;
    
    auto toInt = aux::to<int>;

    chain["init"] = [&]() { pig = Pig(toInt(par[1])); };
    chain["addCoin"] = [&]() { 
        if      (par[1] == "10") pig.addCoin(M10);
        else if (par[1] == "25") pig.addCoin(M25);
        else if (par[1] == "50") pig.addCoin(M50);
        else if (par[1] == "100") pig.addCoin(M100);
    };
    chain["addItem"] = [&]() { pig.addItem(Item(par[1], toInt(par[2]))); };
    chain["break"] = [&]() { pig.breakPig(); };
    chain["getCoins"] = [&]() { aux::show << pig.getCoins(); };
    chain["getItens"] = [&]() { aux::show << pig.getItens(); };
    chain["show"] = [&]() {     aux::show << pig.str(); };

    aux::execute(chain, par);
}