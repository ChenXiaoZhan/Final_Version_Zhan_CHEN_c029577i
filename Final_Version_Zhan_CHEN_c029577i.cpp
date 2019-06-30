// Assessment c++ Zhan CHEN.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "book.h"
#include<fstream> 
#include <list>
#include <string>
#include<vector>
#include <set>
#include <regex>
#include <mutex>
#include <thread>


using namespace std;


list<paperbook*> getInfoPBookFromText(ifstream& in_s);
list<hardbook*> getInfoHBookFromText(ifstream& in_s);
list<magazine*> getInfoMagaFromText(ifstream& in_s);
vector<vector<advertisement*> > getInfoAdvertisementFromeText(ifstream& in_s);
list<advertiser*> getInfoAdvertiser(ifstream& in_s);

unsigned int getInputNumber();
string generate_mage_ID();
bool contains(vector<string>, string);
void searchAWord(string, string);
void deallocate(list<magazine*>);
void deallocate(list<paperbook*>);
void deallocate(list<hardbook*>);

mutex m; //global mutex object, used in searching word

int main() {

	ifstream in_s;
	string act1, act2;

	int i;
	string line;
	in_s.open("bookdataset.txt");
	for (i = 0; i <= 1232; ++i) {
		getline(in_s, line);
		act1 = act1 + line + '\n';
	}

	for (i = 1233; i <= 2235; ++i) {
		getline(in_s, line);
		act2 = act2 + line + '\n';
	}

	list<paperbook*> listOfPbook;
	listOfPbook = getInfoPBookFromText(in_s);

	list<hardbook*> listOfHBook;
	listOfHBook = getInfoHBookFromText(in_s);

	list<magazine*> listOfMaga;
	listOfMaga = getInfoMagaFromText(in_s);

	vector<vector<advertisement*> >listOfListsOfAdvertisement;
	listOfListsOfAdvertisement = getInfoAdvertisementFromeText(in_s);

	int numberOflist = 0;
	list<magazine*>::iterator it;
	for (it = listOfMaga.begin(); it != listOfMaga.end(); it++) {
		(*it)->setAdvertisement(listOfListsOfAdvertisement[numberOflist]);
		numberOflist++;
	}

	list<advertiser*> listOfAdvertiser;
	listOfAdvertiser = getInfoAdvertiser(in_s);



	vector<string> vectorOfNumber;
	for (int number(0); number < 10; number++) {
		string number_string = to_string(number);
		vectorOfNumber.push_back(number_string);
	}

	string user_choice; 

	vector<string> yesOrNo;
	yesOrNo.emplace_back("y");
	yesOrNo.emplace_back("n");

	vector<string> mainmenuOrRetry;
	mainmenuOrRetry.emplace_back("m");
	mainmenuOrRetry.emplace_back("r");

MAIN:

	cout << "please enter a number to choose from the following menu :" << endl;
	cout << "1. List all magazines" << endl;
	cout << "2. List all paperback books" << endl;
	cout << "3. List all hardback books" << endl;
	cout << "4. List all advertisers" << endl;
	cout << "5. List advertisements and advertiser for a magazine" << endl;
	cout << "6. Remove a Book / Magazine by ID" << endl;
	cout << "7. Add a magazine" << endl;
	cout << "8. Search for a word" << endl;
	cout << "9. Sum of the weight of all hardback books" << endl;
	cout << "0. exit" << endl;

	do
	{
		cin >> user_choice;
		if (!contains(vectorOfNumber, user_choice)) std::cout << "please input a number between 0 and 9" << std::endl;
		std::cout << std::endl;
	} while (!contains(vectorOfNumber, user_choice));

	if (user_choice == "1") {  //----------------case 1 list all magazines----------------
		cout << "----------------------------------------------------------" << endl << endl;
		cout << "here are all the magazines: " << endl << endl;

		list<magazine*>::iterator it_maga;
		for (it_maga = listOfMaga.begin(); it_maga != listOfMaga.end(); ++it_maga) {
			cout << *it_maga << endl;
		}
		cout << "----------------------------------------------------------" << endl;

		cout << "would you back to main menu ? (y/n)" << endl;
		cout << "y: back to the main menu." << endl;
		cout << "n: exit." << endl;

		string YesOrNo_choice;

		do {
			cin >> YesOrNo_choice;
			if (!contains(yesOrNo, YesOrNo_choice)) {
				cout << "please input only 'y' or 'n' " << endl;
			}

		} while (!contains(yesOrNo, YesOrNo_choice));

		if (YesOrNo_choice == "y") {
			goto MAIN;
		}
		if (YesOrNo_choice == "n") {
			deallocate(listOfHBook);
			deallocate(listOfPbook);
			deallocate(listOfMaga);
			return 0;
		}
	}
	if (user_choice == "2") {
		cout << "----------------------------------------------------------" << endl << endl;
		cout << "here are all the paperback books:" << endl << endl;
		list<paperbook*>::iterator it_pb;
		for (it_pb = listOfPbook.begin(); it_pb != listOfPbook.end(); it_pb++) {
			cout << *it_pb << endl;
		}
		cout << "----------------------------------------------------------" << endl;
		cout << "would you back to main menu ? (y/n)" << endl;
		cout << "y: back to the main menu." << endl;
		cout << "n: exit." << endl;

		string YesOrNo_choice;

		do {
			cin >> YesOrNo_choice;
			if (!contains(yesOrNo, YesOrNo_choice)) {
				cout << "please input only 'y' or 'n' " << endl;
			}

		} while (!contains(yesOrNo, YesOrNo_choice));

		if (YesOrNo_choice == "y") {
			goto MAIN;
		}
		if (YesOrNo_choice == "n") {
			deallocate(listOfHBook);
			deallocate(listOfPbook);
			deallocate(listOfMaga);
			return 0;
		}
	}
	if (user_choice == "3") {
		cout << "----------------------------------------------------------" << endl << endl;
		cout << "here are all the hardback books: " << endl << endl;
		list<hardbook*>::iterator it_hb;
		for (it_hb = listOfHBook.begin(); it_hb != listOfHBook.end(); it_hb++) {
			cout << *it_hb << endl;
		}
		cout << "----------------------------------------------------------" << endl;
		cout << "would you back to main menu ? (y/n)" << endl;
		cout << "y: back to the main menu." << endl;
		cout << "n: exit." << endl;

		string YesOrNo_choice;

		do {
			cin >> YesOrNo_choice;
			if (!contains(yesOrNo, YesOrNo_choice)) {
				cout << "please input only 'y' or 'n' " << endl;
			}

		} while (!contains(yesOrNo, YesOrNo_choice));

		if (YesOrNo_choice == "y") {
			goto MAIN;
		}
		if (YesOrNo_choice == "n") {
			deallocate(listOfHBook);
			deallocate(listOfPbook);
			deallocate(listOfMaga);
			return 0;
		}
	}
	if (user_choice == "4") {
		/*set<string> set_of_ad_ID;
		list<magazine*>::iterator it_maga;
		for (it_maga = listOfMaga.begin(); it_maga != listOfMaga.end(); ++it_maga) {
			vector<advertisement*> listOfAd = (*it_maga)->getListOfAd();
			vector<advertisement*>::iterator it_ad;
			for (it_ad = listOfAd.begin(); it_ad != listOfAd.end(); ++it_ad) {
				set_of_ad_ID.insert((*it_ad)->getAd_ID());
			}
		}
		cout << "----------------------------------------------------------" << endl;
		set<string>::iterator it_of_set;
		for (it_of_set = set_of_ad_ID.begin(); it_of_set != set_of_ad_ID.end(); ++it_of_set) {
			cout << *it_of_set << endl;
		}*/
		cout << "Here are all advertisers:" << endl;
		list<advertiser*>::iterator it_advertiser;
		for(it_advertiser= listOfAdvertiser.begin();it_advertiser!= listOfAdvertiser.end();++it_advertiser)
		{
			cout << (*it_advertiser)->getAd_name() << endl;
		}

		cout << "----------------------------------------------------------" << endl;
		cout << "would you back to main menu ? (y/n)" << endl;
		cout << "y: back to the main menu." << endl;
		cout << "n: exit." << endl;

		string YesOrNo_choice;

		do {
			cin >> YesOrNo_choice;
			if (!contains(yesOrNo, YesOrNo_choice)) {
				cout << "please input only 'y' or 'n' " << endl;
			}

		} while (!contains(yesOrNo, YesOrNo_choice));

		if (YesOrNo_choice == "y") {
			goto MAIN;
		}
		if (YesOrNo_choice == "n") {
			deallocate(listOfHBook);
			deallocate(listOfPbook);
			deallocate(listOfMaga);
			return 0;
		}
	}
	if (user_choice == "5") {

		vector<string> listofID;

		cout << "----------------------------------------------------------" << endl;
		cout << "here are all the magazine IDs: " << endl;
		list<magazine*>::iterator it_magaID;
		for (it_magaID = listOfMaga.begin(); it_magaID != listOfMaga.end(); ++it_magaID) {
			cout << (*it_magaID)->getID() << ", ";
			listofID.push_back((*it_magaID)->getID());
		}

	SEARCH:
		cout << "\n";
		cout << "please enter a magazine ID: " << endl;
		string maga_id;
		cin >> maga_id;

		set<string> set_of_ad_ID;
		list<magazine*>::iterator it_maga;
		cout << "----------------------------------------------------------" << endl;
		for (it_maga = listOfMaga.begin(); it_maga != listOfMaga.end(); ++it_maga) {
			if ((*it_maga)->getID() == maga_id) {
				cout << "these is (are) " << (*it_maga)->getListOfAd().size() << " advertisement(s) in this magazine." << endl;
				cout << "advertiser(s) is(are): " << endl;
				vector<advertisement*> listOfAd = (*it_maga)->getListOfAd();
				vector<advertisement*>::iterator it_ad;
				for (it_ad = listOfAd.begin(); it_ad != listOfAd.end(); ++it_ad) {
					set_of_ad_ID.insert((*it_ad)->getAd_ID());
				}
				
				set<string>::iterator it_of_set;
				for (it_of_set = set_of_ad_ID.begin(); it_of_set != set_of_ad_ID.end(); ++it_of_set) {
					cout << *it_of_set << endl;

				}
				goto wouldyou;

			}
			if (!contains(listofID, maga_id)) {
				cout << "These is no magazine with this ID" << endl;
				cout << "Would you try with an another ID?(y/n) " << endl;
				cout << "y: try with an another ID" << endl;
				cout << "n: back to main menu" << endl;
				string YesOrNo_choice;
				do {
					cin >> YesOrNo_choice;
					if (!contains(yesOrNo, YesOrNo_choice)) {
						cout << "please input only 'y' or 'n' " << endl;
					}

				} while (!contains(yesOrNo, YesOrNo_choice));

				if (YesOrNo_choice == "y") {
					goto SEARCH;
				}
				if (YesOrNo_choice == "n") {
					goto MAIN;
				}
			}

		}
	wouldyou:
		cout << "----------------------------------------------------------" << endl;
		cout << "press 'm' to back to main menu or press 'r' to try with an another ID" << endl;
		cout << "m: back to the main menu." << endl;
		cout << "r: try with another ID" << endl;

		string YesOrNo_choice;
		do {
			cin >> YesOrNo_choice;
			//std::cin.ignore();
			//std::cin.clear();
			if (!contains(mainmenuOrRetry, YesOrNo_choice)) {
				cout << "please input only 'm' or 'r' " << endl;
			}

		} while (!contains(mainmenuOrRetry, YesOrNo_choice));

		if (YesOrNo_choice == "m") {
			goto MAIN;
		}
		if (YesOrNo_choice == "r") {
			goto SEARCH;
		}
	}
	if (user_choice == "6") {

		cout << "here are all the book/magazine IDs: " << endl;
		cout << "magazines: " << endl;
		list<magazine*>::iterator it_maga;
		for (it_maga = listOfMaga.begin(); it_maga != listOfMaga.end(); ++it_maga) {
			cout << (*it_maga)->getID() << ", ";
		}

		cout << "\n";
		cout << "paperback books: " << endl;

		list<paperbook*>::iterator it_pb;
		for (it_pb = listOfPbook.begin(); it_pb != listOfPbook.end(); ++it_pb) {
			cout << (*it_pb)->getID() << ", ";
		}
		cout << "\n";
		cout << "hardback books: " << endl;

		list<hardbook*>::iterator it_hb;
		for (it_hb = listOfHBook.begin(); it_hb != listOfHBook.end(); ++it_hb) {
			cout << (*it_hb)->getID() << ", ";
		}
	REMOVE:
		cout << "\n";
		cout << "enter the ID of the book or magazine that you want to delete: " << endl;

		string book_id("");
		cin >> book_id;
		bool removed = false;
		list<magazine*>::iterator it_maga_2;
		for (it_maga_2 = listOfMaga.begin(); it_maga_2 != listOfMaga.end(); ++it_maga_2) {
			if ((*it_maga_2)->getID() == book_id) {

				listOfMaga.erase(it_maga_2);

				cout << "----------------------------------------------------------" << endl;
				cout << "the magazine of this ID is deleted successfully !" << endl;
				cout << "----------------------------------------------------------" << endl;
				removed = true;
				break;
			}
		}
		if (!removed) {
			list<paperbook*>::iterator it_pb;
			for (it_pb = listOfPbook.begin(); it_pb != listOfPbook.end(); it_pb++) {
				if ((*it_pb)->getID() == book_id) {
					listOfPbook.erase(it_pb);
					cout << "----------------------------------------------------------" << endl;
					cout << "the paperbook of this ID is deleted successfully !" << endl;
					cout << "----------------------------------------------------------" << endl;
					removed = true;
					break;
				}
			}
		}

		if (!removed) {
			list<hardbook*>::iterator it_hb;
			for (it_hb = listOfHBook.begin(); it_hb != listOfHBook.end(); it_hb++) {
				if ((*it_hb)->getID() == book_id) {
					listOfHBook.erase(it_hb);
					cout << "----------------------------------------------------------" << endl;
					cout << "the hardbook of this ID is deleted successfully !" << endl;
					cout << "----------------------------------------------------------" << endl;
					removed = true;
					break;
					}
				}
		}
		if (!removed) {
			cout << "----------------------------------------------------------" << endl;
			cout << "these is no book with this ID" << endl;
			cout << "----------------------------------------------------------" << endl;
			cout << "would you want to try with another ID?(y/n)" << endl;
			string tryanother;
			cin >> tryanother;
			if (tryanother == "y") {
				goto REMOVE;
			}
			else {
				goto MAIN;
			}
		}
		if (removed) {
			cout << "would you back to main menu ? (y/n)" << endl;
			cout << "y: back to the main menu." << endl;
			cout << "n: exit." << endl;

			string YesOrNo_choice;

			vector<string> yesOrNo;
			yesOrNo.push_back("y");
			yesOrNo.push_back("n");

			do {
				cin >> YesOrNo_choice;
					if (!contains(yesOrNo, YesOrNo_choice)) {
						cout << "please input only 'y' or 'n' " << endl;
					}

				} while (!contains(yesOrNo, YesOrNo_choice));

				if (YesOrNo_choice == "y") {
					goto MAIN;
				}
				if (YesOrNo_choice == "n") {
					deallocate(listOfHBook);
					deallocate(listOfPbook);
					deallocate(listOfMaga);
					return 0;
				}
			}

	}
	if (user_choice == "7") {
		cout << "please input a title for the magazine:" << endl;
		string maga_title;
		cin >> maga_title;
		cout << "please input number of page: " << endl;
		unsigned int number_of_page;

		number_of_page=getInputNumber();

		string maga_ID = generate_mage_ID();

		string content1 = "content1";
		string content2 = "content2";

		int random = rand() % 2; //ramdom number between 0 and 1, in order to pick content1 and content2 ramdomly

		vector<string> maga_content_vector;
		maga_content_vector = {content1, content2};

		string maga_content = maga_content_vector[random]; //so magazine's content will randomly be content1 or content2;

		vector<advertisement*> vector_of_advertisements_Q7;
		vector_of_advertisements_Q7 = listOfListsOfAdvertisement[0];

		vector<advertisement*> vector_of_3_advertisements(vector_of_advertisements_Q7.begin(), vector_of_advertisements_Q7.end() - 6);
		magazine* maga = new magazine(maga_ID, maga_title, number_of_page, maga_content, vector_of_3_advertisements);

		listOfMaga.emplace_back(maga);
		cout << "The magazine has been added" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "would you back to main menu ? (y/n)" << endl;
		cout << "y: back to the main menu." << endl;
		cout << "n: exit." << endl;

		string YesOrNo_choice;

		vector<string> yesOrNo;
		yesOrNo.push_back("y");
		yesOrNo.push_back("n");

		do {
			cin >> YesOrNo_choice;
			if (!contains(yesOrNo, YesOrNo_choice)) {
				cout << "please input only 'y' or 'n' " << endl;
			}

		} while (!contains(yesOrNo, YesOrNo_choice));

		if (YesOrNo_choice == "y") {
			goto MAIN;
		}
		if (YesOrNo_choice == "n") {
			deallocate(listOfHBook);
			deallocate(listOfPbook);
			deallocate(listOfMaga);
			return 0;
		}

	}
	if (user_choice == "8") {

	SEARCHWORD:
		string word;
		cout << "please input a word: " << endl;
		cin >> word;
		cout << "------------------------------------------------------------------------------------------------" << endl;
		list<book*> list_of_all_books;

		list<magazine*>::iterator it_maga;
		for (it_maga = listOfMaga.begin(); it_maga != listOfMaga.end(); ++it_maga)
		{
			list_of_all_books.emplace_back(*it_maga);
		}
		
		list<hardbook*>::iterator it_hb;
		for (it_hb = listOfHBook.begin(); it_hb != listOfHBook.end(); ++it_hb)
		{
			list_of_all_books.emplace_back(*it_hb);
		}

		list<paperbook*>::iterator it_pb;
		for (it_pb = listOfPbook.begin(); it_pb != listOfPbook.end(); ++it_pb)
		{
			list_of_all_books.emplace_back(*it_pb);
		}

		list<book*>::iterator it_books;
		for (it_books = list_of_all_books.begin(); it_books != list_of_all_books.end(); ++it_books)
		{
			cout << (*it_books)->getTitle() << " with ID: ";
			cout << (*it_books)->getID() << ".";
			auto content = (*it_books)->getContent();
			if (content == "content1") {
				content = act1;
			}
			else
			{
				content = act2;
			}
			thread myThread(searchAWord, content, word);
			myThread.join();
		}

		/*string word;
		cout << "please input a word: " << endl;
		cin >> word;

		cout << "----------------------------------------------------------" << endl;
		list<magazine*>::iterator it_maga;
		for (it_maga = listOfMaga.begin(); it_maga != listOfMaga.end(); ++it_maga) {

			cout << (*it_maga)->getTitle() << " with ID: ";
			cout << (*it_maga)->getID() << ".";
			auto content = (*it_maga)->getContent();
			if (content == "content1") {
				content = act1;
			}
			else
			{
				content = act2;
			}
			thread myThread(searchAWord, content, word);
			myThread.join();
		}
		cout << "\n\n";
		list<hardbook*>::iterator it_hb;
		for (it_hb = listOfHBook.begin(); it_hb != listOfHBook.end(); ++it_hb) {
			cout << (*it_hb)->getTitle() << " with ID: ";
			cout << (*it_hb)->getID() << ".";
			auto content = (*it_hb)->getContent();
			if (content == "content1") {
				content = act1;
			}
			else
			{
				content = act2;
			}
			thread myThread(searchAWord, content, word);
			myThread.join();
		}

		cout << "\n\n";

		list<paperbook*>::iterator it_pb;
		for (it_pb = listOfPbook.begin(); it_pb != listOfPbook.end(); ++it_pb) {
			cout << (*it_pb)->getTitle() << " with ID: ";
			cout << (*it_pb)->getID() << ".";
			auto content = (*it_pb)->getContent();
			if (content == "content1") {
				content = act1;
			}
			else
			{
				content = act2;
			}
			thread myThread(searchAWord, content, word);
			myThread.join();
		}*/
		cout << "------------------------------------------------------------------------------------------------" << endl;

		cout << "Would you like to search for another word?(y/n)" << endl;
		cout << "y: search for another word." << endl;
		cout << "n: back to main menu" << endl;
		string yesOrNo;
		cin >> yesOrNo;
		if (yesOrNo == "y") {
			goto SEARCHWORD;
		}
		if (yesOrNo == "n") {
			goto MAIN;
		}
	}
	if (user_choice == "9") {
		double total(0);

		list<hardbook*>::iterator it_hb;
		for (it_hb = listOfHBook.begin(); it_hb != listOfHBook.end(); ++it_hb) {
			total = total + (*it_hb)->getWeight();
		}


		cout << "----------------------------------------------------------" << endl;
		cout << "The sum of the weight of all hardback books is: ";
		cout << total << "kg" << endl;
		cout << "----------------------------------------------------------" << endl;

		cout << "would you back to main menu ? (y/n)" << endl;
		cout << "y: back to the main menu." << endl;
		cout << "n: exit." << endl;

		string YesOrNo_choice;

		do {
			cin >> YesOrNo_choice;
			//std::cin.ignore();
			//std::cin.clear();
			if (!contains(yesOrNo, YesOrNo_choice)) {
				cout << "please input only 'y' or 'n' " << endl;
			}
		} while (!contains(yesOrNo, YesOrNo_choice));

		if (YesOrNo_choice == "y") {
			goto MAIN;
		}
		if (YesOrNo_choice == "n") {
			return 0;
		}
	}
	if (user_choice == "0") {
		deallocate(listOfHBook);
		deallocate(listOfPbook);
		deallocate(listOfMaga);
		return 0;
	}

	return 0;
}



