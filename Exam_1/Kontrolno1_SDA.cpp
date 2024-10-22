//Use case: 
//    for arrays with many dublicated elements, 
//    large array size, but each element is from a small same range
//
//Example restrictions:
//    0 <= arr.size() <= 10^7
//    -50 <= arr[i] <= 50
//
//Time-complexity: O(N + k)
//Space-complexity: O(K) (without input vector)

#include <iostream>
#include<vector>

using namespace std;

void printNoDubl(vector<int> nums) {
	int N = nums.size();
	int minEl = *min_element(nums.begin(), nums.end());
	int maxEl = *max_element(nums.begin(), nums.end());

	int K = 0;
	if (minEl < 0) {
		K = abs(minEl) + maxEl + 1;
	}
	else {
		K = maxEl - minEl + 1;
	}

	vector<int> counts(K, 0);

	for (int i = 0; i < N; i++) {
		counts[nums[i] - minEl]++;
	}

	bool containsItems = false;
	for (int i = 0; i < K; i++) {

		if (counts[i] >= 1) {
			cout << i + minEl << " ";
			counts[i]--;
			containsItems = true;
		}

		if (i == (K - 1)) {
			if (containsItems == false) {
				break;
			}
			else {
				cout << endl;
				i = -1;
				containsItems = false;
			}
		}
	}
}

int main()
{
	int N = 0;
	cin >> N;

	vector<int> nums;
	int input = 0;
	for (size_t i = 0; i < N; i++)
	{
		cin >> input;
		nums.push_back(input);
	}
	printNoDubl(nums);
}
