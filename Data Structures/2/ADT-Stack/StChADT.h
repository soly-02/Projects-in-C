// FILENAME StChADT.h
                    /* ��������� ������� �� ������ */
              /* �� �������� ��� ������� ����� �����char */

#define StackLimit 80  // �� ���� �������� ��� �������, ���������� ��� �� 80

typedef char StackElementType;  // � ����� ��� ���������  ��� �������
                                //���������� ����� char

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

