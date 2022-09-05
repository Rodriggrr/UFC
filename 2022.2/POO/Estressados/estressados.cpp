using namespace std;
#include "cout.hpp"    //cout
#include "find.hpp"    //find
#include "count.hpp"   // count
#include "filter.hpp"  //filter
#include "set.hpp"     //set
#include "sort.hpp"    //sort
#include "reverse.hpp" //reverse
#include "others.hpp"  //others (bloco 3 e extras)


int main()
{
    vector<int> fila {1, -2, 3, -4, 3, -65, 34, -12, 11};

    cout<< "count file: ----------------------------------------------------\n\n"
        << count(fila, 3) << " - count function\n"
        << average(fila) << " - average fnc\n"
        << half_compares(fila) << " - half compare fnc\n"
        << more_men_or_women(fila) << " - more men or women fnc\n"
        << sex_battle(fila) << " - sex battle fnv\n";
    
    cout<< "\nfilter file: -----------------------------------------------------\n\n"
        << get_men(fila) << " - get_men fnc\n"
        << get_calm_women(fila) << " - get_calm_women fnc\n";
    
    cout<< "\nfind file: ------------------------------------------------------\n\n"
        << in(fila, 2) << " - in fnc\n"
        << index_of(fila, 2) << " - index_of fnc\n"
        << find_if(fila, 2) << " - find_if fnc\n"
        << min_element(fila) << " - min_element fnc\n"
        << fin_min_if(fila) << " - fin_min_if fnc\n";

    cout << "\nset file: -------------------------------------------------------\n\n"
         << unique(fila) << " - unique fnc\n"
         << repeated(fila) << " - repeated fnc\n";

    cout << "\nsort file: ------------------------------------------------------\n\n"
         << sort::sort(fila) << " - sort fnc\n"
         << sort_stress(fila) << " - sort_stress fnc\n";

    cout << "\nothers file: ------------------------------------------------------\n";
    embaralhar(fila);
    cout << fila << " - embaralhar fila\n"
        << Map(fila) << " - fnc map\n"
        << sozinhos(fila) << " - fnc sozinhos\n"
        << acompanhados(fila) << " - fnc acompanhados\n"
        << times(fila) << " - fnc times\n"
        << casais(fila) << " - fnc casais\n"
        << remover_todos({0, 2}, fila) << " - fnc remover_todos\n"
        << dance(fila) << " - fnc dance\n"
        << sortear(fila) << " - fnc sortear\n";

    cout << "\nreverse file: ------------------------------------------------------\n"
         << reverse(fila) << " - fnc reverse\n";
    reverse_inplace(fila);
    cout << fila << " - fnc reverse_inplace\n"
         << "\n------------------------------------------------------------------\n";

}