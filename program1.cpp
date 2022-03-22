// Jordan Seth Myers

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>

using namespace std;


void insertionsort(vector<string> &ar ){
		
	int j, s;

	string place;
	 
	int temp = ar.size();
	
	
	for(j = 1; j <temp; j++){
		
		place = ar[j];
		s = j - 1;
		 while(s >= 0 && ar[s] > place){
			
			ar[s + 1] = ar[s];
			s = s - 1; 
			
		}
			ar[s +1] = place;
	}
 }
 
void sort_perm(vector<string> &ar, int place){
	
	vector<string> temporary;
	
	for(int z = 0; z <= place; z++){
		temporary.push_back(ar[z]);
	}
	for(int x = ar.size() - 1; x > place; x--){
		temporary.push_back(ar[x]);
	}
	
	ar = temporary;
}


void display(vector<string> s, int z){
	
	cout << z << ":";
	 
	for(int i = 0; i < s.size(); i++){
		cout << s[i] << " ";
	}
	cout << endl << endl;
}


void Lexiographic(vector<string> s){
	
	int size = s.size();
	
	int first_index, second_index;
	int numberOfPerms = 0;
	
	string temp; 
	
	bool finish = false; 
	
	while(!finish){
		finish = true; 
		numberOfPerms++;
		display(s, numberOfPerms);
	
		for(int i = size - 2;i >= 0; i--){
			if(s[i] < s[i+1]){
				first_index = i;
				i = -1; 
				finish = false; 
			}
		}
		for(int z = size - 1; z >= 1; z--){
			if(s[first_index] < s[z]){
				second_index = z;
				z = 0;
			}
		}
		temp = s[first_index]; 
		s[first_index] = s[second_index]; 
		s[second_index] = temp; 
		
		sort_perm(s, first_index);
	}
	
	
	
}


int main(){
	
	string user_input; 
	vector<string> s; 
	
	int count = 0; 
	
	while(true){
		
		cout << "Enter a string or type quit: ";
		cin >> user_input; 
		
		if(user_input == "quit" || count == 100){
			break;
		}
		s.push_back(user_input);
		count++;
	}

	cout << endl;
	cout << "The size of your array is " <<s.size() <<" elements\n\n" << endl;
	cout << "Sorting the array with the Insertion Sort Algorithm..." << endl;
	
	insertionsort(s);
	
	Lexiographic(s);
	
	return 0; 
}
	


