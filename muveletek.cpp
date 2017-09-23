#include <iostream>
#include <string>
using namespace std;


int atoi(std::string t){
	int szam = 0, i = 0;
	bool found = false, negative = false, end = false;
	while( t[i] != '\x0' and !end )
	{
		if( t[i] >= '0' and t[i] <= '9' )
		{
			if( !found and i > 0 )
			{
				if( t[i - 1] == '-' )
				{
					negative = true;
				}
			}
			
			found = true;
			int number = int(t[i] - '0');
			szam = szam * 10 + number;
			
			if( i + 1 < t.size())
			{
				if( t[i + 1] < '0' or t[i + 1] > '9' )
				{
					end = true;
				}
			}
		}
		
		i++;
	}

	if(negative)
	{
		return -szam;
	}

	return szam;
}


std::string itoa(int szam){
	string sz;
	while(szam != 0){
		sz.insert(0, 1, '0' + szam%10);
		szam /= 10;
	}
	return sz;
}

int szimpla_muveletek(string a){
	int eredmeny;
	for(int i = 0 ; i < a.size(); i++){
		int beg, end;
		if(a[i] == '+'){
			int j = i - 2;
							
			while(j != 0 and a[j] != ' '){
					j--;
			}
			int elso = atoi(a.substr(j, i - 1));		
			
			beg = j;

			j = i + 2;
			while(j < a.size() and a[j] != ' ') {
				j++;
			}
			
			end = j;

			int masodik = atoi(a.substr(i+2, j));

			a.erase(beg, end-beg);
			a.insert(beg, itoa(elso + masodik));
			i = beg;
		}else if(a[i] == '-'){
			int j = i - 2;
				
			while(j != 0 and a[j] != ' '){
					j--;
			}
				
			int elso = atoi(a.substr(j+1, i - 1));
			beg  = j;
			j = i + 2;

			while(j < a.size() and a[j] != ' ') {
				j++;
			}
			end = j;
			int masodik = atoi(a.substr(i+2, j));

			a.erase(beg, end-beg);
			a.insert(beg, itoa(elso - masodik));
			i = beg;
		}
	}
	return(atoi(a));
}


int muveletek(string a){
	for(int i = 0; i < a.size(); i++){
		if(a[i] == '*'){
			int beg, end;
			int j = i - 2;
			
			while(j != 0 and a[j] != ' '){
				j--;
			}
			
			int elso = atoi(a.substr(j+1, i - 1));
			
			beg = j + 1;
			
			j = i + 2;

			while(j < a.size() and a[j] != ' ') {
				j++;
			}
			
			end = j;

			int masodik = atoi(a.substr(i+2, j));

			a.erase(beg, end-beg);
			a.insert(beg, itoa(elso * masodik));
			i = beg;

		}else if(a[i] == '/'){
			int beg, end;
			int j = i - 2;
			
			while(j != 0 and a[j] != ' '){
				j--;
			}
			
			int elso = atoi(a.substr(j+1, i - 1));
			beg = j + 1;
			j = i + 2;

			while(j < a.size() and a[j] != ' ') {
				j++;
			}
			end = j;
			int masodik = atoi(a.substr(i+2, j));

			a.erase(beg, end-beg);
			a.insert(beg, itoa(elso / masodik));
			i = beg;
		}
	}
	return szimpla_muveletek(a);
}

void zarojeltelenit(string a){
}


int main(){
	string a = "1 + 12 * 23 * 2 / 2 + 2 + 3 * 4";
	cout << muveletek(a) << endl;
	return 0;
}
