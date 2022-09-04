#include <iostream>
#include <vector>
using namespace std;

struct carro{
    int pass = 0, gas = 0, km = 0;
    const int gasMax = 100, passMax = 2;

    void enter();
    void show();
    void leave();
    void fuel();
    void drive();
};

void carro::show()
{
    cout << "pass: " << pass << ", gas: " << gas << ", km: " << km << endl;
}

void carro::enter()
{
    pass++;
    if(pass > passMax){
        cout << "fail: limite de pessoas atingido\n";
        pass--;
    }
}

void carro::leave()
{
    pass--;
    if(pass < 0){
        cout << "fail: nao ha ninguem no carro\n";
        pass++;
    }
}

void carro::fuel()
{
    int fuel;
    cin >> fuel;
    gas += fuel;
    if(gas > gasMax)
        gas = gasMax;
}

void carro::drive()
{
    int dist;
    cin >> dist;
    if(gas == 0)
        cout << "tanque vazio\n";
    else if(pass == 0)
        cout << "fail: nao ha ninguem no carro\n";
    else {
        gas -= dist;
        if(gas < 0){
            cout << "fail: tanque vazio após dirigir " << dist + gas << " km\n";
            km += dist + gas;
            gas = 0;
        }
        else
            km += dist;
    }
}

bool check_command(string choice, carro &car)
{
    if(choice == "$enter")
        car.enter();
    else if(choice == "$show")
        car.show();
    else if(choice == "$leave")
        car.leave();
    else if(choice == "$fuel")
        car.fuel();
    else if(choice == "$drive")
        car.drive();
    else if(choice == "$end")
        return true;
    return false;
}


int main()
{
    carro car;
    while(true)
    {
        string choice;
        cin >> choice;
        if(check_command(choice, car))
            break;
    }
    return 0;
}