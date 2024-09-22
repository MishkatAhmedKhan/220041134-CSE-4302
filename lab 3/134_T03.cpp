#include<iostream>

using namespace std;

class Time {
    private:
        int hour = 0;
        int min = 0;
        int sec = 0;
    public:
        int hours() {
            return hour;
        }

        int minutes() {
            return min;
        }

        int seconds() {
            return sec;
        }

        void reset(int h, int m, int s) {
            hour = h;
            min = m;
            sec = s;
        }

        void advance(int h, int m, int s) {
            sec += s;
            min += sec/60 + m;
            sec = sec%60;
            hour += min/60 + h;
            min = min%60;
            hour = hour%24;
        }

        void print() {
            cout<<"Current time: "<<hour<<":"<<min<<":"<<sec<<endl;
        }
};

int main() {
    Time t1;
    t1.reset(23, 40, 20);
    t1.print();
    t1.advance(0, 20, 40);
    t1.print();
    return 0;
}