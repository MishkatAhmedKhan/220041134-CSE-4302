#include <iostream>
#include <string>
using namespace std;

class Temperature {
    private:
        double temp = 0;
        char unit; 
    public:
        void assign() {
            double x;
            char y;
            while (true) {
                cout << "Set Temperature: ";
                cin >> x;
                cout << "Set Unit (C, F, K): ";
                cin >> y;
                y = toupper(y);
                if (y != 'C' && y != 'F' && y != 'K') {
                    cout << "Invalid unit! Please provide C, F, or K.\n";
                    continue;
                }
                if ((y == 'K' && x < 0) || (y == 'C' && x < -273.15) || (y == 'F' && x < -459.67)) {
                    cout << "Invalid temperature for the selected unit! Please provide a valid temperature.\n";
                    continue;
                }
                temp = x;
                unit = y;
                break;
            }
        }

        double convert() {
            char target;
            while(true) {
                cout << "Target Unit (C, F, K): ";
                cin >> target;
                
                target = toupper(target);
                
                if (target != 'C' && target != 'F' && target != 'K') {
                    cout << "Invalid target unit! Please provide C, F, or K.\n";
                    continue;
                }
                break;
            }
            if (target == unit) return temp;
            double converted_temp = temp;
            if (unit == 'C') {
                if (target == 'K') {
                    converted_temp = temp + 273.15;
                } else if (target == 'F') {
                    converted_temp = temp * 9 / 5 + 32;
                }
            } else if (unit == 'F') {
                if (target == 'C') {
                    converted_temp = (temp - 32) * 5 / 9;
                } else if (target == 'K') {
                    converted_temp = (temp - 32) * 5 / 9 + 273.15;
                }
            } else if (unit == 'K') {
                if (target == 'C') {
                    converted_temp = temp - 273.15;
                } else if (target == 'F') {
                    converted_temp = (temp - 273.15) * 9 / 5 + 32;
                }
            }
            return converted_temp;
        }

        void print() {
            cout << "The temperature is " << temp << " ";
            if (unit == 'C') {
                cout << "Celsius\n";
            } else if (unit == 'F') {
                cout << "Fahrenheit\n";
            } else {
                cout << "Kelvin\n";
            }
        }
};

int main() {
    Temperature t1;
    t1.assign();                 
    double converted = t1.convert();
    cout << "Converted temperature: " << converted << endl;
    t1.print();
    return 0;
}
