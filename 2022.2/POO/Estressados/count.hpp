#include <iostream>
#include <vector>
using namespace std;

int count(vector<int> x, int value)
{
    int index = 0;
    for(auto a : x)
        if(a == value)
            index++;
    return index;
}

float average(vector<int> x)
{
    float index = 0;
    for(int i = 0; i < (int)x.size(); i++){
        if(x[i] < 0)
            x[i] *= -1;

        index += x[i];
    }
    
    return index / (int)x.size();
}

string half_compares(vector<int> x)
{
    int h1 = 0, h2 = 0;
    int j;
    j = ((int)x.size() % 2 == 0) ? (int)x.size() / 2 : (int)x.size() / 2 + 1;

    for(int i = 0; i < (int)x.size() / 2; i++, j++){
        if(x[i] < 0)
             x[i] *= -1;
        if(x[j] < 0)
            x[j] *= -1;

        h1 += x[i];
        h2 += x[j];
    }

    if(h1 == h2)
        return "draw";
    if(h2 > h1)
        return "second";
    return "first";
}

string more_men_or_women(vector<int> x)
{
    if((int)x.size() == 0) return "-1";

    int men = 0, women = 0;
    for(auto a : x)
        if(a > 0)
            men++;
        else   
            women++;

    if(men == women)
        return "draw";
    if(men > women)
        return "men";
    return "women";
}

string sex_battle(vector<int> x)
{
    int menStress = 0, men = 0;
    int womenStress = 0, women = 0;
    
    for(auto a : x)
        if(a > 0){
            men++;
            menStress += a;
        }
        else {
            women++;
            womenStress += -a;
        }
    int menAvg = menStress / men;
    int womenAvg = womenStress / women;

    if(menAvg == womenAvg)
        return "draw";
    if(womenAvg > menAvg)
        return "women";
    return "men";
}