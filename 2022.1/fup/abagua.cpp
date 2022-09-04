#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int QcamPipa, NdeCasas;
    cin >> NdeCasas >> QcamPipa;

    int casa[NdeCasas];
    vector<int> valorCasa(NdeCasas, 0);
    int camPipa[QcamPipa][3];
    
    
    for(int i = 0; i < QcamPipa; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> camPipa[i][j];
        }
    }

    for(int i = 0; i < NdeCasas; i++)
    {
        casa[i] = i;
        for(int j = 0; j < QcamPipa; j++)
        {
            if(casa[i] >= camPipa[j][0] && casa[i] <= camPipa[j][1])
            {
            valorCasa.at(i) += camPipa[j][2];
            } 
        }
    }
    for(int i = 0; i < NdeCasas; i++)
    {
        cout << valorCasa.at(i);
        if(i != NdeCasas - 1)
            cout << " ";
    }
    cout << endl;
}