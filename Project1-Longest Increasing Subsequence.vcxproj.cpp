#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> getLength(vector<int> &arr);
vector<int> getLIS(vector<int> &arr, vector<int>&dp);


int main() {
	vector<int> L;//����һ����̬����L�洢int��
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
			L.push_back(elem);//push_back(elem)����������������
		} while (getchar() != '\n');

		vector<int> length = getLength(L);//���ú���getLength�����ݶ�̬����L
		vector<int> array = getLIS(L, length);//���ú���generateLIS������������̬����L��length

		cout << "The longest increasing subsequence is: ";
		for (int i = 0; i < array.size(); i++) {
			cout << array[i] << " ";//�����̬����lis
		}
		L.clear();//�����������������
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
	vector<int> len(nums.size(), 1);//��������len�洢int�ͣ���󳤶���nums��size����ʼֵȫΪ1
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i]) {
				len[i] = max(len[j] + 1, len[i]);//�����len
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
	for (int i = 0; i < len.size(); i++) { //Ѱ�����������ĩβ��λ�ú�ֵ
		if (len[i] > longest) {
			longest = len[i]; // ����г���
			index = i; // �����ĩλ��
		}
	}

	cout << "Length of LIS is: " << longest << endl;
	//cout << "Index of the last number: " << index << endl;
	vector<int> arr(longest, 0);
	longest--;
	arr[longest] = nums[index];//�ҵ����һ������
	//cout << len << endl;
	//cout << lis[len] << endl;

	for (int j = index; j >= 0; j--) {
		if (nums[j] < nums[index] && len[j] == len[index] - 1) { //�Ӻ���ǰ��������
			longest--;
			arr[longest] = nums[j];
			index = j;
		}
	}
	return arr;
}