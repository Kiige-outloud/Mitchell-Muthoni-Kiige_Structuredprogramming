#include <stdio.h>
#include <stdlib.h>
#include "login.h"

int correctPIN = 2010;

int verifyPIN(int userPIN){
  return(userPIN == correctPIN);
  }

void checkUserPIN(){
  int userPIN;
  int attempts = 3;

  while(attempts > 0){
    printf("Enter PIN: \n");
    scanf("%d", &userPIN);

    if(userPIN < 999 || userPIN > 9999){
        printf("Invalid PIN length!\n");
        continue;
    }
    if(verifyPIN(userPIN)){
        printf("Access granted!\n");
        return;
    }else{
        attempts--;
        if(attempts > 0){
        printf("Incorrect PIN. Attempts left: %d\n", attempts);
        }else{
          printf("Incorrect PIN. No attempts left!\n");
        }

      }
  }

}
