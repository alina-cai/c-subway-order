#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char order[21] = "";
    char strSandwich[21];
    char strSnack[21] = "";
    char strDrink[21] = "";
    bool bVeggie = false;
    bool bChips = false;
    bool bCookies = false;
    bool bDrink = false;
    bool bBottle = false;
    bool bTooManySnacks = false;
    float fCost = 0.0;
    int iCalories = 0;
    
    // user input
    printf("Welcome to the Sandwich Shop\n");
    printf("Would you like a veggie or roast chicken Sub? (v/c) ");
    scanf("%s", order);
    if (tolower(order[0]) == 'v') {
        bVeggie = true;
        strcpy(strSandwich, "veggie");
    }    
    else {
        bVeggie = false; 
        strcpy(strSandwich, "roast chicken");
    }
    printf("Would you like chips? (y/n) ");
    scanf("%s", order);
    if (tolower(order[0]) == 'y') {
        bChips = true;
        strcpy(strSnack, "and chips");
    }    
    else {
        bChips = false;   
    }
    printf("Would you like cookies? (y/n) ");
    scanf("%s", order);
    if (tolower(order[0]) == 'y') {
        bCookies = true;
        strcpy(strSnack, "and cookies");
    }    
    else {
        bCookies = false;   
    }    
    printf("Would you like a drink? (y/n) ");
    scanf("%s", order);
    if (tolower(order[0]) == 'y') {
        bDrink =  true;
        printf("Would you like a bottle or a fountain drink? (b/f) ");
        scanf("%s", order);
        if (tolower(order[0]) == 'b') {
            bBottle = true;
            strcpy(strDrink, "and bottle drink");
        }    
        else {
            bBottle = false; 
            strcpy(strDrink, "and fountain drink");
        }    
    }        
    else
        bDrink = false;
             
    // question 1
    if ((bChips == true) and (bCookies == true)) {
        bTooManySnacks = true;
    }

    // question 2
    if (bVeggie == true) {
        iCalories = iCalories + 460;
        fCost = fCost + 5.5;
    }
    // question 3
    else {
        iCalories = iCalories + 620;
        fCost = fCost + 6.75;
    }
    
    // question 4
    if (bChips == true) {
        iCalories = iCalories + 222;
        fCost = fCost + 1.1;
    }

    //question 5
    if (bCookies == true) {
        iCalories = iCalories + 440;
        fCost = fCost + 1.6;
    }

    // question 6
    if (bBottle == true) {
        iCalories = iCalories + 187;
        fCost = fCost + 1.8;
    }

    // question 7
    if ((bBottle == false) and (bDrink == true)) {
        iCalories = iCalories + 260;
        fCost = fCost + 1.3;
    }

    // question 8
    if ((bChips == true || bCookies == true) and (bDrink == true)) {
        fCost = fCost - 1;
    }

    // output
    if (bTooManySnacks){ 
        printf("You can't order both cookies and chips, get out of the line\n");
    }
    else {
        printf("\n\nYour order of %s sandwich %s %s is\n ",
            strSandwich, strSnack, strDrink);
        printf("\t$%.2f and %d calories\n\n",
             fCost, iCalories);  
    }            
    return 0;
}