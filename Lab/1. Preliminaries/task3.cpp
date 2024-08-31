#include <iostream>
#include <string>
#include <cstdint>

class Document {
public:
    Document( std::int32_t count=0 ) 
        : count(count) 
    {
        if (!count) {
            text = nullptr;
            return;
        }

        text = new char[count+1];

        char letter;
        std::cout << "Enter Text" << '\n';
        for (int i=0; i<count; i++) {
            std::cin >> letter;
            text[i] = letter;
        }

        text[(this->count)++] = '\0';
    }

    Document( const Document& other ) {
        text = new char[other.count];
        this->count = other.count;
        for (int i=0; i<other.count; i++) {
            (this->text)[i] = (other.text)[i];
        }
    }

    Document& operator=(const Document& other) {
        delete [] text;
        text = new char[other.count];

        this->count = other.count;
        for (int i=0; i<other.count; i++) {
            (this->text)[i] = (other.text)[i];
        }

        return *this;
    }

    void modifyCharacter(int place, char letter) {
        text[place] = letter;
    }

    void display() const {
        for (int i=0; i<count; i++) {
            std::cout << text[i];
        }
        std::cout << '\n';
    }

    ~Document() {
        delete [] text;
    }

private:
    char* text;
    std::int32_t count;
};

int main() {
    Document first(5);
    first.display();

    Document second;
    second = first;
    second.display();

    Document third(first);
    third.display();

    /*
     * Changing Orignal Text's Value
     * will it affect others?
    */

    std::cout << "\nAfter Changing First's Content\n";

    first.modifyCharacter(1, 'd');
    first.modifyCharacter(2, 'o');
    first.modifyCharacter(3, 'n');
    first.modifyCharacter(4, 'e');

    first.display();
    second.display();
    third.display();

    return 0;
}