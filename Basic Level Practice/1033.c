#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
    char lo[26] = {0}, di[10] = {0}, ch[4] = {0}, space = 0;
    char badkey[100001] = {0}, instr[100001] = {0};
    
    //scanf("%s %s",badkey,instr);
    gets(badkey);
    gets(instr);
    
    int i , isnull = 1;
    for(i = 0; i < strlen(badkey); i++)
    {
        if(isdigit(badkey[i]))
            di[badkey[i] - '0'] = 1;
        else if(isupper(badkey[i]))
        {
            lo[badkey[i] - 'A'] = 1;
        }
        else if(badkey[i] == '_')
        {
            space = 1;
        }
        else {// + , - .
            ch[ badkey[i] - '+'] = 1;
        }
                
    }
    for (i = 0; i < strlen(instr); i++) 
    {
        if(isdigit(instr[i]) && !di[instr[i]-'0'])
        {
            printf("%c",instr[i]);
            isnull = 0;
        }    
        else if (islower(instr[i]) && !lo[instr[i]-'a']) {
            printf("%c",instr[i]);
            isnull = 0;
        }  
        else if (isupper(instr[i]) && !ch[0] && !lo[instr[i]-'A']) {
            printf("%c",instr[i]);
            isnull = 0;
        }
        else if ( (instr[i] == '_') && !space) {
            printf("_");
            isnull = 0;
        }  
        else if( instr[i] >= '+' && instr[i] <= '.' && !ch[instr[i] - '+'])
        {
            printf("%c",instr[i]);
            isnull = 0;
        }
    }
    if(isnull) printf("\n");
    return 0;    
}



