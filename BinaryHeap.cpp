#include "BinaryHeap.h"
#include <stdlib.h>
#include <stdio.h>
PriorityQueue Initialize(unsigned int capacity)
{
	PriorityQueue pPQueue = (PriorityQueue)malloc(sizeof(struct BinaryHeap));
	pPQueue->heap = (unsigned int *)malloc(sizeof(int)*capacity);
	pPQueue->capacity = capacity;
	pPQueue->size = 0;
	pPQueue->heap[0] = 0;  //��heap[0]Ϊ0���Ա������ʱ��Ԫ�����˹�ͷ

	return pPQueue;
}

bool Insert(PriorityQueue pPQueue, unsigned int x)
{
	//���ڶ���ѵ�heap[0]�Ƿ������õģ�����size���Ϊcapacity-1
	if (pPQueue->size == pPQueue->capacity - 1 || x == 0 || x > INT_MAX)
		return false;

	//CurPos����ǰλ�ã���ʼ��Ϊ�����Ķ����size������β
	unsigned int CurPos = ++pPQueue->size;

	//���ϵ���CurPos��Ӧ�ĸ������x�Ƚϣ�������x���������ˣ��ȼ�����x����
	//��С��x���˳�ѭ������ʱCurPos��xӦ����λ��
	for (;pPQueue->heap[CurPos / 2] > x;CurPos /= 2)
	{
		pPQueue->heap[CurPos] = pPQueue->heap[CurPos / 2];
	}
	pPQueue->heap[CurPos] = x;
	return true;
}

unsigned int Dequeue(PriorityQueue pPQueue)
{
	//�����ѿ��򷵻�0��0�ز�Ϊ����Ԫ��
	if (pPQueue->size == 0)
		return 0;
	
	unsigned int root = pPQueue->heap[1];   //root������ԭ�Ѹ�������Ҫ���ص�ֵ
	unsigned int LastElement = pPQueue->heap[pPQueue->size--];  //LastElement����βԪ��

	//��LastElement�Ӹ���ʼ���ˣ�����CurPos��ʼ��Ϊ1��child����ָ��CurPos�������������ȼ����ߵ��Ǹ�
	unsigned int CurPos = 1;
	unsigned int child = CurPos * 2;
	while (child <= pPQueue->size)
	{
		//��child�������һ��Ԫ�أ������ֵܣ�CurPos���Һ��ӣ����ȼ����ߣ�����childָ��CurPos�Һ���
		if (child != pPQueue->size&&pPQueue->heap[child] > pPQueue->heap[child + 1])
			child += 1;
		//�Ƚ�LastElement��CurPos�����ȵĺ��ӣ���LastElement�����ȣ���ѭ������
		//������CurPos�����Ⱥ������ˣ��ȼ�����LastElement����
		if (pPQueue->heap[child] < LastElement)
		{
			pPQueue->heap[CurPos] = pPQueue->heap[child];
			CurPos = child;
			child = CurPos * 2;
		}
		else
			break;
	}
	//����ѭ�����CurPos��LastElement�ô���λ��
	pPQueue->heap[CurPos] = LastElement;

	return root;
}

void Print(PriorityQueue pPQueue)
{
	for (int i = 1;i <= pPQueue->size;++i)
	{
		printf("%u  ", pPQueue->heap[i]);
	}
	printf("\n");
}
