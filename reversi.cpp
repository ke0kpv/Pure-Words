#include <iostream>
#include <fstream>
#include <string>
#include <new>
//#include "rough_count.h"
using namespace std;
string file_name = "4.txt";
int main(){
//	int a =rough_cout(f
	fstream file;
	string test;
	string* buffer;
	int counter=0;
	
	
	
	file.open(file_name, fstream::in);
	while(getline(file, test)){counter++;}
	
	buffer = new string[counter];

	file.clear();
	file.seekg(0, ios::beg);
	cout << counter;

	for(int i=0; i<counter; i++){
		getline(file, buffer[i]);
		buffer[i]+="\n";
	}

	file.close();
	file.open("5.txt", fstream::out);
	for(int i=counter-1; i>=0; i--){
		file << buffer[i];
	}
	file.close();
	delete [] buffer;
	cout << "\nREVERSI!\n";
	return 0;
}
