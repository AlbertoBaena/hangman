#include <stdio.h>
#include <string.h>
#include <time.h>

void printHangman(int lives);
void printTitle(char a[]);
char toCaps(char c);
int isLetter(char c);
int isIn(char str[], char c);
void printLetters(char str[]);
int randomize(unsigned int n);
int countlines(char *filename);

int main(){
    char keepPlaying = 'Y', letter;
    int lives, win;

    char correctWord[200];
    char currentWord[200];
    char incorrectLetters[27];
    int it;//"incorrectLetters" string iterator in the game

    FILE *words, *lineFile;
    int line;

    /*If "line" file doesn't exist, create one*/
    lineFile = fopen("line","r+");
    if(lineFile == NULL){
        int n;
        printf("I need a random number, please: ");
        scanf("%d",n);
        n = n % countlines("words.txt");
        lineFile = fopen("line","w+");
        fprintf(lineFile,"%d",n);
    }
    fclose(lineFile);

    /*Check if "words.txt" exists*/
    words = fopen("words.txt","r+");
        if(words == NULL){
            printf("Error: words.txt not found");
            return 1;
        }
    fclose(words);
    
    
    /*Game loop*/
    while(keepPlaying == 'Y' || keepPlaying == 'y'){
        lives = 6;
        win = 0;
        it = 0;

        /*Generate random number*/
        srand(time(NULL));
        line = rand()%countlines("words.txt");
        
        
        /*Get word from random number of line*/
        words = fopen("words.txt","r+");
        if(words == NULL){
            printf("Error: words.txt not found");
            return 1;
        }
        for(int i = 3; fgets(correctWord, 200, words) && i <= line; i++);
            fgets(correctWord, 200, words);
        fclose(words);
        
        /*Pass correct word to caps*/
        for(int i = 0; i < 200; i++)
            correctWord[i] = toCaps(correctWord[i]);

        /*Prepare current word*/
        strcpy(currentWord,correctWord);
        for(int i = 0; currentWord[i] != '\0'; i++)
            currentWord[i] = '_';
        incorrectLetters[0] = '\0';
        /*Title*/
        printTitle("HANGMAN BY ZABE");
        /*Game*/
        while(lives > 0 && !win){
            do{
                printf("\nEnter a letter: ");
                fflush(stdin);
                scanf("%c",&letter);
            }while(!isLetter(letter));
            
            if(letter >= 97)
                letter = toCaps(letter);
            
            printf("\n");
            if(isIn(correctWord, letter)){
                if(!isIn(currentWord,letter)){
                    for(int i = 0; correctWord[i] != '\0'; i++)
                        if(correctWord[i] == letter)
                            currentWord[i] = letter;
                }
                else{
                    printf("Letter %c is already in your current word.",letter);
                    lives--;
                }
            }
            else{
                printf("Letter %c isn't in the correct word.",letter);
                if(!isIn(incorrectLetters,letter)){
                    incorrectLetters[it] = letter;
                    incorrectLetters[it+1] = '\0';
                    it++;
                }
                else
                    printf("\nAlso, you had tried this letter earlier.");
                lives--;
            }
            printf("\n\nWord: %s\n",currentWord);
            printHangman(lives);
            printf("\nIncorrect letters: ");
            if(incorrectLetters[0] != '\0')
                printLetters(incorrectLetters);
            else
                printf("none.");
            if(strcmp(currentWord,correctWord)==0)
                win = 1;
            if(lives == 0)
                win = 0;
        }
        system("@cls||clear");
        if(win)
            printTitle("You have won :D");
        else{
            printTitle("You have lost :(");
            printf("\n\nThe correct word was %s.\n",correctWord);
        }

        do{
            printf("Do you want to keep playing? [Y/N]: ");
            fflush(stdin);
            scanf("%c",&keepPlaying);
        }while(keepPlaying != 'y' && keepPlaying != 'Y'&& keepPlaying != 'n' && keepPlaying != 'N');
        system("@cls||clear");
    }
    printTitle("Thanks for playing! OwO");
    clock_t start_time = clock(); 
    while (clock() < start_time + 1600);

    return 0;
}

