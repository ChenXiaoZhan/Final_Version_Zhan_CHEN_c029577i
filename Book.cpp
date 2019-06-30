#include "pch.h"
#include "book.h"

book::book(string ID, string title, int numberOfPage, string content) {
	m_ID = ID; //m means member variables
	m_Title = title;
	m_numOfPage = numberOfPage;
	m_bcontent = content;
}

book::book()
{
}

book::~book()
{
}

paperbook::paperbook(string ID, string title, int numberOfPage, string content) :book(ID, title, numberOfPage, content) {

}

paperbook::paperbook()
{
}

paperbook::~paperbook()
{
}

string book::getID() {
	return m_ID;
}
string book::getTitle() {
	return m_Title;
}
int book::getNumOfPage() {
	return m_numOfPage;
}
string book::getContent() {
	return m_bcontent;
}

hardbook::hardbook(string ID, string title, int numberOfPage, string content, double weight) : book(ID, title, numberOfPage, content) {
	//constructor of children class
	m_weight = weight;
}

hardbook::hardbook(double weight) : book() {
	m_weight = weight;
}

double hardbook::getWeight() {
	return m_weight;
}

hardbook::~hardbook()
{
}


magazine::magazine(string ID, string title, int numberOfPage, string content, vector<advertisement*> listofAd) : book(ID, title, numberOfPage, content) {
	//constructor of children class
	m_vectorOfAd = listofAd;
}

vector<advertisement*> magazine::getListOfAd() {
	return m_vectorOfAd;
}

void magazine::setAdvertisement(vector<advertisement*> vector_of_advertisement)
{	
	m_vectorOfAd = vector_of_advertisement;
}

magazine::~magazine()
{
}


advertisement::advertisement(string ad_title, string advertiser_ID)
{
	m_ad_title = ad_title;
	m_ad_ID = advertiser_ID;
}
string advertisement::getAd_title() {
	return m_ad_title;
}
string advertisement::getAd_ID() {
	return m_ad_ID;
}





advertiser::advertiser(string advertiser, string advertiser_ID) {
	m_ad_name = advertiser;
	m_ad_ID = advertiser_ID;
}

string advertiser::getAd_ID() {
	return m_ad_ID;
}
string advertiser::getAd_name() {
	return m_ad_name;
}






ostream & operator<<(ostream & flux, paperbook* const& apaperbook)
{
	flux << "Paperback book ID: " << apaperbook->getID() << endl;
	flux << "Paperback book Title: " << apaperbook->getTitle() << endl;
	flux << "Number of pages: " << apaperbook->getNumOfPage() << endl;
	return flux;
}

ostream & operator<<(ostream & flux, hardbook* const & ahardbook)
{
	flux << "hardback book ID: " << ahardbook->getID() << endl;
	flux << "hardback book Title: " << ahardbook->getTitle() << endl;
	flux << "Number of pages: " << ahardbook->getNumOfPage() << endl;
	flux << "weight: " << ahardbook->getWeight() << " kg" << endl;
	return flux;
}


ostream & operator<<(ostream & flux, magazine* const & amagazine)
{
	flux << "Magazine ID: " << amagazine->getID() << endl;
	flux << "Magazine Title: " << amagazine->getTitle() << endl;
	flux << "Number of pages: " << amagazine->getNumOfPage() << endl;
	return flux;
}
