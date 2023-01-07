#include <stdio.h>
#include <stdlib.h>     // Library for basic functions
#include <time.h>		// Library for Srand function


// Team Sous-marin Pro Max
// Name : Akilesh Subhadu, Student ID : M00851681
// Name : Harshal Chawla, Student ID : M00909042

// The use of function helps to write the code once and use it many times rather writing the code again and again
// * To declare pointer = indirection operator(value at address)
// why file pointer should be null? To initialize a pointer variable when that pointer variable hasn’t been assigned any valid memory address yet
// rand() generates a number from 0-32,767
// & at the address of


void Drawing(char*Name_Of_File)
{
    FILE *pfile = NULL;                       //Declaration of file pointer,the pointer's value is initialized as NULL.Good practice to assign null if declaring a pointer
    char buffer[256];                         //The buffer will act as a container, an array of characters to hold one line of our file one line at a time. Maximum input size in the buffer is 256
    pfile = fopen(Name_Of_File, "r");         //The file is opened and the variable pfile takes the value of the file pointer
    while (fgets(buffer,256, pfile) != NULL)  //checks if a new line or end of file  has been reached and stores the file line in buffer.
                                              //If the end of the file is reached, fgets will return null
    {
        printf("%s", buffer);                 //outputs the file line
    }
    fclose(pfile);                            // closes the file
    //A pointer to null (the 0 memory address) should never be dereferenced/accessed(*).
    //Doing so will at best cause abrupt program termination.
}


int faces_validation()
{
    int Faces;                                   //Declaration of the variable faces as integer
    char*Name_Of_File = "errorfile.txt";         //Declaration of the Name_of_File pointer and initializing it as "errorfile.txt".

    printf("\n Input number of faces: ");
    scanf("%d", &Faces);                         //Input the number of faces and stores it in variable Faces
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n");
    while (Faces <=1 || Faces>=25)               //While loop checks if number of faces is out of range
    {
        sleep(1);                                // If true, it will return an error image and continues to loop until user input is in the appropriate range
        Drawing(Name_Of_File);
        printf("\n The range for number of faces is (2-24)! "); // Validation of data
        printf("\n Input number of faces : ");
        scanf("%d", &Faces);                     //stores user input in variable faces
        printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n");

    }
    return (Faces);                              //number of faces is returned
}


int throws_validation()
{
    int Throws;                                   //Declaration of variable throws as integer
    char*Name_Of_File = "errorfile.txt";          //Declaration of file name pointer and initializing it as "errorfile.txt".

    printf("\n Input number of throws: ");
    scanf("%d", &Throws);                         //stores user input in variable throws
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n");
    while (Throws <=1 || Throws >=500)            // while loop checks if number of throws is out of range
    {
        sleep(1);                                            // If true, it will return an error image and continues to loop until user input is in appropriate range
        Drawing(Name_Of_File);
        printf("\n The range for number of throws is (2-499)! "); //validation of data
        printf("\n Input number of throws : ");
        scanf("%d", &Throws);                     //stores user input in variable throws
        printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n");

    }

    return (Throws);                              //number of throws is returned
}

void Generate_Randomnumber(int min, int max, int Throws, int *random_numberArray)  //The function takes as parameter the minimum and the maximum number of faces,
                                                                              //The number of throws
{                                                                             //And the pointer which points to the first element of array random_number
    srand(time(0));                                                           //uses the current time as a seed to generate random numbers
    int i;
    for (i = 0; i < Throws; i++)
    {                                                                         //iterates n times where n is the number of throws
        int number = (rand() % max) + min;                                    //Generate a random number between the minimum and maximum number inclusive
        *random_numberArray = number;                                         //The random number generated is stored in the array random_numberArray
        random_numberArray = random_numberArray + 1;                          //The pointer is incremented to point to the next address in the array random_numArray.
    }
}


void Output_Randomvalues(int *random_numberArray, int Throws)                //Function  takes as parameter the number of throws
{                                                                            //And points to the first element of the array random_numberArray .

    printf("\nGenerating throws:\n");

    for (int i = 0; i < Throws; i++)                                         //For loop iterates through all elements in the array random_numberArray.
    {   if (Throws <= 20)
        {
        printf("\n%d\n", *random_numberArray);                               //Outputs the value pointed by the pointer
        random_numberArray = random_numberArray +1;                          //The pointer is incremented to point to the next address in the array random_numArray.
        usleep(500000);                                                      //usleep function is microsecond and 500000 = 0.5 s, usleep allows decimal values
        }
        else                                                                 // If Throws >20 , the throws will be generated without a delay
        {
        printf("\n%d\n", *random_numberArray);
        random_numberArray = random_numberArray +1;

        }
    }
}

void occurences_And_Percentage(int Faces,int Throws, char percentage,int *random_numberArray, int occurrence)
{
     for (int i = 1; i < (Faces + 1); i++)                                                      //Loops through every face value
    {
        occurrence = 0;                                                                         //occurrence is set to 0 and after each iteration of face,it becomes zero again
        for (int j = 1; j < (Throws + 1); j++)                                                  // iterates through the array  random_numberArray to calculate occurrence
        {
            if (*random_numberArray == i)                                                       //To check if the element in random_numberArray is the same as i,
            {
                occurrence = occurrence + 1;                                                    //IF TRUE, occurrence of that value of face is incremented
            }
            random_numberArray = random_numberArray + 1 ;                                       //The pointer is incremented to point to the next address in the random_numberArray.
        }
        random_numberArray = random_numberArray - Throws;                                       //The pointer returns to the first element of the array
        printf(" \n occurrences of %d : %.2lf %c \n  ", i, ((occurrence / ((double)Throws)) * 100), percentage); // .2lf (.2 is for 2 decimal places and lf is for double datatype)
        usleep(500000);                                                                         // Each throws value will be outputed after 0.5 seconds
    }
}


int main()
{

    int Faces, Throws,occurrence;
    char percentage = '%';


    char *welcome = "welcome.txt";
    char *start_rolling = "START.txt";       // Declaration of Pointers
    char *Num_occurences = "OCCURRENCES.txt";


    Drawing(welcome);                   //Displays welcome page image
    sleep(1);                           //Program to sleep for 1 second
                                        //The sleep function gives a simple way to make the program wait for a short interval


    Faces = faces_validation();          // Calling function. The number of throws which is returned from the faces_validation function is stored in variable Faces.
    sleep(1);


    Throws = throws_validation();       // Calling function. The number of throws which is returned from the throws_validation fucntion is stored in variable Throws.
    sleep(1);

    Drawing(start_rolling);             //Displays start rolling image
    sleep(3);                           //Program to sleep for 3 seconds


    int random_numberArray[Throws];     //Array random number is initialized with size of throws(the number of throws returned).
    Generate_Randomnumber(1,Faces, Throws, random_numberArray); //generate random numbers and stores it in array random_numberArray.
    Output_Randomvalues(random_numberArray, Throws);            //prints the random values.
    sleep(1) ;


    Drawing(Num_occurences);                                    // Display OCCRURENCES image
    sleep(1);
    occurences_And_Percentage(Faces, Throws,percentage,random_numberArray,occurrence);  //calling function and display percentages of occurrences for each faces
    printf("\n--------------------------------------------------------------------------------------------END OF PROGRAM----------------------------------------------------------------------------------------------------------");

    return 0;
}
