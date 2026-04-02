#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Balance(double* balance);
bool CheckEnoughMoney(double balance, double amount);
void ClearScreen(void) { //clears the screen
    system("cls"); 
}
void WelcomeMessage(void) { //Message when the program starts
    printf(" Virtual Bank at West\n");
    printf("                              WELCOME\n");
}
bool AskPin(void) { //Ask user for pin and error handling
    int pin = 0;
    printf("Enter Pin: ");
    for (int attempt = 1; attempt <= 3; attempt++) {
        if (attempt != 1)
            printf("Invalid PIN, Re-enter Pin: "); //Only prompts if it's not the first attempt
        scanf("%d", &pin);

        if (pin >= 1000 && pin <= 9999 && attempt <= 3) { //If pin is 4 digits and have not used all 3 attempts
            ClearScreen();
            return true;
        }
    }
    
    printf("Sorry you can\'t continue, contact your bank for assistance!"); //prompts if user entered invalid pin for 3 times
    return false; //return false if user entered invalid pin for 3 times
}
bool AskReceipt(void) { //Ask user for receipt
    char choice = ' ';
    bool validInput = false;

    while (!validInput) { //loops until user types a valid input
        printf("                        Receipt y or Y -> Yes             No <- n or N  \n");
        printf("                        Enter choice: ");
        scanf(" %c", &choice); //Skips newline

        if (choice == 'y' || choice == 'Y') { //If user typed y or Y
            ClearScreen();
            return true;
        }
        if (choice == 'n' || choice == 'N') { //If user typed n or N
            ClearScreen();
            return false;
        }
        //Runs if user input is invalid
        ClearScreen();
        printf("                        Invalid choice, try again\n");
    }
    return false;
}
int AskMenuOption(void) { //Ask user for option
    int option = 0;
    bool validOption = false;
    while (!validOption) {//loops forever until user typed a valid input
        printf("CHOOSE FROM THE FOLLOWING\n");
        printf("                                    1 -> Fast Cash             Withdraw      <- 2\n");
        printf("                                    3 -> Deposit                Check Balance <- 4\n");
        printf("                                    5 -> Get Card Back\n");
        printf("Enter your choice: ");
        scanf("%d", &option);    
        if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5) { //if user input is valid
            ClearScreen();
            return option;
        }
        //only runs if user input is invalid
        ClearScreen();
        printf("Invalid Entry\n");
    }
    return false;
}
void FastCash(double* balance) { //option 1
    ClearScreen();
    bool validInput = false;
    int userInput = 0;
    while (!validInput) { //loops until valid input
        printf("Press (0 to exit):\n");
        printf("1 --> $20.00                $40.00  <-- 2\n");
        printf("3 --> $80.00                $100.00 <-- 4\n");
        scanf("%d", &userInput);
        switch (userInput) {
            case 0:
                ClearScreen();
                return;
            case 1:
                ClearScreen();
                if (!CheckEnoughMoney(*balance, 20))
                    break;
                *balance -= 20.00;
                Balance(balance); //displays current balace
                return;
            case 2:
                ClearScreen();
                if (!CheckEnoughMoney(*balance, 40))
                    break;
                *balance -= 40.00;
                Balance(balance);
                return;
            case 3:
            if (!CheckEnoughMoney(*balance, 80))
                    break;
                ClearScreen();
                *balance -= 80.00;
                Balance(balance);
                return;
            case 4:
            if (!CheckEnoughMoney(*balance, 100))
                    break;
                ClearScreen();
                *balance -= 100.00;
                Balance(balance);
                return;
        }
        //only runs if invalid input
        ClearScreen();
        printf("Don't have enough money, try again...\n");
    }
}
void Withdraw(double* balance) { //option 2
    double withdrawAmount = 0.0;
    bool validInput = false;
    while (!validInput) { //loops until valid input
        printf("Enter amount to withdraw (enter 0 to cancel): ");
        
        scanf("%lf", &withdrawAmount);
        if (withdrawAmount <= 0.0001 && withdrawAmount >= -0.0001) { //If user enters zero
            return;
        }
        if (withdrawAmount < 0) { //If user enters negative number
            printf("Can't enter a negative value...\n");
        }
        else if (withdrawAmount > *balance) { //If amount withdraw is greater than the balance
            printf("You don't have enough money...\n");
        }
        else if (withdrawAmount <= *balance) {//If amount withdraw is less than or equal to the balance
            *balance -= withdrawAmount; //subtract withdraw amount from balance
            printf("Take your cash\n");
            Balance(balance); //displays current balance
            return;
        }
        else {
            printf("Invalid input, try again...\n");
        }
    }

}
void Deposit(double* balance) { //option 3
    ClearScreen();
    double depositAmount = 0;
    int validInput = false;
    while (!validInput) { //loops until valid input
        printf("Enter amount to deposit (enter 0 to cancel): ");
        scanf("%lf", &depositAmount);
        if (depositAmount <= 0.0001 && depositAmount >= -0.0001) { //If user enters zero
            return;
        }
        if (depositAmount < 0) { //if user enters negative value
            printf("Deposit amount can't be negative\n");
        }
        else if (depositAmount > 0) { //If user enters more than 0
            *balance += depositAmount; //add deposit amount to balance
            Balance(balance); //displays current balance
            return;
        }
        else {
            printf("Invalid input, try again\n");
        }
    }
}
void Balance(double* balance) { //option 4
    printf("your balance is: %.2lf$\n", *balance);
}
bool AskAnotherTransaction(void) { //Ask user for another transaction
    int option = 0;
    bool validInput = false;
    while (!validInput) { //loops until user hits valid input
        printf("1 -> Another Transaction                   Get Card Back <- 2\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        if (option == 1) { //If user enters 1
            ClearScreen();
            return true;
        }
        if (option == 2) { //If user enters 2
            ClearScreen();
            return false;
        }
        //runs if user input is invalid
        ClearScreen();
        printf("Invalid input...\n");
    }
    return false;
}
void GoodByeMessage(void) { //Message when the program terminates
    printf("THANK YOU FOR USING OUR VIRTUAL BANK SYSTEM\n");
    printf("GOODBYE. . .\n");
}
bool CheckEnoughMoney(double balance, double amount) { //Checks if user has enough money to withdraw or not
    if (balance - amount < 0)
        return false;
    return true;
}
int main(void) {
    WelcomeMessage(); //display welcome message
    double balance = 5000.0; //total balance
    bool end = false;
    bool validPin = AskPin(); //ask for pin
    int option = 0;
    bool receipt = false;
    if (validPin) {
        receipt = AskReceipt(); //ask for receipt
        while (!end) { //while user didn't choose to get card back
            option = AskMenuOption(); //ask for option
            switch (option) {
                case 1:
                    FastCash(&balance); //pass by pointer
                    break;
                case 2:
                    Withdraw(&balance); //pass by pointer
                    break;
                case 3:
                    Deposit(&balance); //pass by pointer
                    break;
                case 4:
                    ClearScreen();
                    Balance(&balance); //pass by pointer
                    break;
                case 5: //Get card back
                    end = true; //ends the program
                    break;
                default: //In case something bad happens
                    printf("Something went wrong...\n");
                    end = true;
            }
            if (!end) { //If program haven't ended
                end = !AskAnotherTransaction(); //program ends if user doens't want another trancsaction
            }
        }
        ClearScreen();
        if (receipt) { //If user wanted a receipt
            printf("Receipt printed\n");
        }
        GoodByeMessage();

    }
    return 0;
}