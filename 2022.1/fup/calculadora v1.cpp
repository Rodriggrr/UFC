#include <iostream>
#include <limits>
#include <unistd.h>
using namespace std;
int error(){ 
  cout << "ERRO: Caractere/s não esperado/s inserido/s. Repita.\n";
     cin.clear();                                            
     cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
  return 0;
  }
int main(){  
float valorUm, valorDois;               
int direcionador;                       
char varEstetc;                           
 cout << "Você deseja usar a calculadora? (S/N)\n";
 while (true){ 
  if (cin >> varEstetc){;
   if(varEstetc == 's'){
    break;}     
   if(varEstetc == 'n'){
    cout << "Processo encerrado.";
    return 0;
} else {
   error();     
 }}}
 reinicio:    
 cout << "Escolha:\n1 para SOMA;\n2 para MULTIPLICAÇÃO;\n3 para SUBTRAÇÃO;\n4 para DIVISÃO.\n";
 while (true){
   if (cin >> direcionador, 4 >= direcionador){ 
   if (direcionador > 0){                     
     break;
   } else {
     error();
     }
   } else {
     error();
  }}
  if (direcionador == 1){                 
   cout << usleep(250000) << "\b \b•\n" << usleep(250000) << "\b \bEscolhido: SOMA.";         
  }                                        
  if (direcionador == 2){                  
   cout << usleep(250000) << "\b \b•\n" << usleep(250000) << "\b \bEscolhido: MULTIPLICAÇÃO.";
  }
  if (direcionador == 3){
   cout << usleep(250000) << "\b \b•\n" << usleep(250000) << "\b \bEscolhido: SUBTRAÇÃO.";
  }
  if (direcionador == 4){
   cout << usleep(250000) << "\b \b•\n" << usleep(250000) << "\b \bEscolhido: DIVISÃO.";
  }
  cout << "\n" << usleep(250000) << "\b \b•\n" << usleep (250000) << "\b \b•\n" << usleep(250000) << "\b \b•\n\b \b" << usleep(250000);
  while (true){
   cout << "\b \bValor 1: ";
   if (cin >> valorUm){
     break;
  } else {
     error();
   } };
  while (true){
   cout << "Valor 2: ";
   if (cin >> valorDois){
      break;
  } else {
     error();
    };};
  if (direcionador == 1){
   cout << "Resultado: " << valorUm + valorDois <<  usleep(250000) << "\b \b\n----------\n" << usleep(250000) <<"\b \b" << valorUm << " + " << valorDois << " = " << valorUm + valorDois << endl << usleep (250000) << "\b \b----------";
  }
  if (direcionador == 2){
   cout << "Resultado: " << valorUm * valorDois <<  usleep(250000) << "\b \b\n----------\n" << usleep(250000) <<"\b \b" << valorUm << " • " << valorDois << " = " << valorUm * valorDois << endl << usleep (250000) << "\b \b----------";
  }
  if (direcionador == 3){
      cout << "Resultado: " << valorUm - valorDois <<  usleep(250000) << "\b \b\n----------\n" << usleep(250000) <<"\b \b" << valorUm << " - " << valorDois << " = " << valorUm - valorDois << endl << usleep (250000) << "\b \b----------";
  }
  if (direcionador == 4){
      cout << "Resultado: " << valorUm / valorDois <<  usleep(250000) << "\b \b\n----------\n" << usleep(250000) <<"\b \b" << valorUm << " ÷ " << valorDois << " = " << valorUm / valorDois << endl << usleep (250000) << "\b \b----------";
  }
  cout << "\n" << usleep(250000) << "\b \b•\n" << usleep (250000) << "\b \b•\n" << usleep(250000) << "\b \b•\n\b \b" << usleep(250000) << "\b \bPressione ENTER para continuar.";
   cin.ignore(1);                          //argumentos para continuar o código
   cin.get();                              //apenas quando apertado "ENTER".
   cout << "Você deseja continuar usando a calculadora? (S/N)\n";
   while (true){
  if (cin >> varEstetc){;
   if(varEstetc == 's'){
    write(1,"\E[H\E[2J",7); //argumentos para limpar o console. retirados da internet.
    goto reinicio;}         //comando goto, utilizado para ir ao ponto de controle "reinicio" previamente declarado. (linha 27).
   if(varEstetc == 'n'){
    cout << "Processo encerrado.";
    return 0;
} else {
   error();
}}}}
