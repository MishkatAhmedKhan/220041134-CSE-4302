#include<iostream>
#include<string>

using namespace std;

class FlightManagement {
    private:
        int FlightNO;
        string Destination;
        float Distance;
        float MaxFuelCapacity;

        double CalFuel() {
            double fuel;
            if(Distance <= 1000) fuel = 500;
            else if(Distance > 1000 && Distance <= 2000) fuel = 1100;
            else if(Distance > 2000) fuel = 2200;
            return fuel;
        }

    public:
        void FeedInfo() {
            int fn;
            string dest;
            float dst;
            float mxf;
            cout<<"Give Flight Number: ";
            cin>>fn;
            cout<<"Give Destination: ";
            cin>>dest;
            cout<<"Distance: ";
            cin>>dst;
            cout<<"Set Max Fuel: ";
            cin>>mxf;
            FlightNO = fn;
            Destination = dest;
            Distance = dst;
            MaxFuelCapacity = mxf;
        }

        void ShowInfo() {
            cout<<"Flight Number: "<<FlightNO<<endl;
            cout<<"Destination: "<<Destination<<endl;
            cout<<"Distance: "<<Distance<<endl;
            cout<<"Max Fuel: "<<MaxFuelCapacity<<endl;

            if((double)MaxFuelCapacity >= CalFuel()) cout<<"Fuel capacity is fit for this flight distance"<<endl;
            else cout<<"Not sufficient Fuel Capacity for this flight."<<endl;
        }
};

int main() {
    FlightManagement f;
    f.FeedInfo();
    f.ShowInfo();
    return 0;
}