list<paperbook*> getInfoPBookFromText(ifstream& in_s) {

	string line;
	getline(in_s, line);
	while (line.empty()) {
		getline(in_s, line);
	};//skip blanc lines until sentinel

	string numOfPbook_string;

	getline(in_s, numOfPbook_string);//to store how many books are there

	int numOfPbook_int = atoi(numOfPbook_string.c_str());//convert string to intger

	list<paperbook*> listOfPaperbook;//declare a linked list containing pointers to paperbook object

	string id;
	string title;
	string page_string; //number of page is string in this moment, I'll convert it to integer later
	string content;

	for (int i = 1; i <= numOfPbook_int; i++) {
		getline(in_s, id);// read line and store string into id variable
		getline(in_s, title);// read line and store string into title variable
		getline(in_s, page_string);// read line and store string page_stringvariable
		getline(in_s, content);// read line and store string into content variable

		int page_int = atoi(page_string.c_str());//converts string to int

		paperbook* paperbook1 = new paperbook(id, title, page_int, content);//create new pointer to paperbook object

		listOfPaperbook.push_back(paperbook1);//push it to the linked list
	}
	return listOfPaperbook;
}

list<hardbook*> getInfoHBookFromText(ifstream& in_s) {

	string line;
	getline(in_s, line);
	while (line.empty()) {
		getline(in_s, line);
	};

	string numOfHbook_string;

	getline(in_s, numOfHbook_string);

	int numOfHbook_int = atoi(numOfHbook_string.c_str());//convert string to intger

	list<hardbook*> listOfHardbook;

	string id;
	string title;
	string page_string; //number of page is string in this moment, I'll convert it to integer later
	string weight_string;//weight is string for now, I'll convert it to integer later
	string content;

	for (int i = 1; i <= numOfHbook_int; i++) {
		getline(in_s, id);
		getline(in_s, title);
		getline(in_s, page_string);
		getline(in_s, content);
		getline(in_s, weight_string);

		int page_int = atoi(page_string.c_str());
		double weight_float = atof(weight_string.c_str());

		hardbook* hardbook1 = new hardbook(id, title, page_int, content, weight_float);


		listOfHardbook.push_back(hardbook1);
	}
	return listOfHardbook;
}

