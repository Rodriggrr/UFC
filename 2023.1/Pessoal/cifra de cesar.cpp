#include <iostream>

bool check_letter(int a)
{
    if((a > 96 && a < 96 + 26) or (a > 64 && a < 65 + 26))
        return true;
    return false;
}

char move_letter(char c, const int &key){
    c += key;
    if(!check_letter(c))
        c -= 26;

    return c;
}

std::string criptografar(std::string palavra, const int &key){
    for(auto i = 0; i < palavra.length(); i++)
        palavra[i] = move_letter(palavra[i], key);

    return palavra;
}

int loop(std::string palavra, int key)
{
    while(key != 0){
        std::cout << "Escreva a palavra a ser Cifrada:\n";
        std::cin >> palavra;
        std::cout << "Escolha uma chave entre 1 e 25:\n";
        std::cin >> key;
        if(key == 0){
            std::cout << "Encerrando...\n";
            continue;
        } 
        else if(key > 25 or key < 1){
            std::cout << "Chave inválida. Repita.\n";
            continue;
        }
        palavra = criptografar(palavra, key);
        std::cout << "Sua palavra cifrada: " + palavra + '\n';
    }

    return 0;
}


int main()
{
    std::string palavra;
    int key;
    loop(palavra, key);
    return 0;
}