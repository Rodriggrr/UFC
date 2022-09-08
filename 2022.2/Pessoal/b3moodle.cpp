#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
ostream& operator<<(ostream& out, vector<pair<T, T>> v)
{
    for (auto& p : v)
        out << p.first << " " << p.second << endl;
    return out;
}

ostream& operator<<(ostream& out, vector<int> v)
{
    for (auto& i : v)
        out << i << " ";
    return out;
}

pair<bool, int> find_pair(vector<pair<int, int>> vet, int value)
{
    for (int i = 0; i < vet.size(); i++){
        if (vet[i].first == value)
            return make_pair(true, i);
    }
    return make_pair(false, -1);
}

vector<pair<int, int>> occurr(vector<int> vet)
{
    sort(vet.begin(), vet.end(),[](auto a, auto b) { return abs(a) < abs(b); });
    vector<pair<int, int>> v;
    for(int i = 0; i < vet.size(); i++)
    {
        pair<bool, int> p = find_pair(v, vet[i]);
        if(p.first)
            v[p.second].second++;
        else
            v.push_back(make_pair(abs(vet[i]), 1));
    }
    return v;
}

int main()
{
    cout << occurr({22,2,2,1,1, -3});
}