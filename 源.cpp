#include<iostream>
#include<vector>
using namespace std;
int judsu(int n,int *su,int numofsu){
	int count = 0;
	for (int i = 0; i < numofsu; i++){
		if (su[i] * su[i]>n)break;
		if (!(n%su[i]))count++;
	}
	if (!count)return 1;
	return 0;
}
int searchsu(int n, int *su,int numofsu){
	for (int i = 0; i < numofsu; i++){
		if (n < su[i])return i;
	}
	return numofsu;
}
int main()
{
	int *su; su = new int[446];
	su[0] = 2; su[1] = 3; su[2] = 5;
	int maxsu = 5;
	int input,i,j;
	int count = 0, numofsu = 3;
	vector<int> inputdata;
	cin >> input;
	if (input == 0){
		cout << 0;
		system("pause");
		return 0;
	}
	while (input != 0){
		inputdata.push_back(input);
		cin >> input;
	}
	for (i = 0; i < inputdata.size(); i++){
		if (inputdata[i] <= maxsu){
			cout << searchsu(inputdata[i], su, numofsu);

			continue;
		}
		count = numofsu;
		for (j = maxsu + 1; j <= inputdata[i]; j += 6){
			if (judsu(j - 1, su, numofsu)){
				count++;
				if (j - 1 != maxsu){
					if (j - 1 < 3138){
						su[numofsu++] = j - 1;
						maxsu = j - 1;
					}
				}
				else count--;
			}
			if (j + 1 > inputdata[i])break;
			if (judsu(j + 1, su, numofsu)){
				count++;
				if (j + 1 < 3138){
					maxsu = j + 1;
					su[numofsu++] = j + 1;
				}
			}
		}
		cout << count<<endl;
	}
	system("pause");
	return 0;
}