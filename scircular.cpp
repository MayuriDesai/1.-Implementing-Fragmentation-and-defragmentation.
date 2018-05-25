#include<stdio.h>
#include<malloc.h>
#include<conio.h>

#define MAX 5

struct node
{
	int iData;
	struct node * pNext;
};


void Display(struct node *  pHead);
//void DeleteFirst(struct node * * pHead,struct node ** pLast);
//void DeleteLast(struct node * * pHead, struct node ** pEnd );
void FreeNode(struct node * * pHead,struct node ** pEnd);
int Insert(struct node * * pHead,struct node ** pEnd,int iNo );
void Defragementation(struct node * * pHead,struct node ** pEnd);
void InsertFirst(struct node * * pHead,struct node * * pLast,int iNo );
void DeleteAtPosition(struct node * * pHead,struct node ** pEnd,int iPos );

static int SC,tp,pq;
static int iPos;
static int iRet;

int main()
{
	int iNo,iData1,iC=0,ipos,p=0;
	struct node *pFirst=NULL;
	struct node *pLast=NULL;
	struct node *pTemp2=NULL;

	while(iC<MAX)
	{
	   InsertFirst(&pFirst,&pLast,0);
	   iC++;
	}

	Display(pFirst);

	while(1)
	{
	  printf("1. Insert First \n");
	  printf("2. Delete data \n");
	  printf("3. Defragementation \n");
	  printf("4. Exit \n");
	 
	  scanf("%d",&iNo);
	
	  switch(iNo)
	  {
	    case 1:
			p=0;
			pTemp2=pFirst;
			while(pTemp2->pNext != pFirst)	
	       {
	          if(pTemp2->iData == 0)
				  p++;
	          pTemp2=pTemp2->pNext;
	        }

	         if(pTemp2->iData == 0)
				  p++;

			 if(p>0)
			 {
			    printf("enter  node data");
			    scanf("%d",&iData1);

			if(iData1 == 0 )
			{
				printf("Invalid data \n \n");
				break;
			}

			iRet=Insert(&pFirst,&pLast,iData1);
			Display(pFirst);
			}
			 else
				 printf("linked list is full \n");

			break;
	    
     
		case 2:
			p=0;
			pTemp2=pFirst;
			while(pTemp2->pNext != pFirst)	
	       {
	          if(pTemp2->iData == 0)
				  p++;
	          pTemp2=pTemp2->pNext;
	        }

	         if(pTemp2->iData == 0)
				  p++;

			 if(p<MAX)
			 {
			   printf("enter position of data");
			   scanf("%d",&ipos);

		       DeleteAtPosition(&pFirst,&pLast,ipos);

			   Display(pFirst);
			 }
			 else
				 printf("data not present u cannot delete data.. \n");
			break;


		case 3:
			//printf("b1111111");
			  Defragementation(&pFirst,&pLast);
			 // printf("bbbbb");
			  Display(pFirst);
			  break;


	   case 4:
		     iC=0;
		      while(iC<MAX)
	          {
	            FreeNode(&pFirst,&pLast);
	            iC++;
	          }

			   return 0;
	 
	  }



	}


	getch();
	return 0;
}


void DeleteAtPosition(struct node ** pHead,struct node ** pEnd,int iPos)
{
	int count,ic=0,iRet;
	struct node *pTemp=NULL;
	//struct node *pTemp2=NULL;
	

	if((*pHead)== NULL)
	{
	   printf("\n Linked list is empty \n");
	   return ;

	}
	
	if(iPos<=0 || iPos>MAX )
	{
         printf("Invalide Position \n");	
		 return ;
	}

	if(iPos==1)
	{
		pTemp=*pHead;

		if(pTemp->iData >0)
			pTemp->iData=0;
		else
			printf("\n Data not present");

	   //DeleteFirst(pHead,pEnd);
	   return ;
	}

	if(iPos==(MAX))
	{
		pTemp=(*pHead);
		while(pTemp != (*pEnd))
		{
		  pTemp=pTemp->pNext;
		}

		if(pTemp->iData >0)
			pTemp->iData=0;
		else 
			printf("\n data not present.");

	 
	   return ;
	}

	ic=1;
	pTemp=(*pHead);
	
	while(ic<(iPos))
	{
	  //pTemp2=pTemp;
	  ic++;
	  pTemp=pTemp->pNext;
	}

	
	if(pTemp->iData >0)
		pTemp->iData=0;
	else 
		printf("\n data not present.");

}


