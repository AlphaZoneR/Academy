#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
	char a[256] = "hello my name is feri better x ferike\nwhat is happening\ndelivery hello dannielllllle	wadasd wasd dwa dsa dwa a a d b";
	int db = 0, i = 0, j = 0, word = 0, count = 0, cursor = 0;
	while(a[cursor] != '\x0'){
		if(a[cursor] == ' ' or a[cursor] == '	' or a[cursor] == '\n'){
			db++;
		}
		cursor++;
	}
	db++;
	char ** t = (char **) malloc(db * sizeof(char*));
	bool end = false;	
	while(!end){
		if(a[i] == '\x0'){
			end = true;
		}
		if((a[i] == ' ' or a[i] == '	' or a[i] == '\n' or a[i] == '\x0') and i != j){
			count = 0;
			char * buffer = (char *) malloc(i - j + 1);
			for(int k = j; k < i; k++){
				buffer[count++] = a[k];
			}
			buffer[count] = '\x0';
			t[word++] = buffer;
			j = i+1;
		}
		i++;
	}
}