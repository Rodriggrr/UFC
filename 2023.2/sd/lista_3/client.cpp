#include "tcpsock.hpp"
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include "fn.hpp"


std::mutex mu;
using namespace skt;

std::vector<std::thread> threads;

float errors = 0;
int trials = 100;

int main()
{
    for(int i = 0; i < trials; i++) {

        try {
            std::thread t([](int i){
                try {
                    Socket client(49101, true);
                    client.connect();
                    client.send("ping");
                    client.recv();
                    client.close();
                } catch(std::runtime_error& e) {
                    mu.lock();
                        errors++;
                    mu.unlock();
                }

            }, i);
            threads.push_back(std::move(t));
        } catch(std::system_error& e){
            std::cout << e.what() << ", waiting 5 sec" <<std::endl;
            sleep(5);
        }

    }

    for(auto& t : threads) {
        t.join();
    }

    std::cout << "Done." << std::endl;
    std::cout << "Errors: " << errors << std::endl;
    //error percentage
    errors = 100 - (errors / ((float)trials / 100));
    std::cout << "Success rate: " << fn::format("{%0.2f}%", errors) << std::endl;
}