/*list<magazine*> getInfoMagaFromText(ifstream& in_s) {

	string line;
	getline(in_s, line);
	while (line.empty()) {
		getline(in_s, line);
	};

	string numOfMaga_string;

	getline(in_s, numOfMaga_string);

	int numOfMaga_int = atoi(numOfMaga_string.c_str());//convert string to intger

	list<magazine*> listOfMaga;

	string id;
	string title;
	string page_string; //number of page is string in this moment, I'll convert it to integer later
	string content;

	string number_of_advertisement_string;

	for (int j = 1; j <= numOfMaga_int; j++) {
		getline(in_s, id);
		getline(in_s, title);
		getline(in_s, page_string);
		getline(in_s, content);
		getline(in_s, number_of_advertisement_string);

		list<advertisement*> listofAd_func;

		int page_int = atoi(page_string.c_str());
		int number_of_advertisement_int = atoi(number_of_advertisement_string.c_str());
		for (int i = 1; i <= number_of_advertisement_int; i++) {
			string ad_title;
			string advertiser_ID;
			getline(in_s, ad_title);
			getline(in_s, advertiser_ID);
			advertisement* advertisement1 = new advertisement(ad_title, advertiser_ID);
			listofAd_func.push_back(advertisement1);
		}

		magazine* magazine1 = new magazine(id, title, page_int, content, listofAd_func);

		listOfMaga.push_back(magazine1);

	}
	return listOfMaga;
}*/

