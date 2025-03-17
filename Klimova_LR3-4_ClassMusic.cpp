#include "Klimova_LR3-4_ClassMusic.h"

// Конструктор по умолчанию
Composition::Composition() : title("Unknown"), author("Unknown"), duration(0.0), releases({}) {}

// Параметризованный конструктор
Composition::Composition(const string& title, const string& author, double duration, const vector<string>& releases)
    : title(title), author(author), duration(duration), releases(releases) {}

// Конструктор копирования
Composition::Composition(const Composition& other)
    : title(other.title), author(other.author), duration(other.duration), releases(other.releases) {}

// Конструктор преобразования (из строки в композицию)
Composition::Composition(const string& title) : title(title), author("Unknown"), duration(0.0), releases({}) {}

// Деструктор
Composition::~Composition() {}

// Дружественная функция вывода
ostream& operator<<(ostream& os, const Composition& c) {
    os << "Title: " << c.title << "\n";
    os << "Author: " << c.author << "\n";
    os << "Duration: " << c.duration << " min\n";
    os << "Releases: ";
    for (const auto& release : c.releases) {
        os << release << " ";
    }
    os << "\n";
    return os;
}

// Дружественная функция ввода
istream& operator>>(istream& is, Composition& c) {
    cout << "Enter title: ";
    getline(is, c.title);
    cout << "Enter author: ";
    getline(is, c.author);
    cout << "Enter duration (in minutes): ";
    is >> c.duration;
    is.ignore(); // Очищаем буфер
    cout << "Enter releases (space-separated, end with '\n'): ";
    string release;
    c.releases.clear();
    while (is.peek() != '\n') {
        is >> release;
        c.releases.push_back(release);
    }
    is.ignore();
    return is;
}

// Перегруженная операция сравнения (по длительности)
bool Composition::operator<(const Composition& other) const {
    return duration < other.duration;
}

// Перегруженная операция сложения (суммирование длительностей)
Composition Composition::operator+(const Composition& other) const {
    return Composition(title + " & " + other.title, author + " & " + other.author, duration + other.duration, releases);
}

// Префиксный инкремент (увеличение длительности на 1 минуту)
Composition& Composition::operator++() {
    duration += 1.0;
    return *this;
}

// Постфиксный инкремент (увеличение длительности на 1 минуту)
Composition Composition::operator++(int) {
    Composition temp = *this;
    ++(*this);
    return temp;
}

// Перегруженная операция присваивания
Composition& Composition::operator=(const Composition& other) {
    if (this != &other) {
        title = other.title;
        author = other.author;
        duration = other.duration;
        releases = other.releases;
    }
    return *this;
}
