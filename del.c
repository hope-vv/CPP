#include <stdlib.h>


int fstrlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
char * mergeAlternately(char * word1, char * word2){
    int i = 0;
    int len =  fstrlen(word1) + fstrlen(word2) + 1;
    int len1 = fstrlen(word1);
    char *str = malloc(sizeof(char) * len);
    int j = 0;
    int k = 0;
    while (i < len)
    {
        str[i] = word1[k];
        i++;
        str[i] = word2[j];
        i++;
        k++;
        j++;
    }
    str[i] = '\0';
    return (str);
}
#include <stdio.h>
int main ()
{
    char *word1 = "ded";
    char *word2 = "wf";
    char *str = mergeAlternately(word1, word2);
    printf("%s\n", str);
}