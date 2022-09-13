// CPP program to find longest even sum
// subsequence.
#include <bits/stdc++.h>
using namespace std;

// Returns sum of maximum even sum subsequence
int maxEvenSum(int arr[], int n)
{
	// Find sum of positive numbers
	int pos_sum = 0;
	for (int i = 0; i < n; ++i)
		if (arr[i] > 0)
			pos_sum += arr[i];

	// If sum is even, it is our
	// answer
	if (pos_sum % 2 == 0){
		return pos_sum;
    }
	int ans = INT_MIN;
	for (int i = 0; i < n; ++i) {
		if (arr[i] % 2 != 0) {
			if (arr[i] > 0)
				ans = max(ans, pos_sum - arr[i]);
			else
				ans = max(ans, pos_sum + arr[i]);
		}
	}

	return ans;
}

// driver program
int main()
{
	int a[] = {2,3,6,-5,10,1,1};
	int n = sizeof(a) / sizeof(a[0]);
	cout << maxEvenSum(a, n);
	return 0;
}
