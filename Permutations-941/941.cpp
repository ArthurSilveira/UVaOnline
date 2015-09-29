#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

 unsigned long long FACTORIAL[21]={
	1,
	1,
	2,
	6,
	24,
	120,
	720,
	5040,
	40320,
	362880,
	3628800,
	39916800,
	479001600,
	6227020800,
	87178291200,
	1307674368000,
	20922789888000,
	355687428096000,
	6402373705728000,
	121645100408832000,
	2432902008176640000
};

void getPermutation(string &s_input, unsigned long long &_K, string &s_perm);

int main()
{	
	string s_input;
	string s_perm;
	vector<string>answers;

	unsigned long long _K; // reqested permutation

	int num_of_samples;

	cin >> num_of_samples;

	while (num_of_samples > 0){

		cin.ignore();
		getline(cin, s_input);
		sort(s_input.begin(), s_input.end());
		cin >> _K;

		getPermutation(s_input, _K, s_perm);
		answers.push_back(s_perm);

		num_of_samples--;
		s_perm.erase();

	}
	
	for (int i = answers.size(); i>0; i--)
		cout << answers[i];



	return 0;
}

void getPermutation(string &s_input, unsigned long long &_K, string &s_perm)
{	
	int string_size = s_input.size();
	int currennt_letter;

	while(string_size > 0){

		currennt_letter = _K/FACTORIAL[string_size-1];
		_K = _K%FACTORIAL[string_size-1];

		s_perm.push_back(s_input[currennt_letter]);

		s_input.erase(s_input.begin()+currennt_letter);
		string_size--;
	}

	
}
