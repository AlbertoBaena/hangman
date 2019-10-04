#include <stdio.h>
#include <string.h>

void printHangman(int lives);
void printTitle(char a[]);
char toCaps(char c);
int isLetter(char c);
int isIn(char str[], char c);
void printLetters(char str[]);

int main(){
    char keepPlaying = 'Y', letter;
    int lives, win;

    char correctWord[200];
    char currentWord[200];
    char incorrectLetters[27];
    int it;

    printTitle("HANGMAN BY ZABE");

    while(keepPlaying == 'Y' || keepPlaying == 'y'){
        lives = 6;
        win = 0;
        it = 0;
        strcpy(correctWord,"CORNER");
        strcpy(currentWord,correctWord);
        for(int i = 0; currentWord[i] != '\0'; i++)
            currentWord[i] = '_';
        incorrectLetters[0] = '\0';

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
        printf("\n");
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
    }
    printf("\n");
    printTitle("Thanks for playing! OwO");
    
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