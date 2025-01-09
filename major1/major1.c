#include "major1.h"

int main() {
    

    printf("Hello, World!\n");

    //user input choice
    unsigned int choice;
    unsigned int num;
    do {    
        //Menu 
        printf("Enter the menu option for the operation to perform: \n");
        printf("(1) Count Leading Zeroes \n");
        printf("(2) Endian Swap \n");
        printf("(3) Rotate-right \n");
        printf("(4) Parity \n");
        printf("(5) EXIT \n");
        scanf("%u", &choice);

        
        switch(choice){
            case 1: 
                do {
                    printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
                    scanf("%u", &num);
                    // Clear the input buffer if scanf failed
                    if(num != 1) {
                        int ch;
                        while((ch = getchar()) != '\n' && ch != EOF);
                    }
                } while(num != 1);
                //call clz function
                printf("The number of leading zeros in %u is %u\n", num, clz(num)); 
                break;
            case 2:
                    printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
                    scanf("%u", &num);

                        int swapped = endian(num);

                    // Print the original and swapped values
                     printf("Swapped: 0x%08X\n", swapped);


                break;
            case 3:
                //call parity function
                break;
            case 4:
                //call rotate function
                break;
            case 5:
                //exit program
                printf("Program terminating. Goodbye...");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

    }while(choice != 5);

    return 0;
}