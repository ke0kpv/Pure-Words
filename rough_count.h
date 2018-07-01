#include <string>
#include <fstream>

int rough_count(string name){
	int counter;
	ifstream file_test;
	string test;
	file_test.open(name);
	while(file_test >> test){ counter++; }
	file_test.close();
	return counter;
}
