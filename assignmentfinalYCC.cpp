#include <iostream>
#include <string>
using namespace std;

//Variables
double money = 1000.0; 
int correctPin = 1234;   

//Function store Menu 
void displayMenu() {
    cout << "\t=========================================\t\n";
    cout << "\t=========================================\t";
    cout << "\n\tATM Menu:\n\t";
    cout << "\t1. Check Balance\n\t";
    cout << "\t2. Withdraw Cash\n\t";
    cout << "\t3. Deposit Money\n\t";
    cout << "\t4. Change PIN\n\t";
    cout << "\t5. Exit\t";
   cout << "\n\t=========================================\t";
    cout << "\n\t=========================================\t";
}

//True/False
bool authenticate(int enteredPin) {
    return (enteredPin == correctPin);
}

//Function
void changePin() {
    int newPin, confirmPin;

    while (true) {
        cout << "\n\t=========================================\t";
        cout << "\n\tEnter your new PIN: ";
        cin >> newPin;
        string newPinStr = to_string(newPin);

        if (newPin == correctPin) {
            cout << "\n\t=========================================\t";
            cout << "\n\tYour new PIN is the same as your old PIN. Please try again.\n";
        } 
        else if (newPinStr.length() != 4) {
            cout << "\n\t=========================================\t";
            cout << "\n\tPIN must be exactly 4 digits. Please try again.\n";
        }
        else {
           
            cout << "\n\t=========================================\t";
            cout << "\n\tPlease re-enter your new PIN to confirm: ";
            cin >> confirmPin;

            if (confirmPin == newPin) {
                correctPin = newPin; // Update the PIN
                cout << "\n\t=========================================\t";
                cout << "\n\tPIN changed successfully!\n";
                break; 
            } 
            else {
                cout << "\n\t=========================================\t";
                cout << "\n\tPINs do not match. Please try again.\n";
            }
        }
    }
}

int main() {
    //Variables
    int choice;
    int enteredPIN;
    int attempts = 3; 
    double amount;

    cout << "Welcome to the ATM Machine!\n";

    while (attempts > 0) {
        cout << "Please enter your PIN (" << attempts << " attempts remaining): ";
        cin >> enteredPIN;

        
        if (authenticate(enteredPIN)) {
            break;
        }
         else {
            attempts--;
            if (attempts > 0) {
              cout << "\n\tIncorrect PIN. Please try again.\n";
            }
             else {
                cout << "\n\t=========================================\t";
                cout << "\n\tIncorrect PIN. No attempts remaining. Exiting...\n";
                return 0; 
            }
         }
    }

   //while loop
    while (true) {
        displayMenu();
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
            cout << "\n\t=========================================\t";
                cout << "\n\tYour current balance is: $" << money << "\n";
                break;

            case 2: 
            cout << "\n\t=========================================\t";
                cout << "\n\tEnter the amount to withdraw: $";
                cin >> amount;
                if (amount > money) {
                    cout << "\n\t=========================================\t";
                    cout << "\n\tNot enough money!\n";
                } 
                else if (amount<=0){
                    cout << "\n\t=========================================\t";
                     cout << "\n\tYour enter amount was Error.\n";
                }
                else {
                    money -= amount;
                    cout << "\n\t=========================================\t";
                    cout << "\n\tWithdrawal successful. Remaining balance: $" << money << "\n";
                }
                break;

            case 3: 
            cout << "\n\t=========================================\t";
                cout << "\n\tEnter the amount to deposit: $";
                cin >> amount;
                if (amount <= 0) {
                    cout << "\n\t=========================================\t";
                    cout << "\n\tInvalid amount!\n";
                } 
                else {
                    money += amount;
                    cout << "\n\t=========================================\t";
                    cout << "\n\tDeposit successful. New balance: $" << money << "\n";
                }
                break;

            case 4: 
                changePin();
                break;

            case 5: 
            cout << "\n\t=========================================\t";
                cout << "\n\tThank you for using the ATM. Goodbye!\t\n";
                return 0;

            default:
            cout << "\n\t=========================================\t";
                cout << "\n\tInvalid choice. Please try again.\n";
        }
        
    }

    return 0;
}