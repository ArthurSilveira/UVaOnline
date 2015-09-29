#include <iostream>

using namespace std;

long long getOddSum(long long &N);

int main()
{	
	long long N;
	while (cin >> N){
		cout << getOddSum(N) << endl;
	}
	return 0;
}

long long getOddSum(long long &N){

	return ( 6*  ( ( (N+1)/2 ) * ( (N+1)/2 ) )   -9);

}