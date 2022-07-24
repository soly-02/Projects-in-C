//filename : HeapADT.h

#define  MaxElements 10          //�� ������� ������ ��� ��������� ��� �����

typedef int  HeapElementType;    //� ����� ��������� ��� ��������� ��� �����
typedef  struct { 
     HeapElementType key;
    // int Data;                // ����������� ����� ��� �� ����������� �������� ���� ������
} HeapNode;


typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMaxHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMaxHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMaxHeap(HeapType *Heap, HeapNode *Item);
