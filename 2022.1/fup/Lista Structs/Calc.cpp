#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>
using namespace std;


struct aluno
{
    string nome;
    float n1, n2, n3;
    float media(){
        float m = (n1 + n2 + n3) / 3;
        return m;
    } 
};
    
vector<aluno> sort_vector(vector<aluno> vetor)
{   
    aluno aux;
    for(int i = 0; i < vetor.size(); i++){
        for(int j = i + 1; j < vetor.size(); j++){
            if(vetor[i].media() < vetor[j].media()){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    return vetor;
}

int main()
{   
    int qntAlunos;
    cin >> qntAlunos;

    vector<aluno> alunos(qntAlunos);
    float maiorMedia = 0;
    for(int i = 0; i < qntAlunos; i++){
        aluno student;
        getline(cin >> ws, student.nome);
        cin >> student.n1 >> student.n2 >> student.n3;

        alunos[i] = student;
    }

    alunos = sort_vector(alunos);
    
    for(int i = 0; i < qntAlunos; i++){
        cout << i << ": " << alunos[i].nome
             << "\nMedia: " << fixed << setprecision(2) << alunos[i].media()
             << "\nN1: " << fixed << setprecision(2) << alunos[i].n1 
             << ", N2: " << fixed << setprecision(2) << alunos[i].n2 
             << ", N3: " << fixed << setprecision(2) << alunos[i].n3 << endl;
    }
}