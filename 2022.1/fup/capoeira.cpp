#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int qnt;
    cin >> qnt;
    int num[qnt];
    for(int i = 0; i < qnt; i++){
        cin >> num[i];
    }
    cout << "[ ";
    for(int j = qnt - 1; j >= 0; j--){
        cout << num[j] << " ";
    }
    cout << "]" << endl;

}