/* Equation solver for variância and desvio padrão.*/

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

namespace stc
{
    auto sum(const vector<double> &vet)
    {
        double sum{};
        for(auto a : vet)
            sum += a;
        return sum;
    }

    //Calcula a média de um vetor;
    auto avg(vector<double> vet)
    {
        return sum(vet) / vet.size();
    }

    auto var(vector<double> vet)
    {
        double sum{}, avg = stc::avg(vet);
        
        for(auto a : vet)
            sum += pow((a - avg), 2);

        return sum / (vet.size() - 1);
    }

    auto desv_p(vector<double> vet)
    {
        return sqrt(var(vet));
    }
}

template<typename T>
void get_numbers(vector<T> &vet)
{
    srand(time(NULL));
    for(int i = 0; i < 1000; i++)
        vet.push_back(rand() % 10000);

}


int main()
{
    std::vector<double> vet;
    get_numbers(vet);
    std::cout << stc::avg({1, 2}) << endl;
    cout << stc::desv_p(vet);
}