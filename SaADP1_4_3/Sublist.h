#pragma once
struct Sublist
{
	int data;
	Sublist* nextSub;
};

bool subIsEmpty(Sublist* pHeadSub);