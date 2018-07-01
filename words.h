#include <iostream>
#include <string>
using namespace std;

class word_list{
	private:
		int size,index,counter;
		string* words;
	public:
		word_list(int init){ size=init; words=new string[size]; for(int i=0; i<size; i++){
		words[i]='\0';} reset(); }
		~word_list(){ delete [] words;}
		void input(int element, string word){ words[element] = word;}
		string output(int element){return words[element];}
		int size_g(){ return size;} int index_g(){ return index;}
		int counter_g() {return counter;}
		int real_size() { reset(); do{ 
			index++;  
			if(words[index].at(0) == '\0'){ counter++;}
		}while((counter < 3) && (index < size-1));
		return index;
		}
		void reset(){ index = 0; counter = 0;}
		void index_inc() {index++;} void counter_inc() {counter ++;}
		friend istream& operator >>(string& in, word_list& cache);
		friend istream& operator >>(istream& in, word_list& cache);
		friend ostream& operator <<(ostream& out, word_list& cache);
		friend ostream& operator <<(string& out, word_list& cache);
}; 
//something about gun hole foot bang
istream& operator >>(string& in, word_list& cache){ 
	for(int i=0; i <cache.size_g(); i++){ 
		cache.input(i, in);
	}
}
istream& operator >>(istream& in, word_list& cache){
	string buffer; cache.reset();while(in >> buffer){ 
	cache.input(cache.index_g(), buffer); cache.index_inc();}
}
ostream& operator <<(ostream& out, word_list& cache){
	string buffer; 
	cache.reset();
	do{ 
		buffer = cache.output(cache.index_g()); 
		out << buffer;
		out << "\n"; 
		if(buffer[0] == '\0'){ cache.counter_inc();}
		cache.index_inc();
	}
	while((cache.counter_g() < 3) && (cache.index_g() < cache.size_g()));
}
ostream& operator <<(string& out, word_list& cache){
	string buffer; buffer = cache.output(cache.index_g());
	out = buffer; out += "\n"; if(buffer[0] == '\0'){ 
	cache.counter_inc();} cache.index_inc();
}

