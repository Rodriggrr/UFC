#include <iostream>

int trials = 6;

void fill_result(std::string &s, const std::string word)
{
    for(auto a : word)
        s += '*';
}

void print_result(std::string &r)
{
    for(auto a : r)
    if(a == '*')
        std::cout << "_ ";
    else
        std::cout << (char)a << " ";
    
    std::cout << " Tentativas restantes: " << trials;

    std::cout << std::endl;
}

bool game(std::string word)
{
    std::string result;
    fill_result(result, word);
    std::cout << "A palavra tem " << word.size() << " letras.\n";
    print_result(result);

    while (trials > 0)
    {
        trials--;
        std::string chance;
        std::cin >> chance;

        if(chance.size() > 1)
            if(chance == word)
                return true;
             else 
                return false;
        
        for(auto i = 0; i < word.size(); i++)
        if(word[i] == chance[0])
            result[i] = chance[0];
        
        if(result == word)
            return true;

        print_result(result);
    }
    return false;
}

void menu()
{
    std::cout << "Jogo da forca.\n\n1. Jogar\n2. Instruções\n";
    int choice;
    std::cin >> choice;
    if(choice == 1)
        return;
    else
        std::cout << "Você tem 6 tentativas que mudam de acordo com o tamanho da palavra. Escreva letras e adivinhe. Seu amigo escreverá a palavra para você.\nO jogo começou.\n";

    return;
}

void erase_word(const std::string &word)
{
    std::cout << '\r' << "\x1b[A";
    for(auto a : word)
        std::cout << " ";
    std::cout << '\n';
}

int main()
{
    menu();
    std::cout << "Escreva a palavra para outros adivinharem:\n";
    std::string word;
    std::cin >> word;
    erase_word(word);

    trials += ((word.size()) - 6) / 2;
    std::cout << "Você tem " << trials << " tentativas. Adivinhe.\n";


    if(game(word))
        std::cout << "Você ganhou! :D\n";
    else
        std::cout << "Você perdeu... D:\nA palavra era: " << word << '\n';
}