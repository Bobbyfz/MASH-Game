/*
 Author: Robert Feliz
 Date: 8/21/2020
 Purpose: Create a computer version of the MASH pen and paper game
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void clearKeyboardBuffer(void);
void runGame(void);

int main(int argc,char** argv)
{
    char choice;
    //main menu of the game
    do
    {
        printf("Welcome to MASH: A game that can predict your future!\nWould you like to play? (y/n)\n");
        scanf("%c",&choice);
        clearKeyboardBuffer();
    }while(choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n');
    
    if (choice == 'y'||choice == 'Y')
    {
        //function that is called to to start the game
        runGame();
    }else
    {
        exit(0);
    }
    
    printf("Thank you for playing MASH, come again soon!\n");
    return 0;
}


//function to validate user input
void clearKeyboardBuffer (void)
{
    char ch;
    scanf("%1c", &ch);
    
    while (ch != '\n' && ch != '\0')
    {
        scanf("%1c", &ch);
    }
}

void runGame(void)
{
    //variables for holding the various values
    char spouse1[100],spouse2[100],spouse3[100],car1[100],car2[100],car3[100],pet1[100],pet2[100],pet3[100],residence1[100],residence2[100],residence3[100],job1[100],job2[100],job3[100],finalSpouse[100],finalVehicle[100],finalPet[100],finalRes[100],finalJob[100];
    
    int kids1 = 0,kids2 = 0,kids3 = 0,salary1 = 0,salary2 = 0,salary3 = 0,finalSal = 0,finalKids = 0;
    
    char choice;
    
    //seed for the random number that is chosen at the end
    srand(time(0));
    
    printf("You have decided to have your fortune told\n");
    
    //have the user enter 3 of each category
    printf("Enter a person you love: ");
    fgets(spouse1,sizeof(spouse1),stdin);
    printf("Enter another person you love: ");
    fgets(spouse2,sizeof(spouse2),stdin);
    printf("Enter a person you hate: ");
    fgets(spouse3,sizeof(spouse3),stdin);
    
    printf("Enter a car you'd love to drive around: ");
    fgets(car1,sizeof(car1),stdin);
    printf("Enter another car you'd love to drive around: ");
    fgets(car2,sizeof(car2),stdin);
    printf("Enter a car you'd ashamed of taking out of the garage: ");
    fgets(car3,sizeof(car3),stdin);
    
    printf("Enter 3 numbers for your salary separated by a comma: ");
    scanf("%d,%d,%d",&salary1,&salary2,&salary3);
    clearKeyboardBuffer();
    
    printf("Enter a pet you'd love to have: ");
    fgets(pet1,sizeof(pet1),stdin);
    printf("Enter another pet you'd love to have: ");
    fgets(pet2,sizeof(pet2),stdin);
    printf("Enter a person you'd hate to have: ");
    fgets(pet3,sizeof(pet3),stdin);
    
    printf("Enter a place or city you want to live in: ");
    fgets(residence1,sizeof(residence1),stdin);
    printf("Enter another place or city you dream of living in: ");
    fgets(residence2,sizeof(residence2),stdin);
    printf("Enter a plce or city you would never want to live in: ");
    fgets(residence3,sizeof(residence3),stdin);
    
    printf("Enter a job you would never work in a day in your life for: ");
    fgets(job1,sizeof(job1),stdin);
    printf("Enter another dream job: ");
    fgets(job2,sizeof(job2),stdin);
    printf("Enter a job that you wouldn't want to wake up for: ");
    fgets(job3,sizeof(job3),stdin);
    
    printf("Alright, last question before your future is decided\n");
    printf("Enter 3 numbers to decide how many kids you will have separated by a comma: ");
    scanf("%d,%d,%d",&kids1,&kids2,&kids3);
    clearKeyboardBuffer();
    //random numbers for each category to decide which choice you will recieve
    
    int randSpouse = rand() % 4;
    int randVehicle = rand() % 4;
    int randSalary = rand() % 4;
    int randPet = rand() % 4;
    int randResidence = rand() % 4;
    int randJob = rand() % 4;
    int randKids = rand() % 4;
    int randMASH = rand() % 5;
    
    //switch cases to decide what is the final result from the categories
    switch (randSpouse)
    {
        case 0:
            strcpy(finalSpouse,spouse1);
            break;
        case 1:
            strcpy(finalSpouse,spouse2);
            break;
        case 2:
            strcpy(finalSpouse, spouse3);
            break;
    }
    switch (randVehicle)
    {
        case 0:
            strcpy(finalVehicle,car1);
            break;
        case 1:
            strcpy(finalVehicle,car2);
            break;
        case 2:
            strcpy(finalVehicle, car3);
            break;
    }
    switch (randSalary)
    {
        case 0:
            finalSal = salary1;
            break;
        case 1:
            finalSal = salary2;
            break;
        case 2:
            finalSal = salary3;
            break;
    }
    switch (randPet)
    {
        case 0:
            strcpy(finalPet,pet1);
            break;
        case 1:
            strcpy(finalPet,pet2);
            break;
        case 2:
            strcpy(finalPet, pet3);
            break;
    }
    switch (randResidence)
    {
        case 0:
            strcpy(finalRes,residence1);
            break;
        case 1:
            strcpy(finalRes,residence2);
            break;
        case 2:
            strcpy(finalRes, residence3);
            break;
    }
    switch (randJob)
    {
        case 0:
            strcpy(finalJob,job1);
            break;
        case 1:
            strcpy(finalJob,job2);
            break;
        case 2:
            strcpy(finalJob, job3);
            break;
    }
    switch (randKids)
    {
        case 0:
            finalKids = kids1;
            break;
        case 1:
            finalKids = kids2;
            break;
        case 2:
            finalKids = kids3;
            break;
    }
    
    //prints results from previous switch statements
    printf("MASH HAS DECIDED YOUR FATE\n");
    
    printf("You are going to be married to: %s",finalSpouse);
    printf("You are going to be driving a: %s",finalVehicle);
    printf("You are going to be making: $%d a year\n",finalSal);
    printf("You are going to own a(n): %s",finalPet);
    printf("You are going to be living in %s",finalRes);
    switch (randMASH)
    {
        case 0:
            printf("You will live in a Mansion!\n");
            break;
        case 1:
            printf("You will live in an Apartment!\n");
            break;
        case 2:
            printf("You will live in a Shack!\n");
            break;
        case 3:
            printf("You will live in a House!\n");
            break;
    }
    printf("You will be making a living as a %s",finalJob);
    printf("You will be living your life with %d kids\n",finalKids);
    
    //creates another loop so you can continue playing or quit out of the program
    do
    {
        printf("Do you want to play again? (Y/N)\n");
        scanf("%c",&choice);
        clearKeyboardBuffer();
    }while(choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n');
    
    if (choice == 'y'|| choice == 'Y')
    {
        runGame();
    }
    else
    {
        return;
    }
}
