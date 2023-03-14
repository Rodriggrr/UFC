#include <iostream>

int trials = 6;

//Preenche a palavra com a quantidade certa de chars.
void fill_result(std::string &s, const std::string word)
{
    for(auto a : word)
    if(a == '-')
        s += '-';
    else    
        s += '*';
}

//Printa o resultado.
//Achei autoexplicativo.
void print_result(std::string &r)
{
    for(auto a : r)
    if(a == '*')
        std::cout << "_ ";
    else if (a == '-')
        std::cout << "- ";
    else
        std::cout << (char)a << " ";
    
    std::cout << " Tentativas restantes: " << trials << std::endl;
}

//Jogo em si.
bool game(std::string word)
{
    //Result armazena a palavra com os acertos até agora.
    //Preenchemos a palavra para ficar do tamanho da palavra-alvo.
    //Printamos o tamanho da palavra.
    std::string result;
    fill_result(result, word);
    std::cout << "A palavra tem " << word.size() << " letras.\n";

    //Printamos a palavra "result", de acordo com as regras da função.
    print_result(result);

    //Enquanto houver tentativas.
    while (trials > 0)
    {
        //Diminui uma tentativa, espera o jogador escrever o chute, se é uma letra ou uma palavra.
        trials--;
        std::string chance;
        std::cin >> chance;

        //Se for uma palavra e estiver correto, ganha.
        //Caso contrário, perde.
        if(chance.size() > 1)
            if(chance == word)
                return true;
             else 
                return false;
        
        //Procura em que canto da palavra-alvo tem a letra, caso o chute seja uma letra.
        //Se tiver, muda a letra no local indicado do result.
        for(auto i = 0; i < word.size(); i++)
        if(word[i] == chance[0])
            result[i] = chance[0];
        
        //Printa o resultado para saber o progresso.
        print_result(result);
        
        //Se o resultado for igual à palavra, ganha.
        if(result == word)
            return true;

    }
    //Se acabarem as tentativas, perde.
    return false;
}

//Menu do jogo. Como são duas opções, não é necessário utilizar um switch.
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

//Retorna o cursor do terminal para o começo da palavra, e printa espaços
//de acordo com o tamanho da palavra.
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

    //Apaga a palavra para quem adivinha não saber.
    erase_word(word); 

    //Modifica as tentativas de acordo com o número de letras. 
    //Printa as tentativas.
    trials += ((word.size()) - 6) / 2;
    std::cout << "Você tem " << trials << " tentativas. Adivinhe.\n";

    //Condicionamento para caso ganhe ou perca.
    //Se ganhar, ganhou. Se perder, mostra a palavra.
    if(game(word))
        std::cout << "Você ganhou! :D\n";
    else
        std::cout << "Você perdeu... D:\nA palavra era: " << word << '\n';
}