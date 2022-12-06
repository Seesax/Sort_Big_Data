#pragma once
#include "Book.h"
#include<fstream> 
#include <vector>
using namespace std;
void SortById(vector<BookRating>& arr, int digits);
void PushBack(vector<BookRating>& arr, BookRating a);
void SortArr(vector<BookRating>& arr, vector<vector <BookRating>>& typeArr);
void Merge_2_File(string File1_Name, string File2_Name);
void Merge_Files();