#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, unsigned char** argv){
    unsigned char input[1000000];
    unsigned char rangeInput1;
    unsigned char rangeInput2;
    unsigned char z = 'z';
    int p = 0;
    unsigned char compareTo;
   
    ////////DEALING WITH INPUT////////
    /*------If no range is specified-------*/
    if (argc == 1){
        rangeInput1 = '$\000'; // needs to be first possible
        rangeInput2 = '$\377'; // needs to be last possible
    }
    /*------One input i.e. a----*/
    else if (argc == 2){
        rangeInput1 = argv[1][0];
        rangeInput2 = '$\377';//needs to be last possible char
    }
    /*----Two inputs i.e. a z------*/
    else if (argc == 3) {
        rangeInput1 = argv[1][0];
        rangeInput2 = argv[2][0];
    }
    /*-----Three inputs i.e. a-z----------*/
    else if (argc == 4){
        rangeInput1 = argv[1][0];
        rangeInput2 = argv[3][0];
    }
     
    ////////SOME REAL SLICK METHODS////////
    /*---------Finds the number of times a character occurs in a given string-------------*/
    /**
     *  In this case the variable string is going to be the input from the file saved as a string
     *  The for loop takes the string variable and goes through it character by character until the length is met 
     *  The if loops checks if the currect char == the specified char, ch and if it does then the numTimes is incremented and returns this number
     */
    int findNumTimes(const char* string, char ch)
    {
        int numTimes = 0;                           
        for (int i = 0; i <= strlen(input); i++){   
            if (string[i] == ch){                    
                numTimes++;
            }
        }
        return numTimes;
    }

    /*---------Prints the number of pound signs a character occurs in a given string--------*/
    /**
     *  This will make an empty char and then depending on the number returned by findNumTimes it will return some pound signs.
     *  Returns the char array which is used when I printf each line later
     */
    char* printSomeHashtags(char ch){
        char* ret= malloc(1000000*sizeof(char));
        for (int i = 0; i < findNumTimes(input, ch); i++){
            ret[i] = '#';
        }
        return ret;
    }

    ////////THIS IS WHERE THE FUN BEGINS////////
    /*----------Takes in the file and saves it to input ------*/
    /**
     *  This doesnt need much more explanation but it is how I "handled" the file.  
     *  I went char by char and fed each one into a char array with a huge buffer size.  
     *  No doubt that there is a better way to do it that doesnt use so much space but I couldnt figure it out and I'll revisit this in the future
     */
    int t = 0;
    for(int ch = getchar(); ch != EOF; ch = getchar()){
        input[p] = ch;
        p++;
    }
    
    /*------Print the range--------*/
    printf("Range: %c-%c\n", rangeInput1, rangeInput2);

    /*---------Here we print the range of letters being dealt with and store them into a character array----------*/
    for(int i = rangeInput1; i <= rangeInput2; i++){
        printf("%c:%5d %s\n", i, findNumTimes(input, i), printSomeHashtags(i));
       
    }
    //printf("\n");
 
    return 0;
}