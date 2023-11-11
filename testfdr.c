#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    char buffer[16]; 
    int input_num;

    printf(1, "Enter a number: ");
    gets(buffer, sizeof(buffer)); 
    input_num = atoi(buffer);     

    int result = find_digital_root(input_num);
    printf(1, "Digital root of %d is %d\n", input_num, result);

    exit();
}