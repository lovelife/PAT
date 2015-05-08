//http://www.patest.cn/contests/mooc-ds2015spring/01-%E5%A4%8D%E6%9D%82%E5%BA%A61

/*
01-���Ӷ�1. ������к�����(20)

����K��������ɵ�����{ N1, N2, ..., NK }�����������С�������Ϊ{ Ni, Ni+1, ..., Nj }������ 1 <= i <= j <= K��
��������к͡��򱻶���Ϊ������������Ԫ�صĺ�������ߡ�
�����������{ -2, 11, -4, 13, -5, -2 }������������{ 11, -4, 13 }�����ĺ�20��
��Ҫ�����д���򣬼�������������е�������к͡�

�����ʽ��

�����1�и��������� K (<= 100000)����2�и���K������������Կո�ָ���

�����ʽ��

��һ�������������к͡��������������������Ϊ�����������0��
����������

6
-2 11 -4 13 -5 -2

���������

20
*/

//�㷨
//1��������K�������������г�Ϊ1�����г�Ϊ2�����г�Ϊ3��......
//2���������

#include <stdio.h>

int table[100000+1];

int calSum(int i, int len)
{
	int sum = table[i];
	
	while(--len)
		sum += table[++i];
		
	return sum;	
}

int main()
{
	int k , i , j, n, sum, maxsum;
	
	while(scanf("%d",&k) != EOF)
	{
		sum = 0;
		maxsum = 0;
		
		for(i = 0; i < k; i++)
		{
			scanf("%d",&table[i]);
		}
		for(i = 1; i <= k; i++)
		{
			sum = table[i-1];
			for(j = i+1; j <= k; j++)
			{
				sum += table[j - 1];
				if(maxsum < sum)
					maxsum = sum;
			}
		}
/*		//���ǲ�����Ҫ������sumTable[100000+1][100000+1] ��ô��ռ� ȥ�����м�� 
		//һ�������͹��� 
		for(i = 1; i <= k ; i++)
		{
			sumTable[1][i] = sumTable[1][i - 1] + table[i-1];	
		}
		for(i = 1; i <= k; i++)
		{
			for(j = i; j <= k; j++)
			{
				sumTable[i][j] = sumTable[1][j] - sumTable[1][i] + table[i-1];
				if(maxsum < sumTable[i][j])
					maxsum = sumTable[i][j];
			}
		}	
*/
			
/*      // �������ᳬʱ		
		maxsum = table[0] > 0 ? table[0] : 0;	
		for(n = 1; n <= k; n++) // ������г��� 
		{
			for(i = 0; i <= k - n; i++)
			{
				sum = calSum(i, n);
				if ( sum > maxsum)
					maxsum = sum;
			}
		}
*/		
		
		printf("%d\n",maxsum);	
	}
	return 0;
}




 

