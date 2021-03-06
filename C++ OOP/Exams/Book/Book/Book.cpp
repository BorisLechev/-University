#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Book
{
private:
	string bookName;

	int pages;

public:
	Book()
	{
		bookName = "";
		pages = 0;
	}

	Book(string bookNameParam, int pagesParam)
	{
		bookName = bookName;
		pages = pagesParam;
	}

	Book(const Book& bookParam)
	{
		bookName = bookParam.bookName;
		pages = bookParam.pages;
	}

	string GetBookName()
	{
		return bookName;
	}

	void SetBookName(string bookNameParam)
	{
		bookName = bookNameParam;
	}

	int GetPages()
	{
		return pages;
	}

	void SetPages(int pagesParam)
	{
		pages = pagesParam;
	}

	bool operator<(Book bookParam)
	{
		return bookName < bookParam.bookName;
	}

	bool operator==(Book bookParam)
	{
		return bookName == bookParam.bookName;
	}

	int operator+(Book bookParam)
	{
		return pages + bookParam.pages;
	}
};

istream& operator>>(istream &stream, Book bookParam)
{
	string bookNameParam;
	int pagesParam;

	cin >> bookNameParam;
	cin >> pagesParam;

	bookParam.SetBookName(bookNameParam);
	bookParam.SetPages(pagesParam);

	return stream;
}

ostream& operator<<(ostream &toStream, Book bookParam)
{
	toStream << "Book name: " << bookParam.GetBookName() << endl;
	toStream << "Pages: " << bookParam.GetPages() << endl;

	return toStream;
}

class Library
{
private:
	string libraryName;

	vector<Book> books;

public:
	Library()
	{
		libraryName = "";
	}

	Library(string fileName)
	{
		ifstream readFile;

		readFile.open(fileName);

		if (!readFile)
		{
			cout << "File not Found." << endl;
		}
		//else
		//{
		//	readFile >> *this;
		//}
	}

	string GetLibraryName()
	{
		return libraryName;
	}

	void SetLibraryName(string libraryNameParam)
	{
		libraryName = libraryNameParam;
	}

	vector<Book> GetBooks()
	{
		return books;
	}

	void SetBooks(vector<Book> booksParam)
	{
		books = booksParam;
	}

	vector<Book> GetBooksWithRepeatingTitle()
	{
		vector<Book> repeatingBooks;

		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < books.size(); j++)
			{
				if (books[i].GetBookName() == books[j].GetBookName())
				{
					bool alreadyAdded = false;

					for (int k = 0; k < repeatingBooks.size(); k++)
					{
						if (repeatingBooks[k].GetBookName() == books[i].GetBookName())
						{
							alreadyAdded = true;
						}
					}

					if (alreadyAdded == false)
					{
						repeatingBooks.push_back(books[i]);
					}
				}
			}
		}

		return repeatingBooks;
	}

	int RepeatingBooksCount()
	{
		return GetBooksWithRepeatingTitle().size();
	}

	int BooksPagesCountByTitle(string title)
	{
		int pagesCount = 0;

		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].GetBookName() == title)
			{
				pagesCount += books[i].GetPages();
			}
		}

		return pagesCount;
	}
};

istream& operator>>(istream &stream, Library &libraryParam)
{
	vector<Book> books;

	string nameParam;
	stream >> nameParam;
	libraryParam.SetLibraryName(nameParam);

	for (int i = 0; i < 3; i++)
	{
		Book bookParam;
		stream >> bookParam;
		books.push_back(bookParam);
	}

	libraryParam.SetBooks(books);

	return stream;
}

ostream& operator<<(ostream &toStream, Library &libraryParam)
{
	toStream << "Library name: " << libraryParam.GetLibraryName() << endl;

	for (int i = 0; i < 3; i++)
	{
		toStream << "Books: " << libraryParam.GetBooks()[i] << endl;
	}

	return toStream;
}

void main()
{
	try
	{
		//Library libraryByFile("fileName.txt");
		Library library;
		cin >> library;

		//vector <Book> repeatingBooks = library.getBooksWithRepeatingTitle();
		//Book book = repeatingBooks[0];

		//int totalPages = library.getBooksPagesCountByTitle(book.getName());
		//cout << "Pages: " << totalPages;
	}
	catch (exception error)
	{
		cout << error.what() << endl;
	}
}