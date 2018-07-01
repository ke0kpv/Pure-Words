#include <iostream>
#include <string>
#include <fstream>
#include <new>
using namespace std;
class word_count{
	private:
		string word;
		int count;
	public:
		word_count(){word="\0", count=0;}
		void count_inc(){count++;}
		void set_count(int in){count=in;}
		int get_count(){return count;}
		void set_word(string in){ word = in;}
		void set_char(char c, int pos){ word[pos]=c;}
		string get_word(){return word;}
};

int main(){
//	word_count* instance;
	string* buffer;
	string test;
	int counter=0;;
	fstream file;
	//open file, count lines/words
	file.open("3.txt", fstream::in);
	while(getline(file, test)){ counter++ ;}
	cout << counter << "\n";
	//set it up
	cout << "test";
	buffer=new string[counter];
	file.clear();
	file.seekg(0, ios::beg);
	word_count* instance = new word_count[counter];//don't evaluate while you evaluate, dawg
	cout << "test";
	//read file in, restor word_count[]
	for(int i=0; i<counter; i++){
		string buf, num_buf;
		bool test=true;
		getline(file, buffer[i]);
		buffer[i] += "\n";
		for(int j=0; j < buffer[i].length(); j++){
			buf+=buffer[i].at(j);
			if(buf[j] == ' '){
				instance[i].set_word(buf);
				//buf="\0";
				test=false;
				j++;
				while(buffer[i].at(j) != '\n'){
					num_buf+=buffer[i].at(j);
					j++;
				}
				instance[i].set_count(stoi(num_buf));
					
			}
		}
	}
	file.close();
	cout << "not clouds";
	//file input done, now sort.
	bool test1=true;
	bool done;
	while (test1){ //lets get this started
		done=false; //because we only want to stop when we flip one switch
		for(int i=0; i < counter-1; i++){ //because we have to do things repeatedly
			if( instance[i].get_count() > instance[i+1].get_count() ){ // to sort, or not to sort...
				//I guess its better to have loved and lost, etc etc.
			//	cout << "\n" << i;
				string x = instance[i].get_word();
				int y = instance[i].get_count();
				//got it in the 'buffer'
				// element+1 into source
				instance[i].set_word(instance[i+1].get_word());
				instance[i].set_count(instance[i+1].get_count());
				//buffer into source
				instance[i+1].set_word(x);
				instance[i+1].set_count(y);
				//are we done?
				test1=false;
				done=true;
			} 
			if( done == true && test1 == false ) { test1=true; } //are we really done?
			if( done == false && test1 == true ) { test1=false; } //but are we really done?
//			cout << "where am I bad 1";
		}
	}
	file.open("4.txt", fstream::out);
//	for(int i=0; i<counter; i++){
//		cout << instance[i].get_word() << "   ";
//		cout << instance[i].get_count() << "\n";
//	}
	//file output!!! EVERYBODYDANCENOW.MP3
	
	for (int i=0; i<counter; i++){
		file << instance[i].get_word() << " ";
		file << instance[i].get_count() << "\n";
	}
	file.close();
	cout << "\nDONE!!!!!!!";
	delete [] instance;
	cout << "\n";
	return 0;
}
