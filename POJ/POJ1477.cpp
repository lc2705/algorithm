#include <iostream>
using namespace std;

int main()
{
	int n;
	int hi[55];
	int s = 0,i;
	
	while(1)
	{
		cin >> n;
		if(n == 0)
			break;
		s++;
		for(i = 0; i < n; i++)
			cin >> hi[i];
			
		int ave = 0;
		for(i = 0;i < n; i++)
			ave += hi[i];
		ave /= n;
		
		int moves = 0;
		for(i = 0; i < n; i++)
		{
			if(hi[i] > ave)
				moves += hi[i] - ave;
		}
		cout << "Set #" << s << endl;
		cout << "The minimum number of moves is " << moves << "." << endl << endl;
	}
}