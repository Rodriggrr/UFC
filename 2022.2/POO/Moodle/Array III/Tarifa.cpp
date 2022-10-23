#include <algorithm>
#include <sstream>
#include <iostream>
#include <ios>
#include <list>

enum Label {Deposit, Fee, Opening, Reverse, Withdraw};

class Operation{
    int   index{};
    Label label{};
    int   value{};
    int   balance{};
public:
    Operation(int index, Label label, int value, int balance)
    {
        this->index = index;
        this->label = label;
        this->value = value;
        this->balance = balance;
    }
    std::string toString(){
        std::string s;
        switch (label){
            case Deposit:
                s = "  deposit";
                break;
            case Fee:
                s = "      fee";
                break;
            case Opening:
                s = "  opening";
                break;
            case Reverse:
                s = "  reverse";
                break;
            case Withdraw:
                s = " withdraw";
                break;

        }
        s += (correctNum(value, 5) + ":" + correctNum(balance, 5)); 
        return correctNum(index, 2) + ":" + s;
    }
    static std::string correctNum(int num, int sizeNum);
    int   getBalance() { return balance; };
    int   getIndex()   { return index;   };
    Label getLabel()   { return label;   };
    int   getValue()   { return value;   };
};

std::string Operation::correctNum(int num, int sizeNum)
{
    std::string s;
    int size =  (int)((std::to_string(num)).size());
    for(int i = sizeNum - size; i > 0; i--)
        s += " ";
    s += std::to_string(num);
    return s;
}

class BalanceManager {
    int balance{};
    std::list<Operation> operations;
    int nextId{};
public:
    void addOperation(Label label, int value)
    {
        balance += value;
        operations.push_back(Operation(nextId++, label, value, balance));
    }
    int getBalance() { return balance; };

    std::list<Operation> getExtract(int qtdOp)
    {
        if(qtdOp > 0)
        {
            std::list<Operation> extract;
            std::list<Operation>::iterator it = operations.end();
            for(int i = 0; i < qtdOp; i++)
            {
                it--;
                extract.push_front(*it);
            }
            return extract;
        }
        return operations;

    }
    Operation getOperation(int index)
    {
        std::list<Operation>::iterator it = operations.begin();
        while(it != operations.end())
        {
            if(it->getIndex() == index)
                return *it;
            it++;
        }
        return Operation(-1, Opening, 0, 0);
    }
    
};

class Account{
    int id{};
    BalanceManager balanceManager;
public:
    Account (int id)
    {
        this->id = id;
        balanceManager.addOperation(Opening, 0);
    }

    void deposit(int value)
    {
        if(value > 0)
            balanceManager.addOperation(Deposit, value);
        else
            std::cout << "fail: invalid value\n";
    }

    void fee(int value)
    {
        balanceManager.addOperation(Fee, -value);
    }

    void reverse(int index){
        if ((int)balanceManager.getExtract(0).size() < index)
            std::cout << "fail: index " << index << " invalid" << std::endl;
        else if(balanceManager.getOperation(index).getLabel() != Fee)
            std::cout << "fail: index " << index << " is not a fee" << std::endl;
        else{
            int value = balanceManager.getOperation(index).getValue();
            balanceManager.addOperation(Reverse, -value);
        }
    }

    void withdraw(int value)
    {
        if(value <= balanceManager.getBalance())
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

int main()
{

    std::stringstream ss;
    Account account(0);
    while(true)
    {
        std::string line;
        getline(std::cin, line);
        ss << line;
        std::cout << "$" << line << std::endl;
        line.clear();
        ss >> line;
        ss << "";
        //std::cout << "debug:" << line << '\n';

        if(line == "end")
            break;
        else if(line == "init")
        {
            int id;
            ss >> id;
            account.setId(id);
        }
        else if(line == "deposit")
        {
            int value;
            ss >> value;
            account.deposit(value);
        }
        else if(line == "fee")
        {
            int value;
            ss >> value;
            account.fee(value);
        }
        else if(line == "reverse")
        {
            int index;
            while(ss.rdbuf()->in_avail() > 0){
                ss >> index;
                account.reverse(index);
            }
        }
        else if(line == "show")
        {
            std::cout << account.toString() << std::endl;
        }
        else if(line == "withdraw")
        {
            int value;
            ss >> value;
            account.withdraw(value);
        }
        else if(line == "extract")
        {
            int qtdOp;
            ss >> qtdOp;
            std::list<Operation> extract = account.getBalanceManager().getExtract(qtdOp);
            for(auto it = extract.begin(); it != extract.end(); it++)
                std::cout << it->toString() << std::endl;
        }
        else {
            std::cout << "fail: invalid command" << std::endl;
            ss.clear();
            ss.flush();
            line = "";
        }
        ss.clear();
    }

}