
#include <bits/stdc++.h>
using namespace std;

int minDiffSubArray(int arr[], int n)
{

	int total_sum = 0;

	for(int i = 0; i < n; i++)
		total_sum += arr[i];

	int prefix_sum = 0;

	int minDiff = INT_MAX;
	for(int i = 0; i < n - 1; i++)
	{
		prefix_sum += arr[i];

		int diff = abs((total_sum -
					prefix_sum) -
					prefix_sum);

		if (diff < minDiff)
			minDiff = diff;
	}

	return minDiff;
}
int main()
{
	int arr[] = { 7,4 , 6, 14 };

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << minDiffSubArray(arr, n) << endl;

	return 0;
}

