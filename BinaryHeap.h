#pragma once
#ifndef XWBINARYHEAP
#define XWBINARYHEAP


//二叉堆结构定义
struct BinaryHeap {
	unsigned int capacity; //capacity表示二叉堆的最大容量
	unsigned int size;   //size表示当前二叉堆的大小，即元素个数
	unsigned int *heap;  //heap即“数组”，根据初始化时给定的大小初始化
};
typedef struct BinaryHeap *PriorityQueue;   //PriorityQueue即优先队列

PriorityQueue Initialize(unsigned int capacity);
bool Insert(PriorityQueue pPQueue, unsigned int x);
unsigned int Dequeue(PriorityQueue pPQueue);
void Print(PriorityQueue pPQueue);

#endif