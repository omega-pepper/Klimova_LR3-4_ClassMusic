#ifndef KLIMOVA_LR3_4_CLASSMUSIC_H
#define KLIMOVA_LR3_4_CLASSMUSIC_H

#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Composition {
private:
    string title;
    string author;
    double duration; // Длительность в минутах
    vector<string> releases;

public:
    // Конструкторы
    Composition();
    Composition(const string& title, const string& author, double duration, const vector<string>& releases);
    Composition(const Composition& other);
    explicit Composition(const string& title);
    
    // Деструктор
    ~Composition();

    // Методы get
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getDuration() const { return duration; }
    vector<string> getReleases() const { return releases; }

    // Методы set
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setDuration(double d) { duration = d; }
    void setReleases(const vector<string>& r) { releases = r; }

    // Дружественные методы ввода/вывода
    friend ostream& operator<<(ostream& os, const Composition& c);
    friend istream& operator>>(istream& is, Composition& c);

    // Перегруженные операции
    bool operator<(const Composition& other) const; // Сравнение по длительности
    Composition operator+(const Composition& other) const; // Сложение длительностей
    Composition& operator++(); // Префиксный инкремент
    Composition operator++(int); // Постфиксный инкремент
    Composition& operator=(const Composition& other); // Присваивание
};

#endif // KLIMOVA_LR3_4_CLASSMUSIC_H
