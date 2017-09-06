#include <stdio.h>
#include "BinaryHeap.h"

int main()
{
	PriorityQueue pPQueue = Initialize(100);
	Insert(pPQueue, 10);
	Insert(pPQueue, 9);
	Insert(pPQueue, 93);
	Insert(pPQueue, 2);
	Insert(pPQueue, 5);
	Insert(pPQueue, 76);
	Insert(pPQueue, 99);
	Insert(pPQueue, 44);
	Insert(pPQueue, 72);
	Insert(pPQueue, 234);
	Print(pPQueue);
	putchar('\n');
	for (int i = 0;i < 10;++i)
		printf("%u\n", Dequeue(pPQueue));

	return 0;
}