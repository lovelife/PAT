#include<stdio.h>
#include<math.h>

//������1Сʱ������� 
 
int main()
{
	int N,n,s,i,j;
	char ch[2];
	
	{
		scanf("%d %c", &N,ch);
		n = sqrt( (N + 1) / 2);
		
		s = N - 2*n*n + 1;
		
		for(i = 1; i < n; i++)
		{
			// i black
			for(j = 1; j < i; j++)
				printf(" ");
			// (2*n - 1) - 2(i - 1) ch
			for(j = 1; j <= (2*n -2*i + 1); j++)
				printf("%c",ch[0]);
			// i black
			//for(j = 1; j < i; j++)   //����ո��ˣ�����̬ 
			//	printf(" ");	
			printf("\n");
		}
		for(i = 1; i <= n; i++)
		{
			// n - i black
			for(j = 1; j <= n - i; j++)
				printf(" ");
				
			for(j = 1; j <= 2*i - 1; j++)
				printf("%c",ch[0]);
				
			//for(j = 1; j <= n - i; j++)
			//	printf(" ");
			printf("\n");		
		}
		printf("%d",s);
	}
	return 0;
}
