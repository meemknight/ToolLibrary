#include <iostream>
#include <vector>
#include "tools.h"
#include <algorithm>



int main()
{

	std::vector<int> packages = { 0, 12, 10, 14, 1, 20, 2, 12, 1, 0, 1, 0 };
	std::partition(packages.begin(), packages.end(), arg1 < 10);

	std::for_each(packages.begin(), packages.end(), [](int p) {std::cout << p << "\n"; });

	std::cin.get();
	return 0;
}

