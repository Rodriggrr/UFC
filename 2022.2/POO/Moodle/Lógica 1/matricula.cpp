    #include <iostream>
    #include <list>
    #include <map>

    using namespace std;

    class Discip;
    class Aluno;

class Discip
{
        std::string id;
        std::map<std::string, Aluno> Alunos;

public:
        Discip(std::string id){
            this->id = id;
        }

        std::string getId(){
            return this->id;
        }

        std::list<Aluno> getAlunos(){
            std::list<Aluno> Alunos;
            for (auto it = this->Alunos.begin(); it != this->Alunos.end(); it++)
            {
                Alunos.push_back(it->second);
            }
            return Alunos;
        }

        std::string toString(){
            std::string str = "Disciplina: " + this->id + '\n';
        }

        void addAluno(Aluno Aluno){
            this->Alunos[Aluno.getId()] = Aluno;
            Aluno.addDiscip(*this);
        }

        void rmAluno(Aluno aluno){
            this->Alunos.erase(aluno.getId());
            aluno.rmDiscip(*this);
        }
};

class Aluno
{
    string id;
    map<string, Discip> discip;

public:
    Aluno(string id){
        this->id = id;
    }

    string getId(){
        return this->id;
    }

    list<Discip> getDiscip(){
        list<Discip> lista;
        for (auto i = discip.begin(); i != discip.end(); i++)
        {
            lista.push_back(i->second);
        }
        return lista;
    }

    string toString(){
        string str = "Aluno: " + this->id + "\n";
        return str;
    }

    void addDiscip(Discip discip){
        this->discip[discip.getId()] = discip;
        discip.addAluno(*this);
    }

    void rmDiscip(Discip discip){
        this->discip.erase(discip.getId());
        discip.rmAluno(*this);
    }
    friend void Discp::addAluno(Aluno*);
    friend void Discp::rmAluno(string);
};

int main()
{
    return 0;
}