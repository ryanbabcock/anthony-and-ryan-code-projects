#include <iostream>
#include <vector> 
#include <string>
using namespace std;
int main() {
	vector<string> numbers;
	numbers = { "zero","one","two","three","four",
	"five","six","seven","eight","nine"};
	int temp;
	while (cin >> temp){
		if (cin.fail()){
			temp = 0;
			cout << "Bad Input! Interpreted as 0. ";
		}
		else if (temp > 9){
			temp = 0;
			cout << "Bad Input! Interpreted as 0. ";
		}
		cout << '\n'<< numbers[temp] << " ";
	}	
	return 0;
}