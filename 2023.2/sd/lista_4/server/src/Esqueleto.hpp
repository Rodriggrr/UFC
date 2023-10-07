#include "Calculator.hpp"

struct Esqueleto {
    static std::string add(std::string args) {
        auto nums = fn::split(args, ';');
        return fn::tostr(Calculator::add(number(nums[0]), number(nums[1])));
    }
    static std::string sub(std::string args) {
        auto nums = fn::split(args, ';');
        return fn::tostr(Calculator::sub(number(nums[0]), number(nums[1])));
    }
    static std::string mul(std::string args) {
        auto nums = fn::split(args, ';');
        return fn::tostr(Calculator::mul(number(nums[0]), number(nums[1])));
    }
    static std::string div(std::string args) {
        auto nums = fn::split(args, ';');
        return fn::tostr(Calculator::div(number(nums[0]), number(nums[1])));
    }

private:

    static double number(std::string str) {
        return fn::number(str);
    }

};