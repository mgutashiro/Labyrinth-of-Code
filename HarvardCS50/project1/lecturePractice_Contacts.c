#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Hello! Please Answer the following questions.\n ");

    // Name, age, phone number, location
    string name = get_string("What is your name?: ");
    int age = get_int("What is your age? :");
    string phoneNumber = get_string("What is your phone number :");
    string location = get_string("What is your location?: ");

    printf("--------------------------- \n");
    printf("Thank you for your input.\n");
    printf("Name: %s\n", name);
    printf("Age: %i\n", age);
    printf("Phone Number: %s\n", phoneNumber);
    printf("Location: %s\n", location);
}