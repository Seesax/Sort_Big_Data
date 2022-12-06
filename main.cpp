#include "Sort.h"
#include <fstream>
using namespace std;

int DIGITS = 10;
int MAX_PER_TIME = 100000;
string TYPE = ".csv";

int main() {
	cout << "Nhap duong dan cua file can sort:";
	string input1;
	cin >> input1;
	cout << "Nhap duong dan cua folder chua hoac muon tao file output:";
	string input2;
	cin >> input2;
	ifstream ip(input1);
	if (!ip.is_open()) {
		std::cout << "ERROR OPENING FILE" << '\n';
		return 0;
	}
	string temp;
	string id;
	string price;
	string book_title;
	string userId;
	string profileName;
	string reviewScore;
	string reviewTime;
	string reviewSummary;
	string reviewText;
	vector<BookRating> arr;
	// Skipping the first line
	getline(ip, temp);
	string OuputLocation = input2 + "/Output_";
	int dem = 0;
	string FileType = TYPE;
	fstream MyFile;
	for (int j = 0; j < 31;j++) {
		cout << j << endl;
		// Setting saving location
		string OutputFiles =OuputLocation + to_string(dem++) + FileType;
		// Reading big file
		arr.clear();
		for (int i = 0; i < MAX_PER_TIME; i++) {
			getline(ip, id, ',');
			getline(ip, book_title, ',');
			getline(ip, price, ',');
			getline(ip, userId, ',');
			getline(ip, profileName, ',');
			getline(ip, reviewScore, ',');
			getline(ip, reviewTime, ',');
			getline(ip, reviewSummary, ',');
			getline(ip, reviewText, '\n');
			BookRating a(id, book_title, price, userId, profileName, reviewScore, reviewTime, reviewSummary, reviewText);
			arr.push_back(a);
		}
		//sort
		vector<vector <BookRating>> typeArr;
		SortArr(arr, typeArr);
		for (int i = 0; i < typeArr.size();i++) {
			typeArr[i].clear();
		}
		typeArr.clear();
		// Write to piece output file
		MyFile.open(OutputFiles, ios::out | ios::trunc);
		for (int i = 0; i < MAX_PER_TIME; i++) {
			MyFile << arr[i];
		}
		MyFile.close();
	}
	// Close the file
	ip.close();
	Merge_Files();
	return 0;
}