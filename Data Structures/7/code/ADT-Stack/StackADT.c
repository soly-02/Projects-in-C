// Filename: StackADT.c

/* ��������� ������� �������� �� �������*/

#include <stdio.h>
#include <stdlib.h>
#include "StackADT.h"

void CreateStack(StackPointer *Stack)
/* ����������: ���������� ��� ���� ����������� ������. 
   ����������: ��� ���� ����������� ������, Stack  
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* �������:     ��� ����������� ������, Stack.
   ����������:  ������� �� � Stack ����� ����.
   ����������:  TRUE �� � ������ ����� ����, FALSE �����������
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� 
                ������ Stack ��� ��� �������� Item. 
   ����������: ������� ���� ������ ��� ������������ �������, �� �������� Item. 
   ����������: ��� ������������� ����������� ������ 
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item; 
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� ������ Stack. 
   ����������: ������� ��� ��� ������ ��� ������������ �������, 
                �� � ������ ��� ����� ����, �� �������� Item. 
   ����������: ��� ������������� ����������� ������ ��� �� �������� Item. 
   ������:     ������ ����� �������, �� � ����������� ������ ����� ���� 
*/
{
    StackPointer TempPtr;
    
    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;     
        free(TempPtr);
    }
}



