#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

int main()
{
 int cu = 13, cu3 = 0;
 string cu2 = "sexo";

    ofstream file_out;
    file_out.open("cu.txt", ios::out);
    file_out << cu;
    file_out.close();


    ifstream file_in;
    file_in.open("cu.txt", ios::in);
    file_in >> cu3;
cout << cu << endl;
 cout << cu3 << endl;
 cout << cu2 << endl;

}