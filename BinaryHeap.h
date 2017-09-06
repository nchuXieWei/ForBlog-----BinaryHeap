#pragma once
#ifndef XWBINARYHEAP
#define XWBINARYHEAP


//����ѽṹ����
struct BinaryHeap {
	unsigned int capacity; //capacity��ʾ����ѵ��������
	unsigned int size;   //size��ʾ��ǰ����ѵĴ�С����Ԫ�ظ���
	unsigned int *heap;  //heap�������顱�����ݳ�ʼ��ʱ�����Ĵ�С��ʼ��
};
typedef struct BinaryHeap *PriorityQueue;   //PriorityQueue�����ȶ���

PriorityQueue Initialize(unsigned int capacity);
bool Insert(PriorityQueue pPQueue, unsigned int x);
unsigned int Dequeue(PriorityQueue pPQueue);
void Print(PriorityQueue pPQueue);

#endif