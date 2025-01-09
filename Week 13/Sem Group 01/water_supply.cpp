#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class UnionFind {
public:
	vector<size_t> parents;
	vector<size_t> sizes; 

	UnionFind(size_t vertices) : parents(vertices), sizes(vertices, 1)
	{
		for (size_t i = 0; i < vertices; i++)
		{
			parents[i] = i;
		}
	}

	size_t getParent(size_t vertex)
	{
		if (parents[vertex] == vertex)
		{
			return vertex;
		}

		return parents[vertex] = getParent(parents[vertex]);
	}


	bool areInOneSet(size_t first, size_t second)
	{
		return getParent(first) == getParent(second);
	}
	
	void unionVertices(size_t first, size_t second)
	{
		size_t parentOfFirst = getParent(first);
		size_t parentOfSecond = getParent(second);

		if (parentOfFirst == parentOfSecond)
		{
			return;
		}

		if (sizes[parentOfFirst] < sizes[parentOfSecond])
		{
			swap(parentOfFirst, parentOfSecond);
		}

		parents[parentOfSecond] = parentOfFirst;
		sizes[parentOfFirst] += sizes[parentOfSecond];
	}

};

class Solution
{
public:
	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes)
	{
		for (int i = 1; i <= n; i++)
		{
			pipes.push_back({ 0, i, wells[i - 1] });
		}
		
		UnionFind uf(n + 1);
		sort(pipes.begin(), pipes.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[2] < b[2];
		});

		int components = n + 1;
		int res = 0;

		for (size_t i = 0; i < pipes.size(); i++)
		{
			if (uf.areInOneSet(pipes[i][0], pipes[i][1]))
			{
				continue;
			}

			uf.unionVertices(pipes[i][0], pipes[i][1]);
			res += pipes[i][2];
			components--;
			if (components == 1)
			{
				break;
			}
		}
		
		return res;
	}

};