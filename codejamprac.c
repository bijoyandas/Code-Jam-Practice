#include<stdio.h>
#include<stdlib.h>

int numOfdigit=0;
long n;
void addDigits(long num,int digits[])
{
	int i = numOfdigit;
	long m = num;
	int flag = 0;
	while(m>0)
	{
		int d = m % 10;
		for(i=0;i<numOfdigit;i++)
		{
			if(digits[i] == d)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			digits[numOfdigit++] = d;
		}
		else 
			flag = 0;
		m = m/10;
	}
}

int check(int digits[])
{
	int dig = 0;
	int i;
	int flag = 0;
	while(dig<=9)
	{
		flag = 0;
		for(i=0;i<numOfdigit;i++)
		{
			if (dig == digits[i])
			{
				flag = 1;
				dig++;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	return flag;
}

void main()
{
	int *digits;
	int k = 2;
	int m;
	int red = 0;
	int num;
	int cases = 0;
	char c[1000];
	FILE *fp;
	fp = fopen("practice.in","r");
	while(!feof(fp))
	{
		fscanf(fp,"%[^\n]\n",c);
		if(red == 0)
			n = atoi(c);
		else
			num = atoi(c);
		if(red)
		{
			digits = (int *)malloc(10*sizeof(int));
			numOfdigit = 0;
			k = 2;
			m = num;
			if (num == 0)
			{
				printf("Case #%d: INSOMNIA\n",++cases);
			}
			else 
			{
				addDigits(m,digits);
				while(1)
				{
					int flag = check(digits);
					if (flag == 1)
					{
						printf("Case #%d: %ld\n",++cases,m);
						break;
					}
					else 
					{
						m = num * k;
						k++;
						addDigits(m,digits);
					}
				}
			}
		}
		free(digits);
		red++;
	}
}