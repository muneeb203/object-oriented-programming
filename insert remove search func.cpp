#include <iostream>
using namespace std;

class Container {
private:
    int* values;
    int capacity;
    int counter;

public:
    Container(int c) 
    {
        capacity = c;
        values = new int[capacity];
        counter = 0;
    }

    bool isFull()
     {
        return counter == capacity;
    }

    void insert(int val) 
    {
        if (!isFull())
         {
            values[counter] = val;
            counter++;
        }
    }

    bool search(int val) 
    {
        for (int i = 0; i < counter; i++) 
        {
            if (values[i] == val) 
            {
                return true;
            }
        }
        return false;
    }

    void remove(int val)
     {
        int index = -1;
        for (int i = 0; i < counter; i++) 
        {
            if (values[i] == val) 
            {
                index = i;
                break;
            }
        }
        if (index != -1)
         {
            for (int i = index; i < counter - 1; i++)
             {
                values[i] = values[i+1];
            }
            counter--;
        }
    }

    void Print() 
    {
        for (int i = 0; i < counter; i++) 
        {
            std::cout << values[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Container()
     {
        delete[] values;
    }
};

int main() {
    Container container(5); // create a container with a capacity of 5

    container.insert(2);
    container.insert(5);
    container.insert(1);
    container.insert(3);
    container.insert(4);

    std::cout << "Container before removing element 3: ";
    container.Print();

    container.remove(3);

    std::cout << "Container after removing element 3: ";
    container.Print();

    int value = 5;
    if (container.search(value)) {
        std::cout << value << " is found in the container." << std::endl;
    } else {
        std::cout << value << " is not found in the container." << std::endl;
    }

    return 0;
}
