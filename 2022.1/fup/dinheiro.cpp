#include <iostream>
#include <vector>
using namespace std;


int mesa = 0;
bool sair = false;
void mostrar_dinheiro(vector<int> jogador, int qntJog, int mesa, bool fora, vector<int> ign)
{
    cout << "Quantidade de Milho: " << endl;
    cout << "Mesa: " << mesa << endl;
    for(int i = 1; i <= qntJog; i++)
    {
        bool ignore = false;
        if(jogador.at(i - 1) == 0)
        {
            cout << "Jogador " << i << " tá zerado, pobre, dá até pena.\n";
            ignore = true;
        }
        if(fora)
        {
            for(int  j = 0; j < ign.size(); j++)
            {
                if(i == (ign.at(j) + 1))
                    ignore = true;
            }
        }
        if(!ignore)
        {
        cout << "Jogador " << i 
                << ": " << jogador.at(i - 1) 
                << endl;
        }
    }
}

vector<int> dinheiro_mesa_jogador(vector<int> jogador, int quantidade, int qntJog, bool fora, vector<int> ign)
{
    if(quantidade == 0)
    {
        
        for(int i = 0; i < jogador.size(); i++)
        {
            bool ignore = false;
            if(fora)
            {
                for(int  j = 0; j < ign.size(); j++)
                {
                    if(i == ign.at(j))
                        ignore = true;
                }
            }
            if(!ignore)
            {
            mesa += jogador.at(i);
            jogador.at(i) = 0;
            }            
        }
        return jogador;
    }
    else
    {
        for(int i = 0; i < jogador.size(); i++)
        {
            bool ignore = false;
            if(fora)
            {
                for(int  j = 0; j < ign.size(); j++)
                {
                    if(i == ign.at(j))
                        ignore = true;
                }
            }
            if(!ignore)
            {
            mesa += quantidade;
            jogador.at(i) -= quantidade;
            }
        }
        return jogador;
    }
}

int dinheiro_jog(vector<int> jogador, int qntJog)
{
    vector<int> ign;
    while(true)
    {
        int sel1, sel2, qnt;
        cin >> sel1;
        char op, ch;
        cin >> op;
        switch(op){
            case '<':
                cin >> sel2 >> qnt;
                if(jogador.at(sel2 - 1) - qnt < 0)
                {
                    cout << "Você não tem dinheiro o suficiente!" << endl;
                    continue;
                }
                jogador.at(sel1 - 1) += qnt;
                jogador.at(sel2 - 1) -= qnt;
                break;
            case '>':
                cin >> sel2 >> qnt;
                if(jogador.at(sel1 - 1) - qnt < 0)
                    {
                        cout << "Você não tem dinheiro o suficiente!" << endl;
                        continue;
                    }
                jogador.at(sel2 - 1) += qnt;
                jogador.at(sel1 - 1) -= qnt;
                break;

            case 't': 
                cout << "Jogador " << sel1 << " apostou tudo!\nTodos os jogadores vão cobrir a aposta? (s/n)\n";
                cin >> ch;
                if(ch == 's')
                    {
                       jogador = dinheiro_mesa_jogador(jogador, 0, qntJog, sair, ign);
                    }
                    else
                    {
                        cout << "Diga quais jogadores vão sair da jogada, e digite \"0\" quando terminar.\n";
                        while(true)
                            {
                            int jogSair;
                            cin >> jogSair;
                            if(jogSair == 0)
                                break;
                            ign.push_back(jogSair - 1);
                            }
                        sair = true;
                        jogador = dinheiro_mesa_jogador(jogador, 0, qntJog, sair, ign);
                    }
                    break;

            case 'm': 
                cout << "Jogador " << sel1 << " recebe todo o dinheiro da mesa.\n";
                    jogador.at(sel1 - 1) += mesa;
                    mesa = 0;
                    ign.clear();
                break; 

            case 'a':
                cin >> qnt;
                if(jogador.at(sel1 - 1) - qnt < 0)
                {
                    cout << "Você não tem dinheiro o suficiente!" << endl;
                    continue;
                }
                cout << "Jogador " << sel1 << " aposta " << qnt << endl;
                cout << "Todos os jogadores vão cobrir a aposta? (s/n)\n";
                cin >> ch;
                if(ch == 's')
                {
                    jogador = dinheiro_mesa_jogador(jogador, qnt, qntJog, sair, ign);
                }
                else
                {
                        cout << "Diga quais jogadores vão sair da jogada, e digite \"0\" quando terminar.\n";
                        while(true)
                            {
                            int jogSair;
                            cin >> jogSair;
                            if(jogSair == 0)
                                break;
                            ign.push_back(jogSair - 1);
                            }
                        sair = true;
                        jogador = dinheiro_mesa_jogador(jogador, qnt, qntJog, sair, ign);
                }
        }
        mostrar_dinheiro(jogador, qntJog, mesa, sair, ign);
    }
}

int main()
{
    while(true)
    {
        cout << "Digite a quantidade de jogadores:" << endl;

        int jog;
        cin >> jog;
        cout << "Digite com quantos milhos cada jogador começa:\n";
        int comJog;
        cin >> comJog;

        vector<int> jogs(jog, comJog);
        mostrar_dinheiro(jogs, jog, 0, sair, jogs);
        dinheiro_jog(jogs, jog);
    }
}