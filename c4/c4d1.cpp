#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	double conversion = 0;
	A:
	vector<double> nums(2);
	vector<string> units(2);
	nums.clear();
	units.clear();
	while(cin >> nums[0] >> units[0] >> nums[1] >> units[1]){
		if (cin.fail()){
			cout << "\nBad input!\n";
			goto A;
		}
		for (int i = 0; i < 2; ++i){
			if (units[i] == "cm")
				nums [i] *= 1;
			else if (units[i] == "m")
				nums [i] *=100;
			else if (units[i] == "in")
				nums[i] *= 2.54;
			else if (units[i] == "ft")
				nums[i] *= (2.54 * 12);
			else {
				cout << "\nBad input!\n";
				goto A;
			}
			units[i] = "cm";
		}
		cout << "\n" << nums[0] << units[0] << " " << nums[1] << units[1] << "\n";
		if(abs(nums[0]-nums[1])<0.01){
			cout << "the numbers are almost equal \n";
		}
	}
return 0;
}
