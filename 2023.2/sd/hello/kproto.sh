g++ -std=c++17 $1 $2 -o out `pkg-config --cflags --libs protobuf` && ./out
