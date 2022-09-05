#include <iostream>
#include <string>
using namespace std;

int main(){
 char N; 
 std::string N2;
 cin >> N >> N2;

 int contador = 0;

 int posicao = 0;
 
 while(posicao < N2.size()){
   if(N2[posicao] == N) contador++;
   posicao++;
 }
 
 cout << contador << endl;

}