list<magazine*> getInfoMagaFromText(ifstream& in_s) {

	string line;
	getline(in_s, line);
	while (line.empty()) {
		getline(in_s, line);
	};

	string numOfMaga_string;

	getline(in_s, numOfMaga_string);

	int numOfMaga_int = atoi(numOfMaga_string.c_str());//convert string to intger

	list<magazine*> listOfMaga;

	string id;
	string title;
	string page_string; //number of page is string in this moment, I'll convert it to integer later
	string content;


	for (int j = 1; j <= numOfMaga_int; j++) {
		getline(in_s, id);
		getline(in_s, title);
		getline(in_s, page_string);
		getline(in_s, content);

		int page_int = atoi(page_string.c_str());

		vector<advertisement*> list_of_advertisement(0);

		magazine* magazine1 = new magazine(id, title, page_int, content, list_of_advertisement);

		listOfMaga.push_back(magazine1);

	}
	return listOfMaga;
}

vector<vector<advertisement*> > getInfoAdvertisementFromeText(ifstream& in_s)
{
	string line;
	getline(in_s, line);
	while (line.empty()) {
		getline(in_s, line);
	};

	string number_of_lists;

	getline(in_s, number_of_lists);

	int number_of_lists_int = atoi(number_of_lists.c_str());

	vector<vector<advertisement*> >list_of_lists_of_advertisements;

	for(int j=0;j< number_of_lists_int;j++){

		string number_of_advertisement;
		getline(in_s, number_of_advertisement);

		int number_of_advertisement_int = atoi(number_of_advertisement.c_str());
		
		vector<advertisement*> list_of_advertisement;

		for(int i = 0;i< number_of_advertisement_int; i++)
		{
			string advertiserment_title;
			string advertiser_id;
			getline(in_s, advertiserment_title);
			getline(in_s, advertiser_id);

			advertisement* advertisements = new advertisement(advertiserment_title, advertiser_id);
			list_of_advertisement.emplace_back(advertisements);
		}

		list_of_lists_of_advertisements.emplace_back(list_of_advertisement);
	}

	return list_of_lists_of_advertisements;
}

