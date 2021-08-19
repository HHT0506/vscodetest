#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//计数排序，适合数据量大，但是数据范围小的场景
int main()
{

	vector<int> data = { 85,83,89,87,85,84,86,84,89,87,82,83,81,80,84,88,89,86,84,89,86,81,81 };

	//1.寻找最大、最小元素
	int minEle = *min_element(data.begin(), data.end());
	int maxEle = *max_element(data.begin(), data.end());

	//2.定义数组，计数
	vector<int> vec(maxEle - minEle + 1, 0);
	for (int i = 0; i < data.size(); i++)
	{
		vec[data[i] - minEle]++;
	}

	//3.还原顺序
	int index = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i]; j++)
			data[index++] = i + minEle;
	}

	for (auto &it : data)
		cout << it << " ";

	system("pause");
	return 0;
}