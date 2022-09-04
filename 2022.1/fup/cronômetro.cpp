#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;

int main()
{
    int mi = 0, seg = 0, mili = 0;
    cout << "Pressione ENTER para iniciar.\n00 : 00 : 000";
    cin.get();
    write(1,"\E[H\E[2J",7);
    cout << "ENTER para gravar.\n";
    while (seg <= 10) //Segundos até que o programa retorne 0.
    {
        mili++;
        seg = (mili == 1000) ? seg + 1 : seg;
        mi = (seg == 60) ? mi + 1 : mi;
        mili = (mili == 1000) ? 0 : mili;
        seg = (seg == 60) ? 0 : seg;
        mi = (mi == 24) ? 0 : mi;
        cout << setw(2) << setfill('0') << mi << " : "
             << setw(2) << setfill('0') << seg << " : "
             << setw(3) << setfill('0') << mili
             << usleep(1000) << "\b \b\n" << "\x1b[1A";
    }
    return 0;
}
