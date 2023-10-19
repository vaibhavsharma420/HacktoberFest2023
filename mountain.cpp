// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

// Function to check if the given array
// is mountain array or not
bool isMountainArray(vector<int>& arr)
{
	if (arr.size() < 3)
		return false;
	int flag = 0, i = 0;
	for (i = 1; i < arr.size(); i++)
		if (arr[i] <= arr[i - 1])
			break;

	if (i == arr.size() || i == 1)
		return false;

	for (; i < arr.size(); i++)
		if (arr[i] >= arr[i - 1])
			break;
	return i == arr.size();
}
int main()
{
	vector<int> arr
		= { 1, 2, 3, 4, 9,
			8, 7, 6, 5 };
	cout << (isMountainArray(arr)
				? "true"
				: "false");
	return 0;
}
