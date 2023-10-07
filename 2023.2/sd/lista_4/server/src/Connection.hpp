#include "Despachante.hpp"
typedef std::shared_ptr<Node> NodePtr;

class Connection {
    std::thread thread;
    NodePtr node;

    void run() {
        while(true) {
            try {
                
                auto msg = node->recv();
                if(msg == "") break;
                std::cout << "Thread " << thread.get_id() << ": " << msg << std::endl;
                node->send(Despachante::invoke(msg));

            } catch (std::runtime_error& e) {
                std::cout << "Thread " << thread.get_id() << ": ERROR - " << e.what() << std::endl;
            }
        }
    }
    
public:
    Connection(NodePtr node) {
        this->node = node;
        this->thread = std::thread(&Connection::run, this);
        thread.join();
    }
};