#include "Despachante.hpp"
typedef std::shared_ptr<Node> NodePtr;

class Connection {
    std::thread thread;
    Node* node;

    void run() {
        while(true) {
            try {
                
                auto msg = node->recv();
                if(msg == "") break;
                node->send(Despachante::invoke(msg));

            } catch (std::runtime_error& e) {
                std::cout << "Thread" << thread.get_id() << " fechou devido a um erro: " << e.what() << std::endl;
            }
        }
    }
    
public:
    Connection(Node* node) {
        this->node = node;
        this->thread = std::thread(&Connection::run, this);
        thread.join();
    }
};