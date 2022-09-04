#include <iostream>
using namespace std;

int main(){
    int num[5];
    cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
    int menor = num[0], maior = num[0];

    for(int i = 0; i < 5; i++){
        if(menor > num[i])
            menor = num[i];
        if(maior < num[i])
            maior = num[i];
    }
    cout << maior + menor << endl;
}