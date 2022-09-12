#include <stdio.h>
#include <string.h>

int count(char *word, char c) {
    
    char match = c;
    if(match >= 'A' && match <= 'Z')
    {
        match -= 'A';
        match += 'a';
    }

    int repeats = 0;

    for(int i = 0; i < strlen(word); i++) {
        
        char current = word[i];
        if(current >= 'A' && current <= 'Z')
        {
            current -= 'A';
            current += 'a';
        }

        if(current == match) {
            repeats++;
        }
    }

    printf("%c:%d", c, repeats);

}

void countAll(char *word) {

    for(int i = 0; i < strlen(word) - 1; i++) {
        count(word, word[i]);
        if(i + 1 != strlen(word) - 1) printf(", ");
    }

}

int main(void) {

    char input[260];
    scanf("%s", input);

    char ch = input[strlen(input)];

    scanf("%c", &ch);
    if(ch == ' ')   scanf("%c", &ch);
    
    if(ch == '\n') {
        countAll(input);
    }
    else {
        count(input, ch);
    }
    puts("");

}