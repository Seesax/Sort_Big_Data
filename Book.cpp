#include "Book.h"
BookRating::BookRating() {
	m_id = "";
	m_price = "";
	book_title="";
	userId="";
	m_profileName = "";
	m_reviewScore = "";
	m_reviewTime = "";
	m_reviewSummary = "";
	m_reviewText = "";
}
BookRating::BookRating(string& ID, string& Title, string& Price,string& User_id, string& profileName, string& date,string& score, string& summary, string& text) {
	m_id = ID;
	m_price = Title;
	book_title = Price;
	userId = User_id;
	m_profileName = profileName;
	m_reviewScore = score;
	m_reviewTime = date;
	m_reviewSummary = summary;
	m_reviewText = text;
}
BookRating::BookRating(const BookRating& a) {
	m_id            =a.m_id;
	m_price 		=a.m_price;
	book_title 		=a.book_title;
	userId 			=a.userId;
	m_profileName 	=a.m_profileName;
	m_reviewScore 	=a.m_reviewScore;
	m_reviewTime 	=a.m_reviewTime;
	m_reviewSummary	=a.m_reviewSummary;
	m_reviewText 	=a.m_reviewText;
}
string BookRating::getUserId() {
	return userId;
}
string BookRating::getProfileName() {
	return m_profileName;
}
string BookRating::getReviewScore() {
	return m_reviewScore;
}
string BookRating::getReviewTime() {
	return m_reviewTime;
}
string BookRating::getReviewSummary() {
	return m_reviewSummary;
}
string BookRating::getReviewText() {
	return m_reviewText;
}
string BookRating::getBook_title() {
	return book_title;
}
string BookRating::getId() {
	return m_id;
}
string BookRating::getPrice() {
	return m_price;
}
void BookRating::setUserId(string id) {
	userId = id;
}
void BookRating::setProfileName(string profile_N) {
	m_profileName = profile_N;
}
void BookRating::setReveiewScore(string review) {
	m_reviewScore = review;
}
void BookRating::setReveiewTime(string review) {
	m_reviewTime = review;
}
void BookRating::setReveiewSummary(string review) {
	m_reviewSummary = review;
}
void BookRating::setReveiewText(string review) {
	m_reviewText = review;

}
void BookRating::setId(string id) {
	m_id = id;
}
void BookRating::setPrice(string price) {
	m_price = price;
}
void BookRating::setBook_title(string title) {
	book_title = title;
}
ostream& operator << (ostream& os, BookRating& a) {
	os << a.m_id << ",";
	os << a.m_price << ",";
	os << a.book_title << ",";
	os << a.userId << ",";
	os << a.m_profileName << ",";
	os << a.m_reviewScore << ",";
	os << a.m_reviewTime << ",";
	os << a.m_reviewSummary << ",";
	os << a.m_reviewText << endl;
	return os;
}