void InsertFirst(struct node * * pHead,struct node ** pEnd,int iNo )
{
	struct node * pTemp=NULL;
	struct node * pNewNode =NULL;
	pNewNode = (struct node *)malloc(sizeof(struct node));
	

	if(NULL == pNewNode )
	{
	  printf("malloc fails");
	  return ;
	}

	pNewNode->iData=iNo;

	if((*pHead)==NULL)
	{
	  *pHead=pNewNode;
	   pNewNode->pNext=(*pHead);
	   (*pEnd)= pNewNode;
	   return;
	}

	  pTemp=(*pHead);

	 pNewNode->pNext=pTemp;

	 while(pTemp->pNext != (*pHead))
	 {
	   pTemp=pTemp->pNext;
	 }
	
	 pTemp->pNext=pNewNode;
	 (*pHead)=pNewNode;
	
}


int Insert(struct node * * pHead,struct node * * pEnd, int iNo)
{
	int ic,icnt;
	struct node * pTemp= *pHead;

	if(SC==0)
	{
		SC++;
		printf("mmm");
	  while(pTemp->pNext != *pHead)	
	  {
		  iPos++;
		if(pTemp->iData == 0)
		{
			iPos++;
		  pTemp->iData=iNo;
		  return iPos;
		}

	   pTemp=pTemp->pNext;
	  }

	 if(pTemp->iData == 0)
		{
			iPos++;
		  pTemp->iData=iNo;
	    }
		  return iPos;
	}
	else
	{
		SC++;
		pTemp=(*pHead);

		 printf("sss");
		icnt=0;
	 do
	  {
		
	  if( pTemp->iData == 0)
		{
			icnt++;
	    }
	  pTemp=pTemp->pNext;

	 }while(pTemp != (*pEnd)->pNext);


	  if((icnt == MAX )|| (pq>0))
	  {
		  iPos=1;
		  pq=0;
	  }

	   ic=1;
   	  pTemp=(*pHead);

   /*if(iPos == 5)
   {
     iPos=1;
   }*/

	while(ic<(iPos))
	{
	  ic++;
	  pTemp=pTemp->pNext;
	}
   
	if(pTemp->iData == 0)
	{
		  pTemp->iData=iNo;
	      iPos++;
	      return iPos;
	 }
	
	/*if(pTemp->pNext == (*pHead))
	{
	  pTemp=(*pHead);
	}*/

	  printf("sss333");
	    pTemp=pTemp->pNext;
	  while(pTemp->pNext != *pHead)	
	  {
		  iPos++;
		if(pTemp->iData == 0)
		{
		   iPos++;
		  pTemp->iData=iNo;
		  return iPos;
		}

	   pTemp=pTemp->pNext;
	  }

	  printf("sss222");
	  if(pTemp->iData == 0)
		{
			iPos++;
		  pTemp->iData=iNo;
		 return iPos;
	    }
	 
	}

}


void Display(struct node * pHead)
{
   struct node * pTemp=pHead;

   if(pTemp == NULL)
   {
     printf("memory deallocated");
	 return ;
   }
	while(pTemp->pNext != pHead)	
	{
	  printf("  | %d |-> ", pTemp->iData);
	  pTemp=pTemp->pNext;
	}

	 printf("  | %d |-> ", pTemp->iData);

	printf("\n \n");


}


void FreeNode(struct node * * pHead,struct node ** pEnd)
{
	struct node * pTemp= *pHead;
	
	if((*pHead)==NULL)
	{
	  printf(" \n Linked List is Empty..! \n");
	   return ;
	}

	if(pTemp->pNext== (*pHead) )
	{
		pTemp->pNext=NULL;
		free(pTemp);
		//pTemp->iData=0;
		(*pHead)=NULL;
		(*pEnd)=NULL;
		return ;
	}

	(*pHead)=pTemp->pNext;
	pTemp->pNext=NULL;
	free(pTemp);
	//pTemp->iData=0;
}


void Defragementation(struct node * * pHead,struct node ** pEnd)
{
	struct node * pTemp= *pHead;
	struct node * pTemp2=NULL;
	struct node * pTemp3=NULL;
	

	pTemp2=pTemp;
	pTemp=pTemp->pNext;
	pq++;
	do
	{
		
		//printf("aaa");
	  if( pTemp->iData == 0)
		{
			pTemp3=pTemp;
			
			if(pTemp3 == (*pEnd))
			{
				//pTemp2->pNext=pTemp3;
				(*pHead)=pTemp3;
			   (*pEnd)=pTemp2;
			   return;
			}


			pTemp2->pNext=pTemp3->pNext;
			pTemp3->pNext=(*pHead);
	        (*pHead)=pTemp3;
			(*pEnd)->pNext=pTemp3;

			pTemp=pTemp2;
	    }
	  pTemp2=pTemp;
	  pTemp=pTemp->pNext;

	 }while(pTemp != (*pEnd)->pNext);

	
}