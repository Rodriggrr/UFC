#include <iostream>
#include <cmath>

using namespace std;

bool existe;
int collatz(int numColl)
{
    int seq = 0;
    while(numColl > 1 ){
        if(numColl % 2 == 0)
            numColl /= 2;
        else
            numColl = (numColl * 3) + 1;
        seq++;
    }

    return seq;
}

bool perfSQ(int num)
{
    int numSQ = (int)sqrt(num);
    return (numSQ * numSQ == num) ? true : false;
}

int main()
{
    int tam;
    cin >> tam;
    int array[tam];

    for(int i = 0; i < tam; i++)
        cin >> array[i];
    
    int maiorColl[2] = {0};
    for(int i = 0; i < tam; i++){
        existe = false;
        if(perfSQ(array[i])){
            if(collatz(array[i]) > maiorColl[0]){
                existe = true;
                maiorColl[0] = collatz(array[i]);
                maiorColl[1] = array[i];
            }
        }
       
    }
    if(existe)
        cout << maiorColl[1] << endl;
    else
        cout << "a porta nao existe" << endl;
    
}
