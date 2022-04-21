#pragma once
struct Sublist
{
	int data;
	Sublist* nextSub;
};

void initSub(Sublist*& pHeadSub)
bool subIsEmpty(Sublist* pHeadSub);
