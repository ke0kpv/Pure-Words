#include <iostream>
#include <string>
#include <fstream>
#include "words.h"
#include "rough_count.h"
using namespace std;
string file_name = "1.txt";
int main(){
	fstream file;
	int a=rough_count(file_name);
	word_list instance(a);
	file.open(file_name, fstream::in);
	file >> instance;	
	file.close();
	string testing, buffer;
	int real = instance.real_size();
	instance.reset();
	for(int i=0; i<real; i++){
		buffer << instance;
	//	cout << buffer;
		testing += buffer;
	}
	
	file.open("2.txt", fstream::out);
	file << testing;
	file.close();
	cout << "\n";
	return 0;
}
