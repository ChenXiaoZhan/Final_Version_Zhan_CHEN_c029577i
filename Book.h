#pragma once

#include<string>
#include<list>
#include <vector>
using namespace std;
class book {
protected:
	string m_ID; //variables starting with m_ means member variables
	string m_Title;
	int m_numOfPage;
	string m_bcontent;
public:
	string getID();
	string getTitle();
	int getNumOfPage();
	string getContent();
	book(string ID, string title, int numberOfPage, string content);
	book();
	virtual ~book();

};

class paperbook : public book {

public:
	paperbook(string ID, string title, int numberOfPage, string content);
	paperbook();
	friend ostream& operator<<(ostream &flux, paperbook* const& apaperbook);
	~paperbook();
};

class hardbook :public book {
public:
	hardbook(string ID, string title, int numberOfPage, string content, double weight);
	hardbook(double weight);
	double getWeight();
	friend ostream& operator<<(ostream &flux, hardbook* const& ahardbook);
	~hardbook();

private:
	double m_weight;
};

class advertisement {
public:
	advertisement(string ad_title, string advertiser_ID);
	string getAd_title();
	string getAd_ID();
private:
	string m_ad_title;
	string m_ad_ID;

};

class advertiser {
public:
	advertiser(string advertiser, string advertiser_ID);
	string getAd_ID();
	string getAd_name();
private:
	string m_ad_ID;
	string m_ad_name;
};

class magazine :public book {
public:
	magazine(string ID, string title, int numberOfPage, string content, vector<advertisement*> listofAd);
	vector<advertisement*> getListOfAd();
	friend ostream& operator<<(ostream & flux, magazine* const & amagazine);
	void setAdvertisement(vector<advertisement*>);
	~magazine();
private:
	vector<advertisement*> m_vectorOfAd;
};



