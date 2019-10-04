#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char toCaps(char c);
int isLetter(char c);
int isIn(char a[], char c);
void printLetters(char str[]);
int randomize(unsigned int n);
int countlines(char *filename);

int main(){
    int line = 7;
    int i = 2;
    char correctWord[10];
    FILE *words;

    words = fopen("words.txt","r");
    if(words == NULL){
        printf("Error: words.txt not found");
        return 1;
    }

    for(int i = 2; fgets(correctWord, 10, words) && i <= line; i++);
        fgets(correctWord, 10, words);
    printf(correctWord);

    fclose(words);

    printf("%d",countlines("words.txt"));   

    return 0;
    
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
int isIn(char a[], char c){
    for(int i = 0; a[i] != '\0'; i++)
        if(a[i] == c)
            return 1;
    return 0;
} 
void printLetters(char str[]){
    printf("%c",40);
    if(str[0] != '\0'){
    for(int i = 0; str[i] != '\0'; i++)
        printf("%c, ",str[i]);
    printf("%c%c",8,8);
    }
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

    fclose(file);

    return linesCount;
}