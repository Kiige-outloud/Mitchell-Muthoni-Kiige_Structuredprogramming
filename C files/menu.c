#include <stdio.h>
#include "menu.h"

void showMenu(){
  printf("=====MENU=====\n");
  printf("1. Balance inquiry.\n");
  printf("2. Deposit\n");
  printf("3. Withdraw\n");
  printf("4. Exit\n");
}

int getChoice(){
  int choice;
  printf("Enter your choice: \n");
  scanf(" %d", &choice);
  return choice;
}