list<advertiser*> getInfoAdvertiser(ifstream& in_s) {
	string line;
	getline(in_s, line);
	while (line.empty()) {
		getline(in_s, line);
	};

	string numOfadvertiser_string;

	getline(in_s, numOfadvertiser_string);

	int num_Of_advertiser_int = atoi(numOfadvertiser_string.c_str());//convert string to integer

	list<advertiser*> listOfAdvertiser;

	string ad_name;
	string ad_ID;

	for (int i = 0; i  < num_Of_advertiser_int; i++) {
		getline(in_s, ad_name);
		getline(in_s, ad_ID);

		advertiser* advertiser1 = new advertiser(ad_name, ad_ID);

		listOfAdvertiser.push_back(advertiser1);
	}
	return listOfAdvertiser;

}

unsigned int getInputNumber() {
	string str;
	unsigned int str_int(1);
	regex regex_pattern("[0-9]+?[0-9]+");
	do
	{
		cout << "number of pages must be postive integer " << endl;
		cout << "(if it contains only 1 page, enter 01, if 2 pages enter 02, etc)" << endl;

		cin >> str;

		str_int = atoi(str.c_str());
	} while (!regex_match(str, regex_pattern) || str_int == 0);

	return str_int;
}

string generate_mage_ID() {
	static int i = 1000;

	string str = to_string(i);
	return str;
}


