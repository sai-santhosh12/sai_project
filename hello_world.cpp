// library_system.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Book {
public:
    Book(std::string title, std::string author, int year)
        : title(title), author(author), year(year) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return year; }

    virtual void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Year: " << year << std::endl;
    }

    virtual void save(std::ofstream& outFile) const {
        outFile << title << "," << author << "," << year << std::endl;
    }

private:
    std::string title;
    std::string author;
    int year;
};

class Library {
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        for (const auto& book : books) {
            book.display();
        }
    }

    void saveBooks(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Unable to open file for writing" << std::endl;
            return;
        }
        for (const auto& book : books) {
            book.save(outFile);
        }
    }

private:
    std::vector<Book> books;
};

int main() {
    Library library;

    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("1984", "George Orwell", 1949));

    std::cout << "Books in library:" << std::endl;
    library.displayBooks();

    std::string filename = "books.txt";
    library.saveBooks(filename);
    std::cout << "Books saved to " << filename << std::endl;

    return 0;
}
