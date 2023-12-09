/*
---------------------------------------------------------------------------------------------------------------------------------------------
Problem Statement: Given an integer array of coins[ ] of size N representing different types of currency and an integer sum, The task is to find the number of ways to
make sum by using different combinations from coins[].
---------------------------------------------------------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;


int count(int coins[], int n, int sum)
{

	
	if (sum == 0)
		return 1;

	if (sum < 0)
		return 0;

	if (n <= 0)
		return 0;
	return count(coins, n, sum - coins[n - 1])
		+ count(coins, n - 1, sum);
}

// Driver code
int main()
{
	int i, j;
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 5;

	cout << " " << count(coins, n, sum);

	return 0;
}
