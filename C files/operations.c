#include <stdio.h>
#include "operations.h"

void checkBalance(double balance){
  printf("Your current balance is : Ksh%.2f\n", balance);
}
double deposit(double balance){
  double amount;

  printf("Enter deposit amount: \n");
  scanf(" %lf", &amount);

  if(amount <= 0){
        printf("Invalid deposit amount!\n");
        return balance;
}

    balance += amount;
    printf("Ksh %.2f deposited successfully.New balance is Ksh %.2f\n", amount, balance);
    return balance;
}

  double withdraw(double balance){
    double amount;
    printf("Enter withdrawal amount: \n");
    scanf(" %lf", &amount);

    if(amount <= 0 ){
        printf("Invalid amount!\n");
        return balance;
    }
    if(amount > balance){
        printf("Insufficient balance!\n");
        return balance;
    }
    balance -= amount;
    printf("Ksh %.2f withdrawn successfully.New balance is Ksh %.2f\n", amount, balance);
    return balance;
  }
