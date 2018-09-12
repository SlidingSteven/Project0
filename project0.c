#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, unsigned char** argv){
    unsigned char input[1000000];
    unsigned char rangeInput1;
    unsigned char rangeInput2;
    unsigned char z = 'z';
   
    /*----Two inputs i.e. a z------*/
    if (argc == 3) {
        rangeInput1 = argv[1][0];
        rangeInput2 = argv[2][0];
        printf("r1 = %c\nr2 = %c\n", rangeInput1, rangeInput2);
    }
    /*-----Three inputs i.e. a-z----------*/
    else if (argc == 4){
        rangeInput1 = argv[1][0];
        rangeInput2 = argv[3][0];
        //printf("r1 = %c\nr2 = %c\n", rangeInput1, rangeInput2);

    }
    /*------One input i.e. a----*/
    else{
        rangeInput1 = argv[1][0];
        rangeInput2 = z;
    }
   
   printf("\nZero %s\n One %s\n Two %s\n Three %s\n Int %i\n", argv[0], argv[1], argv[2], argv[3], argc);

     //rangeInput1 = argv[1][0];  //This saves the first char entered for the range 
     //rangeInput2 = argv[2][0];  //This saves the second char entered for the range
     //printf("r1 = %c\nr2 = %c\nr = %i", rangeInput1, rangeInput2, argc);
          //  printf("r1 = %c\nr2 = %c\n", rangeInput1, rangeInput2);

    int p = 0;
    unsigned char compareTo;

    printf("Range %c-%c\n", rangeInput1, rangeInput2);

    /*---------Finds the number of times a character occurs in a given string-------------*/
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
    char* printSomeHashtags(char ch){
        char* ret= malloc(1000000*sizeof(char));
        for (int i = 0; i < findNumTimes(input, ch); i++){
            ret[i] = '#';
        }
        return ret;
    }

    /*----------Takes in the file and saves it to input ------*/
    
    int t = 0;
    for(int ch = getchar(); ch != EOF; ch = getchar()){
        input[p] = ch;
        p++;
    }
    /*-------------*/
    /*
    char* input2[1000000];
    char* readIn(){
        unsigned char input1[1000000];
        for(int ch = getchar(); ch != EOF; ch = getchar()){
            input1[p] = putchar(ch);
            p++;
        
        return (*input1);
    }
    input2 = readIn();*/
    //---------Here we print the range of letters being dealt with and store them into a character array----------/
    char lettersInRange[26]; //sets up a char array to put the range of letters into 
    int rangeCounter = 0; // keeps track of the letter in the range you are on 
    for(int i = rangeInput1; i <= rangeInput2; i++){
        printf("\n%c:\t%i %s", i, findNumTimes(input, i), printSomeHashtags(i));
        //printf("%c\t%i\n", i, findNumTimes(input1, i));

        lettersInRange[rangeCounter] = i;
        rangeCounter++;
    }
    printf("\n");
 
    return 0;
}