#include <stdlib.h>
#include <conio.h>
#include <random>
#include <time.h>

struct LIST
{
	int a;
	LIST *next;
};

/**
	\file list_w.cpp list file
*/


/**
 CreateList
 */

/**
	\param Cur current item
	
*/

void CreateList(LIST *Cur)
{
	Cur->a=rand()%25;
	Cur->next=NULL;
}		

/**
 CreateList
 */

/**
	\param Cur current item
	\param n number
	
*/

void AddList(LIST *Cur,int n)
{
	LIST *d;
	for(int i=0;i<n;++i)
	{
		Cur=Cur->next;
		if(!Cur)
		{
			printf("error\n");
			return;
		}
	}
	d=Cur->next;
	int a;
	printf("\nCount of elem\n");
	scanf("%d",&a);
	Cur->next=new LIST;
	Cur->next->a=a;
	Cur->next->next=d;

}

/**
 DeleteList
 */

/**
	\param Cur current item
	\param n number
	
*/

void DeleteList(LIST *Cur,int n)
{
	LIST *d;
	for(int i=0;i<n;++i)
	{
		Cur=Cur->next;
		if(!Cur)
		{
			printf("error\n");
			return;
		}
	}
	d=Cur->next;
	Cur->next=Cur->next->next;
	delete d;
}

/**
 GetCount
 */

/**
	\param Cur current item
	\param n number
	
*/

void GetCount(LIST *Cur,int n)
{
	for(int i=0;i<n;++i)
	{
		Cur=Cur->next;
		if(!Cur)
		{
			printf("error\n");
			return;
		}
	}
	printf("%d",Cur->next->a);
}

/**
 GetCount
 */

/**
	\param Cur current item
		
*/

void PrintList(LIST *Cur)
{
	Cur=Cur->next;
	while(Cur)
	{
		printf("%d ",Cur->a);
		Cur=Cur->next;
	}
}

void main()
{
	LIST *Cur,*First=new LIST;
	First->next=NULL;
	srand(time(NULL));
	for(int i=0;i<10;++i)
	{
		if(!First->next)
		{
			Cur=new LIST;
			First->next=Cur;
		}
		else
		{
			Cur->next=new LIST;
			Cur=Cur->next;
		}
		CreateList(Cur);
	}
	Cur=First;
	PrintList(Cur);
	int b;
	int n;
	while(1)
	{
		printf("\n\n1-add\n2-delete\n3-count\n");
		scanf("%d",&b);
		switch(b)
		{
		case 1:
			printf("\nNumber of elem\n");
			scanf("%d",&n);
			Cur=First;
			AddList(Cur,n);
			Cur=First;
			PrintList(Cur);
			break;
		case 2:
			printf("\nNumber of elem\n");
			scanf("%d",&n);
			Cur=First;
			DeleteList(Cur,n);
			Cur=First;
			PrintList(Cur);
			break;
		case 3:
			printf("\nNumber of elem\n");
			scanf("%d",&n);
			Cur=First;
			GetCount(Cur,n);
			break;
		}
	}
	
}