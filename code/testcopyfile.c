#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    // Check if the number of arguments is correct
    if (argc != 3)
    {
        printf(2, "Usage: %s source_file destination_file\n", argv[0]);
        exit();
    }

    // Print the source and destination file names

    int status = copy_file(argv[1], argv[2]);

    if (status == -1)
        printf(1, "failed to copy\n", argv[2]);
    else
        printf(1, "copied successfully\n", argv[2]);

    // Now you can implement the logic to copy the content of the source file to the destination file

    exit();
}
