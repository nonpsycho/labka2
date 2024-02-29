#ifndef __ARRAY_H__ 
#define __ARRAY_H__ 


typedef struct
{
	void* data;
	int count;
	int capacity;
	int type; 
} Vector;

Vector ConstructVec(int el_size);
void PushBackVec(Vector* str, void* el);
void* BackVec(Vector* v);
void* AtVec(Vector* v, int idx);
void DestructVec(Vector* str);

#endif


