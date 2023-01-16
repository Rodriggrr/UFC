/* Equation solver for variância and desvio padrão.*/

#include <sstream>
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
            sum += std::abs(a);
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

        return sum / (vet.size());
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
    std::vector<double> v;
    std::stringstream ss;
    std::string s;

    std::getline(cin, s);
    ss << s;

    while(ss.rdbuf()->in_avail() != 0)
    {
        double foo;
        ss >> foo;
        v.push_back(foo);
    }

    std::cout << stc::var(v);
    main();
}