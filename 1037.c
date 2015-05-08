#include<stdio.h>

typedef struct _rank
{
    int school;
    int score;
}Rank;

Rank r[100000];

int main()
{
    int n , i, sc[100000] = {0};
    int maxscore = 0, maxschool = 0;
    
    scanf("%d",&n);
    
    for( i = 0; i < n; i++)
    {
        scanf("%d %d", &(r[i].school), &(r[i].score) );
        sc[ r[i].school ] += r[i].score;
        
        if( maxscore < sc[r[i].school])
        {
            maxscore = sc[r[i].school];
            maxschool = r[i].school;        
        }
    }
    printf("%d %d",maxschool, maxscore);
    
    return 0;
}