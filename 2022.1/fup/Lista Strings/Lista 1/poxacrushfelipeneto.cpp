#include <iostream>
#include <cctype>

using namespace std;

int ver_vogais(string nome, bool &ultLetra)
{
    int Vogais = 0;
    string vogais = "aAeEiIoOuU";
    for(int i = 0; i < nome.size(); i++)
        for(int j =0; j < vogais.size(); j++)
            if(nome[i] == vogais[j])
            {
                if(i + 1 != nome.size())
                    ultLetra = true;
                Vogais++;
            }

            
    return Vogais;
}

int main()
{
    bool vogalUltLetraVc = false;
    string seuNome;
    cin >> seuNome;

    bool vogalUltLetraCs = false;
    string nomeCrush;
    cin >> nomeCrush;

    int pontos = 0;

    if(nomeCrush[0] == seuNome[0])
        pontos += 20;

    if(nomeCrush.size() == seuNome.size())
        pontos += 30;

    if(ver_vogais(seuNome, vogalUltLetraVc) == ver_vogais(nomeCrush, vogalUltLetraCs))
        pontos += 30;

    if(vogalUltLetraCs == vogalUltLetraVc)
        pontos += 20;
    else
        pontos -= 10;

    pontos = (pontos < 0) ? 0 : pontos;

    cout << "As chances do crush te dar bola sao: " << pontos << "%!" << endl;

}