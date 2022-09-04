#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int h1, m1, seg1;
    int h2, m2, seg2;
    cin >> h1 >> m1 >> seg1;
    cin >> h2 >> m2 >> seg2;
    int seg = 0;
    while (h1 != h2 || m1 != m2 || seg1 != seg2)
    {
        seg++;
        seg1++;
        m1 = (seg1 == 60) ? m1 + 1 : m1;
        h1 = (m1 == 60) ? h1 + 1 : h1;
        seg1 = (seg1 == 60) ? 0 : seg1;
        m1 = (m1 == 60) ? 0 : m1;
        h1 = (h1 == 24) ? 0 : h1;
    }
    h1 = 0;
    m1 = 0;
    seg1 = 0;
    while (seg > 0)
    {
        seg--;
        seg1++;
        m1 = (seg1 == 60) ? m1 + 1 : m1;
        h1 = (m1 == 60) ? h1 + 1 : h1;
        seg1 = (seg1 == 60) ? 0 : seg1;
        m1 = (m1 == 60) ? 0 : m1;
        h1 = (h1 == 24) ? 0 : h1;
    }
    cout << setw(2) << setfill('0') << h1 << " "
         << setw(2) << setfill('0') << m1 << " "
         << setw(2) << setfill('0') << seg1 << endl;
}