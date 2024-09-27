#include<iostream>

using namespace std;

class Calculator {
    private:
        int current_status;

        int get() {
            return current_status; 
        }

        void set(int element) {
            current_status = element;
        }

    public:
        Calculator() : current_status(0) {}

        Calculator(int element) : current_status(element) {}

        ~Calculator() {
            display();
            cout<<"Destructor of the Calculator object is called."<<endl;
        }

        void add(int value) {
            current_status += value;
        }

        void subtract(int value) {
            current_status -= value;
        }

        void multiply(int value) {
            current_status *= value;
        }

        int divideBy(int value) {
            if(value == 0) {
                cout<<"Invalid arithmetic operation.\n";
                return -1;
            }
            int remainder = current_status % value;
            current_status /= value;
            return remainder;
        }

        void clear() {
            current_status = 0;
        }

        void display() {
            cout<<"Calculator display: "<<current_status<<endl;
        }
};

int main() {
    Calculator c;
    c.add(10);
    c.display();
    c.add(7);
    c.display();
    c.multiply(31);
    c.display();
    c.subtract(42);
    c.display();
    c.divideBy(7);
    c.display();
    c.divideBy(0);
    c.display();
    c.add(3);
    c.display();
    c.clear();
    c.display();
    return 0;
}