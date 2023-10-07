#include "../../server/src/tcpsock.hpp"

using namespace skt;

class Proxy {
    Socket proxy = Socket(49110, true);

public:
    Proxy(int port=49110) {
        proxy = Socket(port, true);
        proxy.connect();
    }

    double add(double a, double b) {
        proxy.send("ADD," + fn::tostr(a) + ';' + fn::tostr(b));
        return fn::number(proxy.recv());
    }
    
    double sub(double a, double b) {
        proxy.send("SUB," + fn::tostr(a) + ';' + fn::tostr(b));
        return fn::number(proxy.recv());
    }
    
    double mul(double a, double b) {
        proxy.send("MUL," + fn::tostr(a) + ';' + fn::tostr(b));
        return fn::number(proxy.recv());
    }

    double div(double a, double b) {
        proxy.send("DIV," + fn::tostr(a) + ';' + fn::tostr(b));
        return fn::number(proxy.recv());
    }

    void close() {
        proxy.close();
    }
};