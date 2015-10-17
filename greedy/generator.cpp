#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define UPPER 999

int main(int argc, char **argv)
{
	ofstream file;
	char filename[25];
	int i;
	srand((unsigned int)time(NULL));
	for(i = 1; i <= 10; i++)
	{
		sprintf(filename,"test_%d",i * 100000);
		file.open(filename);
		for(int j = 0;j < i*100000; j++)
		{
			file << rand()% UPPER << ' ';
		}
		file.close();
	}	
	return 0;
}