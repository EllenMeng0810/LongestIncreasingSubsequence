#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> getLength(vector<int> &arr);
vector<int> getLIS(vector<int> &arr, vector<int>&dp);


int main() {
	vector<int> L;//创建一个动态数组L存储int型
	int elem;
	char flag;
	cout << "Project1-Zhaoying Meng" << endl;
	cout << "Professor: Dr.Lin Chiu" << endl;
	cout << "COMP620-Q1FF" << endl;
	cout << "Mar 18, 2020" << endl;
	cout << endl;

	do {
		cout << "Please input numbers with space: ";
		do {
			cin >> elem;
			L.push_back(elem);//push_back(elem)在数组最后添加数据
		} while (getchar() != '\n');

		vector<int> length = getLength(L);//调用函数getLength，传递动态数组L
		vector<int> array = getLIS(L, length);//调用函数generateLIS，传递向量动态数组L和length

		cout << "The longest increasing subsequence is: ";
		for (int i = 0; i < array.size(); i++) {
			cout << array[i] << " ";//输出动态数组lis
		}
		L.clear();//清除容器中所以数据
		cout << endl;
		cout << endl;
		
		cout << "Would you like to continue?(Y = yes or N = no): ";
		cin >> flag;
		if (flag == 'N' || flag == 'n') {
			cout << "Good Bye!!!" << endl;
		}
			
	} while (flag == 'Y' || flag == 'y');
	cout << endl;

	system("pause");
	return 0;
}


vector<int> getLength(vector<int> &nums) {
	vector<int> len(nums.size(), 1);//创建向量len存储int型，最大长度是nums的size，初始值全为1
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i]) {
				len[i] = max(len[j] + 1, len[i]);//求最大len
			}
		}
	}

	/*for (int k = 0; k < nums.size(); k++) {
		cout << len[k] << " ";
	}
	cout << endl;*/

	return len;
}


vector<int> getLIS(vector<int> &nums, vector<int> &len) {
	int longest = 0; 
	int index = 0;
	for (int i = 0; i < len.size(); i++) { //寻最长递增子序列末尾的位置和值
		if (len[i] > longest) {
			longest = len[i]; // 最长序列长度
			index = i; // 最长序列末位置
		}
	}

	cout << "Length of LIS is: " << longest << endl;
	//cout << "Index of the last number: " << index << endl;
	vector<int> arr(longest, 0);
	longest--;
	arr[longest] = nums[index];//找到最后一个数字
	//cout << len << endl;
	//cout << lis[len] << endl;

	for (int j = index; j >= 0; j--) {
		if (nums[j] < nums[index] && len[j] == len[index] - 1) { //从后往前找子序列
			longest--;
			arr[longest] = nums[j];
			index = j;
		}
	}
	return arr;
}