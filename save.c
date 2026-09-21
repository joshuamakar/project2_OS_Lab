#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    if(argc < 3){
        printf(2, "Usage: %s <filename> <content>\n", argv[0]);// Check if the user provided enough arguments if not, print usage message and exit
        exit();
    }
    int fd;
    fd= open(argv[1],  O_CREATE | O_WRONLY);//

    if(fd < 0){
        printf(2, "Error opening file %s\n", argv[1]);// Check if the file was opened successfully if not, print error message and exit
        exit();
    }

    //write(fd, argv[2], strlen(argv[2]));// Write the content to the file
    //write(fd, "\n", 1);

    //if we are required to write multiple strings to the file, we can loop through the arguments and write each one to the file, but will comment this out 
     
    int i;
     for(i = 2; i < argc; i++){
         write(fd, " ", 1);// Write a space between each string
         write(fd, argv[i], strlen(argv[i]));// Write the string to the file
     }
     
    write(fd, "\n", 1);
    close(fd);// Close the file descriptor


    exit();
}
