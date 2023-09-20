#include "tcpsock.hpp"
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>


std::mutex mu;
using namespace skt;

std::vector<std::thread> threads;

int errors = 0;

int main()
{
    for(int i = 0; i < 100; i++) {

        std::thread t([](int i){
            try {
                Socket client(49101, true);
                client.connect();
                client.send("ping");
                client.recv();
            } catch(std::runtime_error& e) {
                mu.lock();
                    errors++;
                mu.unlock();
            }
        }, i);

        threads.push_back(std::move(t));
    }

    for(auto& t : threads) {
        t.join();
    }

    std::cout << "Done." << std::endl;
    std::cout << "Errors: " << errors << std::endl;
    std::cout << "Success rate: " << 100 - errors << "%" << std::endl;
}