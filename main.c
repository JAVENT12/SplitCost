#include <stdio.h>
#include <time.h> // time_t, time()
#include <stdlib.h> // srand(), rand()
#include <stdbool.h> // bool
#include <ctype.h> // isdigit()
#include <string.h> // Include string 
#pragma warning(disable : 4996) // To supress errors

# define BUDGET 500
int people = 0;
double dividedCost, evenCost;

void display_welcome(void)
{
    puts("Cost split calculator"); // c string
    puts("Code by Jason Ventura!");
}
void say_goodbye(void)
{
    puts("All done!");
}
void display_instructions(void)
{
    puts(" Let's split the cost\n"
        " Define a budget\n"
        " Cost is random\n"
        " Decide how many people to split the cost between\n"
        " Decide how many days the cost is split over\n"
    );
};
void expense_per_day(float days, double cost)
{
    cost = cost / days;
    printf("The cost per day is %.2f\n", cost);
    printf("Splitting %.2f between %d people\n", cost, people);
    dividedCost = cost / people;
    printf("Everyone pays %.2f\n", dividedCost);
};
void split_expense(char* choice, float days)
{
    time_t now = time(NULL);
    srand(now);
    long cost = rand() % (BUDGET * 2 + 1);
    evenCost = cost;
    if (cost > BUDGET)
    {
        printf("The cost exceeded your budget of %d\n", BUDGET);
        printf("The cost is %lu\n", cost);
        exit(-1);
    }
    else
    {
        printf("The cost is %lu\n", cost);
        // Splitting across days? User char for input (y/n) and call another function calculating
        printf("Enter how many people ");
        scanf("%d", &people);
        printf("Are you splitting cost across days? (y/n) ");
        //if (*choice == '\n') split_expense(choice);
        do {
            *choice = getchar();
            if (*choice == '\n') continue; //If user just enters newline
            getchar(); // Also get enters newline
        } while (*choice != 'y' && *choice != 'n');
        if (*choice == 'y')
        {
            printf("Enter how many days \n ");
            scanf("%f", &days);
            printf("Splitting across %f days\n", days);
            expense_per_day(days, cost);
        }
        else
        {
            printf("Splitting %lu between %d people\n", cost, people);
            dividedCost = evenCost / people;
            printf("Everyone pays %.2f\n", dividedCost); // Display only the 1st 2 decimal places
        }
    }
}
char char_symbol;
float days;

int main(void)
{
    display_welcome();
    display_instructions();

    split_expense(&char_symbol, days);
    say_goodbye();
    return 0;
}
/*
=> C Pre-Processor (#include, #define)  -- Done
=> C Data Types (char, int, long, float, double) -- Done
=> C Functions: printf(),  scanf(), srand(), rand(), etc. -- Done
=> C Control Statements (if, if/else, switch) -- Done
=> C Loop Statements (for, while, do) -- Done
=> Any other C skill you'd like to demonstrate -- Handle incorrect input/exceptions
*/
