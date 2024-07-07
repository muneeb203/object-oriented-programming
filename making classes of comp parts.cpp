#include <iostream>
#include <string>
using namespace std;

class Processor {
    string processName;
    int price;

public:
    Processor(string processName, int price) {
        this->processName = processName;
        this->price = price;
    }
};

class MainMemory {
    int size;
    int price;

public:
    MainMemory(int size, int price) {
        this->size = size;
        this->price = price;
    }
};

class MotherBoard {
    string compName;

public:
    MotherBoard() {
        compName = "intel";
    }
};

class Computer {
    Processor proc;
    MainMemory ram;
    MotherBoard mboard;

public:
    Computer(Processor proc, MainMemory ram) : proc(proc), ram(ram), mboard() {}
};

int main() {
    Processor intelProcessor("Hp i5", 1000);
    MainMemory ram(16, 200);
    Computer computer(intelProcessor, ram);

  
    return 0;
}
