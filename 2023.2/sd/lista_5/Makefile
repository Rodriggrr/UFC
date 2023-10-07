FILENAME=$(shell $1 | cut -d'.' -f1)

CXX=g++
CXXFLAGS=-std=c++17
LDFLAGS=$(shell pkg-config --cflags --libs protobuf)
SRC_FILES=$(wildcard *.cpp) $(wildcard *.cc)
OUT_FILE=out

$(OUT_FILE): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(SRC_FILES) -o $(OUT_FILE) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OUT_FILE)
