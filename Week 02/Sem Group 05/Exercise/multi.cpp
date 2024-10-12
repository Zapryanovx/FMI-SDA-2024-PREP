#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> multi(n);
	int multiplier = 1;
	for (int i = 0; i < n; i++)
	{
		std::cin >> multi[i];
		multiplier *= multi[i];

	}

	for (int i = 0; i < n; i++)
	{
		multi[i] = multiplier / multi[i];
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << multi[i] << ' ';
	}



	return 0;
}