/*list<advertisement> get_3_maga_advertisement(list<magazine> listOfmaga) {

	list<advertisement> listofAd;
	listofAd = listOfmaga.front().getListOfAd();

}*/



bool contains(vector<string> vectorOfString, string s) {
	for (size_t i = 0; i < vectorOfString.size(); i++) {   //!!!!!!!important here we use size_t, not int. else '<': signed/unsigned mismatch!!!!!!!!!!!!!!!!
		if (vectorOfString[i] == s) {
			return true;
		}
	}
	return false;
}

void searchAWord(string content, string word) {
	m.lock();

	int found = 0, i = 0, count = -1;

	while (found != -1) {
		found = content.find(word, i);
		count = count + 1;
		i = found + 1;
	}
	if (count == 0) {
		cout << " This book does not contain any of this word." << endl;
	}
	else
	{
		cout << " There is(are) " << count << " occurrence(s) in this book/magazine" << endl;
	}
	this_thread::sleep_for(std::chrono::milliseconds(3000));
	m.unlock();

}

void deallocate(list<magazine*> listm) {
	while (!listm.empty()) delete listm.front(), listm.pop_front();
}

void deallocate(list<paperbook*> listp) {
	while (!listp.empty()) delete listp.front(), listp.pop_front();
}

void deallocate(list<hardbook*> listh) {
	while (!listh.empty()) delete listh.front(), listh.pop_front();
}
