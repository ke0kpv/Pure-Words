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
		int get_count(){return count;}
		void set_word(string in){ word = in;}
		void set_char(char c, int pos){ word[pos]=c;}
		string get_word(){return word;}
};

int main(){
	fstream file;
	string test;
	int counter=0;
	string* buffer;

	//file open and read into buffer, along with 
	//count so we know how many word[]'s we need
	file.open("2.txt", fstream::in);
	while(getline(file, test)){counter++;}
	buffer = new string[counter];
	file.clear();
	file.seekg(0, ios::beg);
	for(int i=0; i<counter; i++){
		string build;
		string buff;
		char buf;
		getline(file, buff);
		for(int j=0; j<buff.length(); j++){
			buf = tolower(buff[j]);
			
			if( ! ( ( (buf >= '0') && (buf <= '9') ) || 
			( ( buf >= 'a' && (buf <= 'z') )  ) )){
				buf = '\0';
			}
			if(buf != '\0'){ build += buf;}
		}
		buffer[i] = build;
	}
	file.close();
	//now that's taken care of, we can move on to processing
	//construct an instance of word_count. 
	//This is where we store our word[]
	word_count* instance = new word_count[counter];

	//lets convert every thing in the buffer to lower case
	//this is where we put the word into the final list and count
	for(int i=0; i<counter; i++){
		//set word[]	
		instance[i].set_word(buffer[i]);

		for(int j=0; j<counter; j++){
			if(instance[i].get_word() == buffer[j]){
				instance[i].count_inc();
				buffer[j]="\0";
			}
		}
	}	

	//we did some through put, now we need some out put
//	for(int loop=0; loop<counter; loop++){
//		if(instance[loop].get_word() != "\0"){
//			cout << instance[loop].get_word() << " ";
//			cout << instance[loop].get_count() << "\n";
//		}
//	}
	file.open("3.txt", fstream::out);
	for(int i=0; i< counter; i++){
		if(instance[i].get_word() != "\0"){
			file << instance[i].get_word() << " ";
			file << instance[i].get_count() << "\n";
		}
	}
	file.close();
	cout << "\n";//fuck unix
	//DESTRUCTORS!!!!!!
	delete [] instance;
	delete [] buffer;
	return 0;//obviously we are done
}
