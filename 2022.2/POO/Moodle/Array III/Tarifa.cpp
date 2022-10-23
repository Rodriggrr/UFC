/*
1) Fiz sozinho.

2) Aprendi muito, já que não tinha o solver: transformei em string, fiz o extrato do zero,
enfim, foi uma loucura. Achei muito legal não ter o solver, pois aprendi muito.

3) Fiz em 2 horas e 30 minutos.
*/

#include <algorithm>
#include <sstream>
#include <iostream>
#include <list>

enum Label // Rótulo em enum;
{
    Deposit,
    Fee,
    Opening,
    Reverse,
    Withdraw
};

//********** OP CLASS **********
class Operation 
{
    int index{};  // Índice da operação, basicamente ID da compra.
    Label label{};// Qual tipo de operação foi feita?
    int value{};  // Valor q decremetar ou aumentar de acordo com a operação.
    int balance{};// Balanço da conta atual.

public:
    Operation(int index, Label label, int value, int balance) // Construtor;
    {
        this->index = index;
        this->label = label;
        this->value = value;
        this->balance = balance;
    }
    std::string toString() // Transoforma a operação em uma string para quando for colocar no extrato.
    {
        std::string s;
        switch (label)
        {
        case Deposit:
            s = "  deposit:";
            break;
        case Fee:
            s = "      fee:";
            break;
        case Opening:
            s = "  opening:";
            break;
        case Reverse:
            s = "  reverse:";
            break;
        case Withdraw:
            s = " withdraw:";
            break;
        }
        s += (correctNum(value, 5) + ":" + correctNum(balance, 5));
        return correctNum(index, 2) + ":" + s;
    }
    static std::string correctNum(int num, int sizeNum);
    int getBalance() { return balance; };
    int getIndex() { return index; };
    Label getLabel() { return label; };
    int getValue() { return value; };
};

std::string Operation::correctNum(int num, int sizeNum) // Corrige a posição do número para ficar bonitinho
{                                                       // (A questão só aceita bonitinho)
    std::string s;
    int size = (int)((std::to_string(num)).size());
    for (int i = sizeNum - size; i > 0; i--)
        s += " ";
    s += std::to_string(num);
    return s;
}

//*********BM CLASS**********
class BalanceManager
{
    int balance{};                   // Quantidade na conta;
    std::list<Operation> operations; // Operações feitas, basicamente o histórico.
    int nextId{};                    // Id maleável das opeerações.

public:
    void addOperation(Label label, int value) // Adiciona uma operação.
    {
        balance += value;
        operations.push_back(Operation(nextId++, label, value, balance));
    }
    
    int getBalance() { return balance; };

    std::list<Operation> getExtract(int qtdOp) // Retorna o extrato de acordo com o pedido do usuário.
    {
        if (qtdOp > 0)
        {
            std::list<Operation> extract;
            std::list<Operation>::iterator it = operations.end();
            for (int i = 0; i < qtdOp; i++)
            {
                it--;
                extract.push_front(*it);
            }
            return extract;
        }
        return operations;
    }
    Operation getOperation(int index)         // Retorna uma operação específica.
    {
        std::list<Operation>::iterator it = operations.begin();
        while (it != operations.end())
        {
            if (it->getIndex() == index)
                return *it;
            it++;
        }
        return Operation(-1, Opening, 0, 0);
    }
};


//*********ACC CLASS***********
class Account
{
    int id{}; // ID do Usuário.
    BalanceManager balanceManager;

public:
    Account(int id) // Construtor, fiz uma gambiarra lá embaixo para mudar o ID.
    {
        this->id = id;
        balanceManager.addOperation(Opening, 0);
    }

    void deposit(int value)
    {
        if (value > 0)
            balanceManager.addOperation(Deposit, value);
        else
            std::cout << "fail: invalid value\n";
    }

    void fee(int value)
    {
        balanceManager.addOperation(Fee, -value);
    }

    void reverse(int index)
    {
        if ((int)balanceManager.getExtract(0).size() < index)
            std::cout << "fail: index " << index << " invalid" << std::endl;
        else if (balanceManager.getOperation(index).getLabel() != Fee)
            std::cout << "fail: index " << index << " is not a fee" << std::endl;
        else
        {
            int value = balanceManager.getOperation(index).getValue();
            balanceManager.addOperation(Reverse, -value);
        }
    }

    void withdraw(int value)
    {
        if (value <= balanceManager.getBalance())
            balanceManager.addOperation(Withdraw, -value);
        else
            std::cout << "fail: insufficient balance\n";
    }

    std::string toString()
    {
        std::string s = "account:" + std::to_string(id) + " balance:" + std::to_string(balanceManager.getBalance());
        return s;
    }
    void setId(int id) { this->id = id; };
    BalanceManager getBalanceManager() { return balanceManager; };
};

//Aceitar comandos do usuário e printar no shell.
int main()
{
    std::stringstream ss;
    Account account(0);
    while (true)
    {
        std::string line;
        getline(std::cin, line);
        ss << line;
        std::cout << "$" << line << std::endl;
        line.clear();
        ss >> line;
        ss << "";
        // std::cout << "debug:" << line << '\n';
        
        //END
        if (line == "end")
            break;
        //INIT
        else if (line == "init")
        {
            int id;
            ss >> id;
            account.setId(id);
        }
        //DEPOSIT
        else if (line == "deposit")
        {
            int value;
            ss >> value;
            account.deposit(value);
        }
        //FEE
        else if (line == "fee")
        {
            int value;
            ss >> value;
            account.fee(value);
        }
        //REVERSE
        else if (line == "reverse")
        {
            int index;
            while (ss.rdbuf()->in_avail() > 0)
            {
                ss >> index;
                account.reverse(index);
            }
        }
        //SHOW
        else if (line == "show")
        {
            std::cout << account.toString() << std::endl;
        }
        //WITHDRAW
        else if (line == "withdraw")
        {
            int value;
            ss >> value;
            account.withdraw(value);
        }
        //EXTRACT
        else if (line == "extract")
        {
            int qtdOp;
            ss >> qtdOp;
            std::list<Operation> extract = account.getBalanceManager().getExtract(qtdOp);
            for (auto it = extract.begin(); it != extract.end(); it++)
                std::cout << it->toString() << std::endl;
        }
        //INVALID COMMAND
        else
        {
            std::cout << "fail: invalid command" << std::endl;
            ss.clear();
            ss.flush();
            line = "";
        }
        ss.clear();
    }
}