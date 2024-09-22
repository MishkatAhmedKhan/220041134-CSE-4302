#include<iostream>

using namespace std;

class Counter {
    private:
        int count = 0;
        int incrementStep = 1;
    public:
        void setIncrementStep(int element) {
            incrementStep = element;
        }

        int getCount() {
            return count;
        }

        void increment() {
            count += incrementStep;
        }

        void resetCount() {
            count = 0;
        }
};

int main() {
    Counter c1;
    cout<<c1.getCount()<<endl;
    c1.setIncrementStep(10);
    c1.increment();
    cout<<c1.getCount()<<endl;
    return 0;
}