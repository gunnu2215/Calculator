#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin = 1234, enteredPin, option, count = 0;
    float balance = 1000.0, deposit, withdraw;
    int running = 1;

    printf("==== Welcome to the ATM Machine ====\n");

    // PIN check (3 attempts)
    while (count < 3) {
        printf("Enter your PIN: ");
        scanf("%d", &enteredPin);
        if (enteredPin == pin) {
            break;
        } else {
            printf("Incorrect PIN. Try again.\n");
            count++;
        }
    }
    if (count == 3) {
        printf("Too many incorrect attempts. Exiting...\n");
        return 0;
    }

    while (running) {
        printf("\n==== ATM Menu ====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Your current balance is: $%.2f\n", balance);
                break;
            case 2:
                printf("Enter amount to deposit: $");
                scanf("%f", &deposit);
                if (deposit > 0) {
                    balance += deposit;
                    printf("Deposit successful. New balance: $%.2f\n", balance);
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 3:
                printf("Enter amount to withdraw: $");
                scanf("%f", &withdraw);
                if (withdraw > 0 && withdraw <= balance) {
                    balance -= withdraw;
                    printf("Withdrawal successful. New balance: $%.2f\n", balance);
                } else {
                    printf("Invalid or insufficient funds.\n");
                }
                break;
            case 4:
                printf("Enter new PIN: ");
                scanf("%d", &pin);
                printf("PIN changed successfully.\n");
                break;
            case 5:
                printf("Thank you for using the ATM. Goodbye!\n");
                running = 0;
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}