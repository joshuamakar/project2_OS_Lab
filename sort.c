#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int 
atoimodified(const char *s)
{
  int n;
  int sign = 1;

  n = 0;
  if (*s == '-') {
    sign = -1;
    s++;
  }

  if(*s < '0' || *s > '9'){
    printf(2, "Invalid number\n");
    exit();
}
  while('0' <= *s && *s <= '9')
    n = n*10 + *s++ - '0';
  return sign * n;
}


int main(int argc, char *argv[])
{
    int sorted[100]; // Array to hold the sorted strings
    
    if(argc < 3){
        printf(2, "Usage: %s <numbers>\n", argv[0]);// Check if the user provided enough arguments if not, 
        //print usage message and exit
        exit();
    }

    for(int i = 1; i < argc; i++){

        sorted[i-1] = atoimodified(argv[i]); // Store the strings in the array after converting them to integers 
    }

    // Sort the strings using bubble sort
    for(int i = 0; i < argc - 2; i++){
        for(int j = 0; j < argc - 2 - i; j++){
            if((sorted[j]>sorted[j+1])){
                int temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }       

    // Print the sorted strings to the terminal
  

    printf(1, "Sorted numbers: \n");
    for(int i = 0; i < argc - 1; i++){
        printf(1, "%d\n", sorted[i]);
    }

    exit();

}

  


    