void printHangman(int lives){
    switch (lives)
    {
    case 6:
        printf("%c%c%c%c%c\n",201,205,205,205,187);
        printf("%c\n",186);
        printf("%c\n",186);
        printf("%c\n",186);
        printf("%c\n",186);
        printf("%c\n",202);
        break;

    case 5:
        printf("%c%c%c%c%c\n",201,205,205,205,187);
        printf("%c   O\n",186);
        printf("%c\n",186);
        printf("%c\n",186);
        printf("%c\n",186);
        printf("%c\n",202);
        break;

    case 4:
        printf("%c%c%c%c%c\n",201,205,205,205,187);
        printf("%c   O\n",186);
        printf("%c   %c\n",186,179);
        printf("%c   %c\n",186,179);
        printf("%c\n",186);
        printf("%c\n",202);
        break;

    case 3:
        printf("%c%c%c%c%c\n",201,205,205,205,187);
        printf("%c   O\n",186);
        printf("%c %c%c%c\n",186,196,196,180);
        printf("%c   %c\n",186,179);
        printf("%c\n",186);
        printf("%c\n",202);
        break;

    case 2:
        printf("%c%c%c%c%c\n",201,205,205,205,187);
        printf("%c   O\n",186);
        printf("%c %c%c%c%c%c\n",186,196,196,197,196,196);
        printf("%c   %c\n",186,179);
        printf("%c\n",186);
        printf("%c\n",202);
        break;

    case 1:
        printf("%c%c%c%c%c\n",201,205,205,205,187);
        printf("%c   O\n",186);
        printf("%c %c%c%c%c%c\n",186,196,196,197,196,196);
        printf("%c   %c\n",186,179);
        printf("%c  %c\n",186,47);
        printf("%c\n",202);
        break;

    

    case 0:
        printf("%c%c%c%c%c\n",201,205,205,205,187);
        printf("%c   O\n",186);
        printf("%c %c%c%c%c%c\n",186,196,196,197,196,196);
        printf("%c   %c\n",186,179);
        printf("%c  %c %c\n",186,47,92);
        printf("%c\n",202);
        break;
    
    default: break;
    }
}
void printTitle(char a[]){
    int j = 0;
    printf("%c%c",176,177);
    for(int i = 0; i <= strlen(a)+7; i++)
        printf("%c",178);
    printf("%c%c\n",177,176);
    printf("%c%c%c%c%c ",176,177,178,177,176);
    while(a[j]!='\0'){
        printf("%c",a[j]);
        j++;
    }
    printf(" %c%c%c%c%c\n",176,177,178,177,176);
    printf("%c%c",176,177);
    for(int i = 0; i <= strlen(a)+7; i++)
        printf("%c",178);
    printf("%c%c\n",177,176);

}
char toCaps(char c){
    if(isLetter(c))
        return c - 32;
}
int isLetter(char c){
    if(c < 65 || (c > 90 && c < 97) || c > 122)
        return 0;
    else
        return 1;
}
int isIn(char str[], char c){
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] == c)
            return 1;
    return 0;
}
void printLetters(char str[]){
    printf("%c",40);
    for(int i = 0; str[i] != '\0'; i++)
        printf("%c, ",str[i]);
    printf("%c%c",8,8);
    printf("%c",41);
}
int randomize(unsigned int n){
    return (n^2)%n + 9*n - n/10;
}
int countlines(char *filename){
    FILE *file;
    int linesCount = 0;
    char c;

    file = fopen(filename,"r");
    if(file == NULL){
        printf("Error: %s not found",filename);
        return 1;
    }

    for(; c != EOF ; c = fgetc(file))
        if(c == '\n')
            linesCount++;
    linesCount++;

    fclose(file);

    return linesCount;
}