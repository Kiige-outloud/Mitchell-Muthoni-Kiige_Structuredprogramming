#include <stdio.h>
#include "login.h"
#include "menu.h"
#include "operations.h"

int main(){
  double balance = 1000.0;
  int choice;

  checkUserPIN();

  while(1){
    showMenu();
    choice = getChoice();

    switch(choice){
        case 1:
            checkBalance(balance);
            break;
        case 2:
            balance = deposit(balance);
            break;
        case 3:
            balance = withdraw(balance);
            break;
        case 4:
            printf("Thankyou for using the ATM :)\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");

    }
  }
  return 0;
}
