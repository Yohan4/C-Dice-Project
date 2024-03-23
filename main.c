#include <stdio.h>
#include <stdlib.h>    
#include <time.h>		


// Function to display content from a given file.
void Drawing(char*Name_Of_File)
{
    FILE *pfile = NULL;                       
    char buffer[256];                         
    pfile = fopen(Name_Of_File, "r");         
    while (fgets(buffer,256, pfile) != NULL)  
                                              
    {
        printf("%s", buffer);               
    }
    fclose(pfile);                           
   
}

// Function to validate the number of faces input by the user.
int faces_validation()
{
    int Faces;                                   
    char*Name_Of_File = "errorfile.txt";        

    printf("\n Input number of faces: ");
    scanf("%d", &Faces);                         
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n");
    while (Faces <=1 || Faces>=25)               
    {
        sleep(1);                               
        Drawing(Name_Of_File);
        printf("\n The range for number of faces is (2-24)! "); 
        printf("\n Input number of faces : ");
        scanf("%d", &Faces);                     
        printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n");

    }
    return (Faces);                             
}

// Function to validate the number of throws input by the user.
int throws_validation()
{
    int Throws;                                   
    char*Name_Of_File = "errorfile.txt";          
    printf("\n Input number of throws: ");
    scanf("%d", &Throws);                         
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n");
    while (Throws <=1 || Throws >=500)            
    {
        sleep(1);                                           
        printf("\n The range for number of throws is (2-499)! ");
        printf("\n Input number of throws : ");
        scanf("%d", &Throws);                     
        printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n");

    }

    return (Throws);                              
}

// Function to generate a specified number of random numbers within a range and store them in an array.
void Generate_Randomnumber(int min, int max, int Throws, int *random_numberArray)  
                                                                              
{                                                                             
    srand(time(0));                                                          
    int i;
    for (i = 0; i < Throws; i++)
    {                                                                         
        int number = (rand() % max) + min;                                    
        *random_numberArray = number;                                         
        random_numberArray = random_numberArray + 1;                          
    }
}

// Function to output the generated random numbers, with a delay for a smaller number of throws.
void Output_Randomvalues(int *random_numberArray, int Throws)                
{                                                                            

    for (int i = 0; i < Throws; i++)                                         
    {   if (Throws <= 20)
        {
        printf("\n%d\n", *random_numberArray);                               
        random_numberArray = random_numberArray +1;                          
        usleep(500000);                                                      
        else                                                                 
        {
        printf("\n%d\n", *random_numberArray);
        random_numberArray = random_numberArray +1;

        }
    }
}

// Function to calculate and print the occurrence and percentage of each face value in the throw results.
void occurences_And_Percentage(int Faces,int Throws, char percentage,int *random_numberArray, int occurrence)
{
     for (int i = 1; i < (Faces + 1); i++)                                                      
        occurrence = 0;                                                                         
        for (int j = 1; j < (Throws + 1); j++)                                                  
        {
            if (*random_numberArray == i)                                                      
            {
                occurrence = occurrence + 1;                                                    
            }
            random_numberArray = random_numberArray + 1 ;                                       
        }
        random_numberArray = random_numberArray - Throws;                                       
        printf(" \n occurrences of %d : %.2lf %c \n  ", i, ((occurrence / ((double)Throws)) * 100), percentage); 
        usleep(500000);                                                                         
    }
}


int main()
{

    int Faces, Throws,occurrence;
    char percentage = '%';


    char *welcome = "welcome.txt";
    char *start_rolling = "START.txt";       
    char *Num_occurences = "OCCURRENCES.txt";


    Drawing(welcome);                   
    sleep(1);                           
                                        

    Faces = faces_validation();          
    sleep(1);


    Throws = throws_validation();       
    sleep(1);

    Drawing(start_rolling);             
    sleep(3);                          


    int random_numberArray[Throws];     
    Generate_Randomnumber(1,Faces, Throws, random_numberArray); 
    Output_Randomvalues(random_numberArray, Throws);            
    sleep(1) ;


    Drawing(Num_occurences);                                    
    sleep(1);
    occurences_And_Percentage(Faces, Throws,percentage,random_numberArray,occurrence);  
    printf("\n--------------------------------------------------------------------------------------------END OF PROGRAM----------------------------------------------------------------------------------------------------------");

    return 0;
}
