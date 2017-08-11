#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	void task1(void);
	void task2(void);
	void task3(void);
	void task4(void);
	void task5(void);

	task1();
	task2();
	task3();
	task4();
	task5();

	return EXIT_SUCCESS;
}

void task1(void)
{
	int a=1;

	printf("\nTask 1\n");	

	for(int i=1; i<=10; i++)
	{
		for(int j=1; j<=a; j++)
		{
			printf("*");
		}
	
		a++;
		printf("\n");
	}
}

void task2(void)
{
	int a=1;
	int b=9;

	printf("\nTask 2\n");	

	for(int i=1; i<=10; i++)
	{
		for(int j=1; j<=b; j++)
		{
			printf(" ");
		}
		
		for(int j=1; j<=a; j++)
		{
			printf("*");
		}
		
		a++;
		b--;
		printf("\n");
	}
}

void task3(void)
{
	int a=1;
	int b=9;

	printf("\nTask 3\n");
	
	for(int i=1; i<=10; i++)
	{
		for(int j=1; j<=b; j++)
		{
			printf(" ");
		}

		for(int j=1; j<=a; j++)
		{
			printf("*");
		}
		

		a+=2;
		b--;
		printf("\n");
	}
}

void task4(void)
{
	int a=1;
	int b=9;

	printf("\nTask 4\n");
	
	for(int i=1; i<=19; i++)
	{
		if(i<=10)
		{
			for(int j=1; j<=b; j++)
			{
				printf(" ");
			}

			for(int j=1; j<=a; j++)
			{
				printf("*");
			}
			
			
			a+=2;
			b--;
			printf("\n");
		}
		else
		{
			for(int j=-1; j<=b; j++)
			{
				printf(" ");
			}
			for(int j=1; j<=a-4; j++)
			{
				printf("*");
			}
			
			a-=2;
			b++;
			printf("\n");
		}
	}
}

void task5(void)
{
	int a=11;

	printf("\nTask 5\n");	

	for(int i=1; i<=11; i++)
	{
		if(a==11)
		{
			for(int j=1; j<=a; j++)
			{
				printf("*");
				printf(" ");
			}
			
			a--;
		}
		else
		{
			for(int j=1; j<=a; j++)
			{
				printf(" ");
				printf("*");
			}
			
			a++;
		}
		printf("\n");
	}
}


