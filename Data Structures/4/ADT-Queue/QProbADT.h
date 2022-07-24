/*******************************************************************************
* Filename: QProbADT.h
******************************************************************************/

/* Queue */
#define QueueLimit 20  //�� ���� �������� ��� �����

typedef struct {
    int Addend1, Addend2;    
} QueueElementType;   /* � ����� ��������� ��� ��������� ��� �����
                         ����� struct (����) */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
