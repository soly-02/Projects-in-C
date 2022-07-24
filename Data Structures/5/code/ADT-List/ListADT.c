// Filename ListADT.c
/*                     (* YLOPOIHSH LISTAS ME PINAKA *)
              (*TA STOIXEIA THS LISTAS EINAI TYPOY integer*)
*/

#include <stdio.h>
#include <stdlib.h>
#include "ListADT.h"


void CreateList(ListType *List)
/* ����������: ���������� ��� ���� �����.
   ����������: ��� ���� �����
*/
{
    List -> Size = 0;
}

boolean EmptyList(ListType List)
/* �������:    ��� ����� List.
   ����������: ������� �� � ����� List ����� ����.
   ����������: True �� � ����� List ����� �����, false �����������
*/
{
    return (List.Size == 0);
}

boolean FullList(ListType List)
/* �������:    ��� ����� List.
   ����������: ������� �� � ����� List ����� ������.
   ����������: True �� � ����� List ����� ������, false �����������
*/
{
    return (List.Size == (ListLimit));
}

void Insert(ListType *List, ListElementType Item, int Pos)
/* �������:    ��� ����� List, �� �������� Item ��� �� ���� Pos ���� ��� �����.
   ����������: �������, ��� ����� List, �� ��� ����� ������, ���� �� ���� Pos
                �� �������� Item.
   ����������: ��� ������������� ����� List.
   ������:     M����� ������� ������, �� � ����� List ����� ������
*/
{
    int i;
    if (FullList(*List))
        printf("Full list...\n");
    else
    {
        for (i=List->Size-1; i>=Pos+1;i--)
            List->Element[i+1] = List ->Element[i];
        List->Element[Pos+1]=Item;
        List->Size++;
    }
}

void Delete(ListType *List, int Pos)
/* �������:    ��� ����� List.
   ����������: ��������� ��� �� ����� List, �� ��� ����� ����,
                �� �������� ��� ��������� ��� ���� Pos.
   ����������: ��� ������������� ����� List.
   ������:     ������ ����� ������, �� � ����� List ����� ����

*/
{
    int i;
    if (EmptyList(*List))
        printf("Empty list...\n");
    else
    {
        for (i=Pos; i<List->Size-1; i++)
            List->Element[i] = List ->Element[i+1];
        List->Size--;
    }
}

void TraverseList(ListType List)
/* �������:    ��� ����� List.
   ����������: ����� �������� ��� ����� List, �� ��� ����� ����.
   ������:     ��������� ��� ��� �����������
*/
{
    int i;
    if (EmptyList(List))
      	printf("Empty List\n");
    else
    {
        printf("\nPlithos stoixeiwn sth lista %d\n",List.Size);
        for (i=0;i<List.Size;i++)
            printf("%d ",List.Element[i]);
        printf("\n");
    }
}

