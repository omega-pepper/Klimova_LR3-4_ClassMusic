#include "Klimova_LR3-4_ClassMusic.h"
#include "Klimova_LR3-4_Methods.h"

// Дружественная функция вывода
ostream& operator<<(ostream& os, const Composition& c) {
    os << "Название: " << c.title << "\n";
    os << "Автор: " << c.author << "\n";
    os << "Длительность: " << c.duration << " мин.\n";
    os << "Релизы: ";
    for (const auto& release : c.releases) {
        os << release << " ";
    }
    os << "\n";
    return os;
}

// Дружественная функция ввода
istream& operator>>(istream& is, Composition& c) {
    cout << "Введите название: ";
    getline(is, c.title);
    cout << "Введите автора: ";
    getline(is, c.author);
    cout << "Введите продолжительность (в минутах): ";
    is >> c.duration;
    is.ignore(); // Очищаем буфер
    cout << "Введите релизы (разделённые пробелами): ";
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
