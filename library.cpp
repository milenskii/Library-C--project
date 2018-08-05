#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <algorithm>

using namespace std;

class library{
	private:
		int numberOfBooks;
		vector<char*> bookTitles;
	public:
		library(){
			numberOfBooks = 0;
		}
		
		void addNewBookTitle(char *newBookTitle){
			bookTitles.push_back(newBookTitle);
		}
		
		int getNumberOfBooks(){
			return numberOfBooks;
		}
		
		void setNumberOfBooks(int newNumberOfBooks){
			numberOfBooks = newNumberOfBooks;
		}
		
		vector<char*> getBookTitles(){
			return bookTitles;
		}
		
		~library(){
			
		}
};

class library_info : public library{
	private:
		vector<char*> authorFirstName;
		vector<char*> authorLastName;
		vector<int> numberOfAuthors;
		vector<bool> available;
		vector<char*> dateOfLending;
	public:
		library_info() : library(){
			
		}
		
		void newBook(char *newBookTitle, char *newAuthorFirstName, char *newAuthorLastName, char *newDateOfLending, int newNumberOfAuthors){
			addNewBookTitle(newBookTitle);
			authorFirstName.push_back(newAuthorFirstName);
			authorLastName.push_back(newAuthorLastName);
			available.push_back(true);
			dateOfLending.push_back(newDateOfLending);
			setNumberOfBooks(getNumberOfBooks() + 1);
			numberOfAuthors.push_back(newNumberOfAuthors);
		}
		/*
		void newBooks(){
			char *newBookTitle = new char[0];
			char *newAuthorFirstName = new char[0];
			char *newAuthorLastName = new char[0];
			char *newDateOfLending = new char[0];
			int newNumberOfAuthors;
			cout << "Book Title: "; 
			cin >> newBookTitle;
			cout << "Author First Name:";
			cin >> newAuthorFirstName;
			cout << "Author Last Name:";
			cin >> newAuthorLastName;
			cout << "Date of Lending:";
			cin >> newDateOfLending;
			cout << "Number of Authors";
			cin >> newNumberOfAuthors;
			addNewBookTitle(newBookTitle);
			authorFirstName.push_back(newAuthorFirstName);
			authorLastName.push_back(newAuthorLastName);
			available.push_back(true);
			dateOfLending.push_back(newDateOfLending);
			setNumberOfBooks(getNumberOfBooks() + 1);
			numberOfAuthors.push_back(newNumberOfAuthors);
		}
		*/
		void makeUnavailable(char *searchBookTitle){
			vector<char*> temp;
			temp = getBookTitles();
			for(int i = 0; i < temp.size(); i++){
				if(!(strcmp(temp[i], searchBookTitle))){
					available[i] = false;
					return;
				}
			}
		}
		
		void updateFile(){
			vector<char*> temp;
			temp = getBookTitles();
			fstream libraryFile;
			libraryFile.open("libraryFile.txt", fstream::out);
			for(int i = 0; i < temp.size(); i++){
				libraryFile << temp[i] << "|" << authorFirstName[i] << "|" << authorLastName[i] << "|";
				libraryFile << dateOfLending[i] << "|";
				if(available[i])
					libraryFile << "available" << endl;
				else
					libraryFile << "unavailable" << endl;
			}
			libraryFile.close();
		}
		
		void printAllBooks(){
			vector<char*> temp;
			temp = getBookTitles();
			for(int i = 0; i < temp.size(); i++){
				cout << "Book Title: " << temp[i] << endl;
				cout << "Author: " << authorFirstName[i] << " " << authorLastName[i] << endl;
				cout << "Lending date: " << dateOfLending[i] << endl;
				cout << "---------------------------------------" << endl << endl;
			}
		}
		// 1 задача
		void printAvailableBooks(){
			vector<char*> temp;
			temp = getBookTitles();
			sort(temp.begin(), temp.end());
			for(int i = 0; i < temp.size(); i++){
				if(available[i]){
					cout << "Book Title: " << temp[i] << endl;
					cout << "Author: " << authorFirstName[i] << " " << authorLastName[i] << endl;
					cout << "Lending date: " << dateOfLending[i] << endl;
					cout << "---------------------------------------" << endl << endl;
				}
			}
		}
		// 2.задача
		void booksOnDate(char *searchDateOfLending){
			system("cls");
			cout << "List of books from date - " << searchDateOfLending << ": " << endl << endl;
			vector<char*> temp;
			temp = getBookTitles();
			sort(temp.begin(), temp.end());
			for(int i = 0; i < temp.size(); i++){
				if(!(strcmp(dateOfLending[i], searchDateOfLending))){
					cout << "Book Title: " << temp[i] << endl;
					cout << "Author: " << authorFirstName[i] << " " << authorLastName[i] << endl;
					cout << "Lending date: " << dateOfLending[i] << endl;
					cout << "---------------------------------------" << endl << endl;
				}
			}
		}
		// 3
		void moreThanOneAuthor(){
			system("cls");
			cout << "List of books with more than one author: " << endl << endl;
			vector<char*> temp;
			temp = getBookTitles();
			for(int i = 0; i < temp.size(); i++){
				if(numberOfAuthors[i] >= 2){
					cout << "Book Title: " << temp[i] << endl;
					cout << "Author: " << authorFirstName[i] << " " << authorLastName[i] << endl;
					cout << "Lending date: " << dateOfLending[i] << endl;
					cout << "---------------------------------------" << endl << endl;
				}
			}
		}
		
	 		ostream& operator<<(ostream &os);
		
		~library_info(){
			
		}
};

ostream& operator<<(ostream &os, library_info &object){
	system("cls");
	cout << "List of all books: " << endl << endl;
	object.printAllBooks();
	cout << endl;
	system("pause");
	system("cls");
	cout << "List of all available books: " << endl << endl;
	object.printAvailableBooks();
	cout << endl;
	system("pause");
}

int main(){
	library_info library1;
	library1.newBook("Call of Cthulhu", "Howard", "Lovecraft", "01/01/2016", 1);
	library1.newBook("Mass Effect: Revelations", "Drew", "Karpyshyn", "02/02/2016", 1);
	library1.newBook("Metro 2034", "Dmitri", "Glukhovski", "03/03/2016", 1);
	library1.newBook("The Laughing Policeman", "Alan/Per", "Blair/Wahloo", "04/04/2016", 2);
	library1.printAllBooks();
	system("PAUSE");
	//library1.newBooks();
	//library1.makeUnavailable("Call of Cthulhu");
	//cout << library1;
	//library1.booksOnDate("03/03/2016");
	//library1.moreThanOneAuthor();
	//library1.updateFile();
	return 0;
}
