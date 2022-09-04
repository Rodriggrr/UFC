#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	write(1,"\E[H\E[2J",7);
	int qntLet = 0, gg = 0, x = 0, m = 1, size;
	string cu;
	string array[1000];
	char choice;
	cout << "Adicione uma palavra: (Sem caracteres especiais ou acentos.)\n";
	cin >> array[0];
	cout << "Quer adicionar outra palavra? (s/n)\n";	
	cin >> choice;
	char letra, letra2;
	if (choice == 's')	
	{
	write(1,"\E[H\E[2J",7);
	cout << array[0] << ";\n";
	retorno2:
	while(true)
	{
		cin >> array[m];
		if (array[m].length() > array[m-1].length())
		{
			size = array[m].length();
		}
		else
		{
			size = array[m-1].length();
		}
	    m++;	
		cout << "Quer adicionar outra palavra? (s/n)\n";
		cin >> choice;
		write(1,"\E[H\E[2J",7);
		for (int iai = 0; iai < m; iai++)
        {
        	cout << array[iai] << ";\n";
        }	             
		if (choice == 'n')
		    break;	       
	}
	}
	reinicio:
	cout << "Qual a letra que você deseja procurar?" << endl;
	cin >> letra;
	write(1,"\E[H\E[2J",7);
	cout << "Letra: " << "\"" << letra << "\"" << endl;	
	letra2 = letra - 32;
	for (int i = 0; i < m; i++)
	{
		int ltln = array[i].length();
		for(int j = 0; j < ltln; j++)
	    {
	      	if (array[i][j] == letra || array[i][j] == letra2)
	      	{
	      		x = 1;
	      		cu[gg] = j+1;
	      		gg++;
	      	    qntLet++;
	      	}
	    }
	    if (x == 1) 
	    {    
			cout << "A palavra " << "\"" << array[i] << "\"";
			if (array[i].length() < size)
			{
				int blank = size - array[i].length();
				for(int d = 0; d < blank; d++)
				{
					cout << "-";
				}
			}  
			if (gg > 1)
			{
				cout << " tem, nos caracteres ";
				for (int k = 0; k < gg; k++)
				{
					if (gg-1 == k && gg > 1)
					{
						cout << "\b\b e " << (int)cu[k]  << ", ";
						break;
					}
						cout << (int)cu[k]  << ", ";
				}
			}
			else
			{
				cout << " tem, no " << (int)cu[0] << "° caractere, ";
			}
		cout << "a letra \"" << letra << "\", totalizando " << gg;
		if (gg > 1)
			cout << " vezes." << endl;
		else
		 	cout << " vez." << endl;
	    }
	    else
		{
	        cout << "A palavra " << "\"" << array[i] << "\"";
			if (array[i].length() < size)
	    	{
	    		int blank = size - array[i].length();
	    		for(int d = 0; d < blank; d++)
	    		{
	    			cout << "-";
	    		}
			}
			cout << " não contém a letra \"" << letra << "\"." << endl;
		}	
		gg = 0;
	    x = 0;
	}
    cout << "A quantidade de \"" << letra << "\" no total é " << qntLet << "." << "\nPressione ENTER para continuar." << endl;
    cin.get();
    cin.ignore(1);
	write(1,"\E[H\E[2J",7);
    cout << "Você deseja:\n1 - Procurar outra letra nas palavras atuais;\n2 - Começar de novo;\n3 - Adicionar mais palavras à lista;\n4 - Encerrar.\n";
    int esc;
    cin >> esc;
    if (esc == 1)
    {
    	qntLet = 0;
        write(1,"\E[H\E[2J",7);
        cout << "A palavras são:\n";
		for (int iai = 0; iai < m; iai++)
		{
			cout << array[iai] << ";\n";
		}	             
   		goto reinicio;
    }
	else if (esc == 4)
	{
		write(1,"\E[H\E[2J",7);
		cout << "Encerrado.\n";
		return 0;
	}
    else if (esc == 2)
    {
        write(1,"\E[H\E[2J",7);
        main();
    }   
	else
	{
		write(1,"\E[H\E[2J",7);
		cout << "Adicione mais palavras:\n";
		goto retorno2;
	}
}