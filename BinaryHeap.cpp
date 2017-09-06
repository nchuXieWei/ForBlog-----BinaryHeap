#include "BinaryHeap.h"
#include <stdlib.h>
#include <stdio.h>
PriorityQueue Initialize(unsigned int capacity)
{
	PriorityQueue pPQueue = (PriorityQueue)malloc(sizeof(struct BinaryHeap));
	pPQueue->heap = (unsigned int *)malloc(sizeof(int)*capacity);
	pPQueue->capacity = capacity;
	pPQueue->size = 0;
	pPQueue->heap[0] = 0;  //令heap[0]为0可以避免插入时新元素上滤过头

	return pPQueue;
}

bool Insert(PriorityQueue pPQueue, unsigned int x)
{
	//由于二叉堆的heap[0]是放弃不用的，所以size最大为capacity-1
	if (pPQueue->size == pPQueue->capacity - 1 || x == 0 || x > INT_MAX)
		return false;

	//CurPos即当前位置，初始化为插入后的二叉堆size，即表尾
	unsigned int CurPos = ++pPQueue->size;

	//不断地令CurPos对应的父结点与x比较，若大于x则令父结点下滤，等价于令x上滤
	//若小于x则退出循环，此时CurPos即x应处的位置
	for (;pPQueue->heap[CurPos / 2] > x;CurPos /= 2)
	{
		pPQueue->heap[CurPos] = pPQueue->heap[CurPos / 2];
	}
	pPQueue->heap[CurPos] = x;
	return true;
}

unsigned int Dequeue(PriorityQueue pPQueue)
{
	//若堆已空则返回0，0必不为表中元素
	if (pPQueue->size == 0)
		return 0;
	
	unsigned int root = pPQueue->heap[1];   //root保存了原堆根，即需要返回的值
	unsigned int LastElement = pPQueue->heap[pPQueue->size--];  //LastElement即表尾元素

	//令LastElement从根开始下滤，所以CurPos初始化为1，child用于指出CurPos两个孩子中优先级更高的那个
	unsigned int CurPos = 1;
	unsigned int child = CurPos * 2;
	while (child <= pPQueue->size)
	{
		//若child不是最后一个元素，且其兄弟（CurPos的右孩子）优先级更高，则令child指向CurPos右孩子
		if (child != pPQueue->size&&pPQueue->heap[child] > pPQueue->heap[child + 1])
			child += 1;
		//比较LastElement与CurPos最优先的孩子，若LastElement更优先，则循环结束
		//否则令CurPos最优先孩子上滤，等价于令LastElement下滤
		if (pPQueue->heap[child] < LastElement)
		{
			pPQueue->heap[CurPos] = pPQueue->heap[child];
			CurPos = child;
			child = CurPos * 2;
		}
		else
			break;
	}
	//跳出循环后的CurPos即LastElement该处的位置
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
