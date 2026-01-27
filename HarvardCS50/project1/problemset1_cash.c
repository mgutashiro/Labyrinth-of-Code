#include <cs50.h>
#include <stdio.h>

const int quarter = 25;
const int dime = 10;
const int nickel = 5;
const int penny = 1;

int calculate_coinTotal(int change, int coin_value);

int main(void)
{
    // for incorrect input
    int change;
    do
    {
        change = get_int("Enter Change Here: ");
    }
    while (change < 0 || change > 99);

    // for outputting specific change

    int quarters = calculate_coinTotal(change, quarter);
    change %= quarter;

    int dimes = calculate_coinTotal(change, dime);
    change %= dime;

    int nickels = calculate_coinTotal(change, nickel);
    change %= nickel;

    int pennies = calculate_coinTotal(change, penny);
    change %= penny;

    // calculating + printing total # of coins
    int total_coins = quarters + dimes + nickels + pennies;
    printf("Total coins owed: %i\n", total_coins);
    printf("-----------------------\n");
    printf("Number of Quarters: %i\n", quarters);
    printf("Number of Dimes: %i\n", dimes);
    printf("Number of Nickels: %i\n", nickels);
    printf("Number of Pennies: %i\n", pennies);
}

int calculate_coinTotal(int change, int coin_value)
{
    return change / coin_value; // integer division does the work
}
