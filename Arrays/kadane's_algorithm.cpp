// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_sum = INT_MIN, curr_sum = 0,
	start =0, end = 0, s=0;

	for (int i=0; i< size; i++ )
	{
		curr_sum += a[i];

		if (max_sum < curr_sum)
		{
			max_sum = curr_sum;
			start = s;
			end = i;
		}

		if (curr_sum < 0)
		{
			curr_sum = 0;
			s = i + 1;
		}
	}
	cout << "Maximum contiguous sum is "
		<< max_sum << endl;
	cout << "Starting index "<< start
		<< endl << "Ending index "<< end << endl;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int n;
    cin>>n;
	int *a=new int[n];
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
	int max_sum = maxSubArraySum(a, n);
	return 0;
}