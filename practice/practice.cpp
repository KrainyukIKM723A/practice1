
#include <iostream>
#include <string>

using namespace std;
class Book {
private:
    string title;
    string author;
    string genre;
    int year;

public:
    Book() : title(""), author(""), genre(""), year(0) {}

    Book(::string t, ::string a, ::string g, int y) : title(t), author(a), genre(g), year(y) {}

    void setTitle(std::string t) { title = t; }
    void setAuthor(std::string a) { author = a; }
    void setGenre(std::string g) { genre = g; }
    void setYear(int y) { year = y; }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    int getYear() const { return year; }

    void printInfo() const {
        cout << "Title: " << title << ::endl;
        cout << "Author: " << author << ::endl;
        cout << "Genre: " << genre << ::endl;
        cout << "Year: " << year << ::endl;
    }
};

int main() {
    Book myBook("The Great Gatsby", "F. Scott Fitzgerald", "Novel", 1925);

    myBook.printInfo();

    myBook.setTitle("1984");
    myBook.setAuthor("George Orwell");
    myBook.setGenre("Dystopian");
    myBook.setYear(1949);

    myBook.printInfo();

    return 0;
}







#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class Vector {
private:
    vector<double> data;

public:
    Vector(const ::vector<double>& vec) : data(vec) {}

    Vector add(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        vector<double> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = data[i] + other.data[i];
        }
        return Vector(result);
    }

    Vector subtract(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        std::vector<double> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = data[i] - other.data[i];
        }
        return Vector(result);
    }

    Vector multiply(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw invalid_argument("Vectors must be of the same size");
        }
        vector<double> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = data[i] * other.data[i];
        }
        return Vector(result);
    }

    double dotProduct(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw ::invalid_argument("Vectors must be of the same size");
        }
        double result = 0;
        for (size_t i = 0; i < data.size(); ++i) {
            result += data[i] * other.data[i];
        }
        return result;
    }

    void print() const {
        for (double val : data) {
            cout << val << " ";
        }
        cout << std::endl;
    }
};

int main() {
    Vector vec1({ 1.0, 2.0, 3.0 });
    Vector vec2({ 4.0, 5.0, 6.0 });

    Vector sum = vec1.add(vec2);
    cout << "Sum: ";
    sum.print();

    Vector difference = vec1.subtract(vec2);
    cout << "Difference: ";
    difference.print();

    Vector product = vec1.multiply(vec2);
    cout << "Product: ";
    product.print();

    double dot = vec1.dotProduct(vec2);
    cout << "Dot Product: " << dot << endl;

    return 0;
}





#include <iostream>
#include <string>
using namespace;
class File {
protected:
    string name;
    double size;

public:
    File(const string& name, double size) : name(name), size(size) {}

    string getName() const { return name; }
    double getSize() const { return size; }

    virtual void printInfo() const {
        cout << "Name: " << name << ", Size: " << size << " MB" << endl;
    }
};

class TextFile : public File {
private:
    string content;

public:
    TextFile(const string& name, double size, const string& content)
        : File(name, size), content(content) {}

    string read() const { return content; }
    void write(const string& newContent) { content = newContent; }

    void printInfo() const override {
        File::printInfo();
        cout << "Content: " << content << endl;
    }
};

class Image : public File {
private:
    string resolution;

public:
    Image(const string& name, double size, const string& resolution)
        : File(name, size), resolution(resolution) {}

    string getResolution() const { return resolution; }

    void printInfo() const override {
        File::printInfo();
        cout << "Resolution: " << resolution << endl;
    }
};

class Video : public File {
private:
    double duration;

public:
    Video(const string& name, double size, double duration)
        : File(name, size), duration(duration) {}

    double getDuration() const { return duration; }

    void printInfo() const override {
        File::printInfo();
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

int main() {
    TextFile txtFile("example.txt", 0.5, "This is an example text.");
    Image imgFile("image.jpg", 2.3, "1920x1080");
    Video vidFile("video.mp4", 500.0, 120.0);

    txtFile.printInfo();
    imgFile.printInfo();
    vidFile.printInfo();

    cout << "Reading text file content: " << txtFile.read() << endl;
    txtFile.write("Updated text content.");
    cout << "Updated text file content: " << txtFile.read() << endl;

    return 0;
}





#include <iostream>
#include <string>
using namespace std;
class ElectronicDevice {
protected:
    string name;
    double screenSize;

public:
    ElectronicDevice(const string& name, double screenSize)
        : name(name), screenSize(screenSize) {}

    virtual void setOperatingSystem(const string& os) = 0;

    virtual void printInfo() const {
        cout << "Name: " << name << ", Screen Size: " << screenSize << " inches" << endl;
    }
};

class Smartphone : public ElectronicDevice {
private:
    string operatingSystem;

public:
    Smartphone(const string& name, double screenSize)
        : ElectronicDevice(name, screenSize) {}

    void setOperatingSystem(const string& os) override {
        operatingSystem = os;
    }

    void printInfo() const override {
        ElectronicDevice::printInfo();
        cout << "Operating System: " << operatingSystem << endl;
    }
};

class Tablet : public ElectronicDevice {
private:
    string operatingSystem;

public:
    Tablet(const string& name, double screenSize)
        : ElectronicDevice(name, screenSize) {}

    void setOperatingSystem(const string& os) override {
        operatingSystem = os;
    }

    void printInfo() const override {
        ElectronicDevice::printInfo();
        cout << "Operating System: " << operatingSystem << endl;
    }
};

class Laptop : public ElectronicDevice {
private:
    string operatingSystem;

public:
    Laptop(const string& name, double screenSize)
        : ElectronicDevice(name, screenSize) {}

    void setOperatingSystem(const string& os) override {
        operatingSystem = os;
    }

    void printInfo() const override {
        ElectronicDevice::printInfo();
        cout << "Operating System: " << operatingSystem << endl;
    }
};

int main() {
    Smartphone phone("iPhone", 6.1);
    Tablet tablet("iPad", 10.2);
    Laptop laptop("MacBook", 13.3);

    phone.setOperatingSystem("iOS");
    tablet.setOperatingSystem("iPadOS");
    laptop.setOperatingSystem("macOS");

    phone.printInfo();
    tablet.printInfo();
    laptop.printInfo();

    return 0;
}