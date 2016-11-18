#include "stdafx.h"
#include <iostream>
#include "NPC.h"

bool test() {
	int a[5][7] = {  { 0, 0, 0, 0, 0, 0, 0 },
					 { 0, 0, 1, 0, 1, 0, 0 },
					 { 0, 0, 1, 0, 1, 0, 0 },
					 { 0, 0, 1, 1, 1, 0, 0 },
					 { 0, 0, 0, 0, 0, 0, 0 } };
	VecVecBool input(5);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 7; ++j)
			input[i].push_back(a[i][j] < 1);
	}
	Point p(0, 0);
	NPC npc(0, 0, input);
	npc.setPole(input);
	npc.position = { 2, 3 };
	Point target(4, 2);
	auto patch = npc.findPath(target);
	return true;
}



int main(int argc, char **)
{
	std::cout << test() << "\n";
	system("pause");
}

