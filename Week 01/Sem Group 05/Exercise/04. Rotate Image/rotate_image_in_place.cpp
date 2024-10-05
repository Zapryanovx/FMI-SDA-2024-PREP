#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>>& matrix) 
{
	for (int row = 0; row < matrix.size(); row++)
	{
		for (int col = row + 1; col < matrix.size(); col++)
		{
			std::swap(matrix[row][col], matrix[col][row]);
		}
	}
	
	for (int row = 0; row < matrix.size(); row++)
	{
		std::reverse(matrix[row].begin(), matrix[row].end());
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<std::vector<int>>matrix = { {1, 2, 3}, {4, 5, 6}, {7,8,9} };

	rotate(matrix);

	for (int row = 0; row < matrix.size(); row++)
	{
		for (int col = 0; col < matrix.size(); col++)
		{
			std::cout << matrix[row][col] << ' ';
		}
		std::cout << std::endl;
	}
}
