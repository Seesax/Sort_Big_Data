#pragma once
#include <string>
#include <iostream>
using namespace std;
class BookRating
{
	string m_id;
	string m_price;
	string book_title;
	string userId;
	string m_profileName;
	string m_reviewScore;
	string m_reviewTime;
	string m_reviewSummary;
	string m_reviewText;
public:
	BookRating();
	BookRating(string& ID, string& Title, string& Price, string& User_id, string& profileName, string& date, string& score, string& summary, string& text);
	BookRating(const BookRating& a);
	string getUserId();
	string getProfileName();
	string getReviewScore();
	string getReviewTime();
	string getReviewSummary();
	string getReviewText();
	string getBook_title();
	string getId();
	string getPrice();
	void setUserId(string id);
	void setProfileName(string profile_N);
	void setReveiewScore(string review);
	void setReveiewTime(string review);
	void setReveiewSummary(string review);
	void setReveiewText(string review);
	void setId(string id);
	void setPrice(string price);
	void setBook_title(string title);
	friend ostream& operator << (ostream& os, BookRating& a);
};

