// #include "types.h"
// #include "stat.h"
// #include "user.h"

// int main(void)
// {
//     char buffer[16]; 
//     int input_num;

//     printf(1, "Enter a number: ");
//     gets(buffer, sizeof(buffer)); 
//     input_num = atoi(buffer);     

//     int result = find_digital_root(input_num);
//     printf(1, "Digital root of %d is %d\n", input_num, result);

//     exit();
// }


#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    // Check if the number of arguments is correct
    if (argc != 3)
    {
        printf(2, "Usage: %s source_file destination_file\n", argv[0]);
        exit();
    }

    // Print the source and destination file names
    printf(1, "Source File: %s\n", argv[1]);
    printf(1, "Destination File: %s\n", argv[2]);

    // Now you can implement the logic to copy the content of the source file to the destination file

    exit();
}
