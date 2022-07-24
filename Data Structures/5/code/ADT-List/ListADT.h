// Filename ListADT.h
#define ListLimit 50    //���� �������� ��� ������, ���������� ������ ��� �� 50

typedef int ListElementType;   /*����� ��������� ��� �� �������� ��� ������ 
                                    ���������� ���������� � ����� int */
typedef struct {
    int Size;
    ListElementType Element[ListLimit];
} ListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateList(ListType *List);
boolean EmptyList(ListType List);
boolean FullList(ListType List);
void Insert(ListType *List, ListElementType Item, int Pos);
void Delete(ListType *List, int Pos);
void TraverseList(ListType List);
