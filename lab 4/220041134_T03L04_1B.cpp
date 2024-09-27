#include<iostream>

using namespace std;

int totAccountsCreated = 0, totAccountsPresent = 0;
double totSourceTaxCollected = 0;

class BankAccount {
    private:
        string account_no;
        string account_holder_name;
        string account_type;
        double current_balance;
        const double minimum_balance;
    
    public:
        BankAccount(string acNO, string acHN, string acT, double cb, double mb) : 
             account_no(acNO),
             account_holder_name(acHN),
             account_type(acT),
             current_balance(cb),
             minimum_balance(mb)
             {
                if(current_balance < minimum_balance) {
                    cout<<"Initial balance is too low! it can't be less than minimum balance"<<endl;
                    current_balance = minimum_balance;
                }
                totAccountsCreated++;
                totAccountsPresent++;
             }

        ~BankAccount() {
            cout<<"Account of Mr. "<<account_holder_name<<" with account no "<<account_no<<" is destroyed with a balance of BDT "<<current_balance<<endl;
            totAccountsPresent--;
        }

        void showAccountDetails() {
            cout<<"Account Number: "<<account_no<<endl;
            cout<<"Account Holder Name: "<<account_holder_name<<endl;
            cout<<"Account Type: "<<account_type<<endl;
            cout<<"Current Balance: BDT "<<current_balance<<endl;
            cout<<"Minimum Balance: BDT "<<minimum_balance<<endl;
        }

        void showBalance() {
            cout<<"Current Balance: BDT "<<current_balance<<endl;
        }

        void deposit(double amount) {
            if(amount <= 0) cout<<"Invalid deposit ammount!"<<endl;
            else {
                current_balance += amount;
                cout<<"Deposited amount: BDT "<<amount<<endl;
                showBalance();
            }
        }

        void withdrawal(double amount) {
            if(amount <= 0) cout<<"Invalid withdrawal amount!"<<endl;
            else if(amount > (current_balance-minimum_balance)) cout<<"Insufficient balance!"<<endl;
            else {
                current_balance -= amount;
                cout<<"Withdrawal amount: BDT "<<amount<<endl;
                showBalance();
            } 
        }

        void giveInterest(double interest_rate = 3.0) {
            double interest = (current_balance*interest_rate) / 100.0;
            double tax = (interest*10) / 100.0;
            interest -= tax;
            current_balance += interest;
            cout<<"Interest added at a rate of "<<interest_rate<<"%"<<endl;
            showBalance();
        }

        double get() const {
            return current_balance;
        }
};

void display_stat() {
    cout<<"Total BankAccount objects created: "<<totAccountsCreated<<endl;
    cout<<"Total BankAccount objects currently present: "<<totAccountsPresent<<endl;
    cout<<"Total source tax collected: "<<totSourceTaxCollected<<endl;
}

BankAccount Larger(const BankAccount A, const BankAccount B) {
    if(A.get() > B.get()) return A;
    return B;
}

int main() {
    return 0;
}