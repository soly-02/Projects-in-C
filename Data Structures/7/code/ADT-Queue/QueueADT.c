// QueuePADT.c
                        /*��������� ����� �������� �� �������*/
                        
#include <stdio.h>
#include <stdlib.h>
#include "QueueADT.h"

void CreateQ(QueueType *Queue)
/* ����������: ���������� ��� ���� ����������� ����. 
   ����������: ��� ���� ����������� ���� 
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����������� ����. 
   ����������: ������� �� � ����������� ���� ����� ����. 
   ����������: True �� � ���� ����� ����, false  ����������� 
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ����������� ���� Queue ��� ���  �������� Item.
   ����������: ��������� �� �������� Item ��� ����� ��� ������������ ����� Queue.
   ����������: ��� ������������� ����
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item; 
    TempPtr->Next = NULL;
    if (Queue->Front==NULL) 
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����������� ����. 
   ����������: ������� �� �������� Item ��� ���  ������ ��� ������������ �����, 
                �� ��� �����  ����. 
   ����������: �� �������� Item ��� ��� ������������� ����������� ����. 
   ������:     ������ ����� �����, �� � ���� �����  ���� 
*/
{
    QueuePointer TempPtr;
    
    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;     
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }   
}



