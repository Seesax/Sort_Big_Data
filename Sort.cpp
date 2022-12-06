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