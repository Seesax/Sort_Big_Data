#include "Sort.h"
//ASCII
//0->9:48->57
//A->Z:65->90
//0->9:0->9   in array
//A->Z:10->35 in array
// radix sort
void PushBack(vector<BookRating>& arr, BookRating a) {
	int n = arr.size();
	arr.resize(n + 1);
	arr[n] = a;
}
void ArrType(vector<BookRating> arr, vector<vector <BookRating>>& tempArr) { // phan loai theo so ki tu cua id
	int n = arr.size();
	tempArr.resize(11);
	for (int j = 0; j < n; j++) {
		int k = arr[j].getId().size();
		BookRating temp = arr[j];
		PushBack(tempArr[k], temp);
	}
}
void SortById(vector<BookRating>& arr,int digits) {
	int n = arr.size();
	vector<vector <BookRating>> tempArr;
	for (int i = digits-1; i >=0; i--) {
		tempArr.clear();
		tempArr.resize(37);
		// form group
		for (int j = 0; j < n; j++) {
			if (arr[j].getId()[i] >= 48 && arr[j].getId()[i] <= 57) {
				int k = arr[j].getId()[i]-47;
				BookRating temp = arr[j];
				PushBack(tempArr[k], temp);
			}else if (arr[j].getId()[i] >= 65 && arr[j].getId()[i] <= 90) {
				int k = arr[j].getId()[i]-54;
				BookRating temp = arr[j];
				PushBack(tempArr[k],temp);
			}else if(arr[j].getId()[i] == 0){
				BookRating temp = arr[j];
				PushBack(tempArr[0], temp);
			}
		}
		int index = 0;
		for (int j = 0; j < 37; j++) {
			int k = tempArr[j].size();
			for (int f = 0; f < k; f++) {
				arr[index++] = tempArr[j][f];
			}
		}
	}
}
void SortArr(vector<BookRating>& arr, vector<vector <BookRating>>& typeArr) {
	ArrType(arr,typeArr);
	for (int i = 1; i < 11; i++) {
		SortById(typeArr[i],i);
	}
	int index = 0;
	for (int i = 1; i < 11; i++) {
		for (int j = 0; j < typeArr[i].size(); j++) {
			arr[index++] = typeArr[i][j];
		}
	}
}
void Merge_2_File(string File1_Name, string File2_Name)
{
	fstream File1, File2;
	vector <BookRating> list1, list2;
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
	// Read 2 files
	File1.open(File1_Name, ios_base::in);
	if (File1.is_open() == true)
	{
		while (File1.eof() == false)
		{
			getline(File1, id, ',');
			getline(File1, book_title, ',');
			getline(File1, price, ',');
			getline(File1, userId, ',');
			getline(File1, profileName, ',');
			getline(File1, reviewScore, ',');
			getline(File1, reviewTime, ',');
			getline(File1, reviewSummary, ',');
			getline(File1, reviewText, '\n');
			BookRating a(id, book_title, price, userId, profileName, reviewScore, reviewTime, reviewSummary, reviewText);
			list1.push_back(a);
		}
		SortById(list1, 10);
	}
	File1.close();
	File2.open(File2_Name, ios_base::in);
	if (File2.is_open() == true)
	{
		while (File1.eof() == false)
		{
			getline(File2, id, ',');
			getline(File2, book_title, ',');
			getline(File2, price, ',');
			getline(File2, userId, ',');
			getline(File2, profileName, ',');
			getline(File2, reviewScore, ',');
			getline(File2, reviewTime, ',');
			getline(File2, reviewSummary, ',');
			getline(File2, reviewText, '\n');
			BookRating a(id, book_title, price, userId, profileName, reviewScore, reviewTime, reviewSummary, reviewText);
			list2.push_back(a);
		}
		SortById(list2, 10);
	}
	File2.close();

	// Merge 2 file & Sort 
	vector <BookRating> list;
	int k = 0;
	int i = 0, j = 0;
	int n1 = list1.size();
	int n2 = list2.size();


	while (i < n1 && j < n2)
	{
		if (list1[i].getId().compare(list2[j].getId()) < 1)
		{
			list.push_back(list1[i]);
			i++;
		}
		else
		{
			list.push_back(list2[j]);
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		list[k] = list1[i];
		k++;
		i++;
	}
	while (j < n2)
	{
		list[k] = list2[i];
		k++;
		j++;
	}

	fstream FileOut;
	FileOut.open(File1_Name, ios_base::out);
	int n = n1 + n2;
	for (int i = 0; i < n; i++)
	{
		FileOut << list[i];
	}

	FileOut.close();
}
void Merge_Files()
{
	string OuputLocation = "D:/OutputFiles/Output_";
	string FileType = ".csv";
	string FileName;
	string FileOut_Name = "sorted_books_rating.csv";

	for (int i = 0; i < 31; i++)
	{
		FileName = OuputLocation + to_string(i) + FileType;
		ofstream FileOut;
		Merge_2_File(FileOut_Name, FileName);
	}
}