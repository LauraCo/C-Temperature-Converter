#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

int main(int argc, char *argv[])
{
    char choice;
    float celsius;
    float farenheit;
    
    printf("Enter start measurement: \n");
    printf("C = Celsius \n");
    printf("F = Farenheit \n");
    
    scanf("%c", &choice);
    
    switch(choice) {
        case 'C':
        case 'c':
            printf("Please enter the temperature in Celsius: ");
            scanf("%f", &celsius);
            
            farenheit = (1.8 * celsius) + 32;
            printf("The temperature in Farenheit: %f \n", farenheit);
            
            break;
            
        case 'F':
        case 'f':
            
            printf("Please enter the temperature in Farenheit: ");
            scanf("%f", &farenheit);
            
            celsius = (farenheit - 32) / 1.8;
            printf("The temperature in Celsius: %f \n", celsius);
            
            break;
            
        default: 
            die("Invalid choice, choose either C or F");
    }
    
    return 0;
}