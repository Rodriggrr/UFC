#include <iostream>
#include <map>
#include <algorithm>
#include <windows.h>
using namespace std;

int main()
{
    LPCSTR oi;
    string ok;

    ok = "corno";

    oi = ok.c_str();
    SetConsoleTitleA(oi);
}
