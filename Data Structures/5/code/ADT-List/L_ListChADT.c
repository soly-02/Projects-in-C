// Filename L_ListChADT.c
/*               ��������� �������̸��� ˺���� �� ������
         TA �������� ��� ������������ ������ ����� ����� char
*/

#include <stdio.h>
#include "L_ListChADT.h"

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* �������:   ��� ������ Node ��� ��� ������ FreePtr ��� ������� ����
                ����� ��������� �����.
  ����������: ����������� ��� ������ Node �� ����������� ����� ���������� ������
                ���� ���������� �������� ��� ������,
                ��� ����������� ��� ������ FreePtr .
  ����������: ��� ������������� ������ Node ��� ���
                ������ FreePtr ��� ������ ���������� ������
*/
{
   int i;

    for (i=0; i<NumberOfNodes;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;    /* ��� �������� ������, ��������� ��� �� ��������� ���� �������� � ���� ��� ��������� Data */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;      /* ��� �������� ������, ��������� ��� �� ��������� ���� �������� � ���� ��� ��������� Data */
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����.
   ����������: ���� (��������) ������ ��� ������� �� ���� �����
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* �������:    ���� ������ List ��� ������� �� ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ����.
   ����������: True �� � ����������� ����� ����� ���� ��� false �����������
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer List)
/* �������:    ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ������.
   ����������: True �� � ���������������� ����� ������, false �����������
*/
{
  return (List==NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* �������:   ��� ������ Node ��� ��� ������ FreePtr.
  ����������: ������ ���� "��������" ����� ��� ��� ������� � ������� P.
  ����������: ��� ������ P ��� ��� �������������  ������ FreePtr
                ��� ����������� ��� ����� ��������� �����

*/
{
  *P = *FreePtr;
   if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* �������:    ��� ������ Node, ��� ���������� �� �������� ��� ���������� ������,
                ���� ������ TempPtr ��� ��� ������ FreePtr.
   ����������: ���������� ��� �������� ��� ����� ���� ����� ������� � TempPtr.
   ����������: ��� ������������� ������ Node ��� ��� ������ FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data = -1;    /* ��� �������� ������, ��������� ��� �� ��������� ����
                        �������� �� ������������ ������ */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* �������:    ��� ����������� �����, ��� ������ Node, ��� ������ PredPtr ���
                ��� �������� Item.
  ����������: ������� ��� ����������� �����, �� ��� ����� ������, �� ��������
                Item ���� ��� ��� ����� ���� ����� ������� � ������� PredPtr.
  ����������: ��� ������������� ����������� �����, ��� ������������� ������ Node
                ��� ��� ������ FreePtr.
  ������:     ������ ������� ������, �� � ����������� ����� ����� ������
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* �������:   ��� ����������� ����� ��� ��� ������ PredPtr ��� �������
                ���� ����������� ����� ��� ����� ��� �� ���������.
  ����������: ��������� ��� �� ����������� �����, �� ��� ����� ����,
                ��� ����������� ����� ��� ����� ���� ����� ������� � PredPtr.
  ����������: ��� ������������� ����� ��� �� ������ FreePtr.
  ������:     ������ ����� ������, �� � ����������� ����� ����� ����
*/
{
  ListPointer TempPtr ;

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* �������:    ��� ����������� �����.
   ����������: ����� �������� ��� ������������ ������, �� ��� ����� ����.
   ������:     ��������� ��� ��� �����������
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("%c",Node[CurrPtr].Data);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
