// FILENAME StackADT.c                   
                    /* ��������� ������� �� ������ *
              *�� �������� ��� ������� ����� ����� int*/
              
#include <stdio.h>
#include "StackADT.h"

void CreateStack(StackType *Stack) 
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack) 
/* �������: ��� ������ Stack. 
   ����������: ������� �� � ������ Stack ����� ����. 
   ����������: True �� � Stack ����� ����, False ����������� 
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack) 
/* �������: ��� ������ Stack. 
   ����������: ������� �� � ������ Stack ����� ������. 
   ����������: True �� � Stack ����� ������, False ����������� 
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item) 
/* �������: ��� ������ Stack ��� ��� �������� Item. 
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������. 
   ����������: ��� ������������� Stack. 
   ������: ������ ������� �������, �� � ������ Stack ����� ������ 
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item) 
/* �������: ��� ������ Stack. 
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����. 
   ����������: �� �������� Item ��� ��� ������������� Stack. 
   ������:  ������ ����� ������� �� � Stack ����� ���� 
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


