#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string nums;
    vector<string> numeros(1);
    getline(cin,nums);

    int posNoVetor = 0;
    for(int i = 0; i < nums.length(); i++)
    {
        if(nums[i] != ' ')
            numeros.at(posNoVetor) += nums[i];
        else
        {
            posNoVetor++;
            numeros.push_back("");
        }    
    }
        cout << "[ ";

    for(int i = numeros.size() - 1 ; i >= 0; i--)
        cout << numeros[i] << " ";

        cout << "]" << endl;
}