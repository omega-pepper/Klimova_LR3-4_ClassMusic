#ifndef KLIMOVA_LR3_4_CLASSMUSIC_H
#define KLIMOVA_LR3_4_CLASSMUSIC_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <limits>
#include <numeric>

using namespace std;

class Composition 
{
private:
    string title;
    string author;
    double duration; // Длительность в минутах
    vector<string> releases;
    vector<double> promotionCosts;

public:
    // Конструкторы
    Composition(string c_title = "Неизвестный трек", string c_author = "Неизвестный автор", double c_duration = 0.0, vector<string> c_releases = {"Релизов немаэ"}, vector<double> c_promotionCosts = {0.0})
    {
        title = c_title;
        author = c_author;
        duration = c_duration;
        releases = c_releases;
        promotionCosts = c_promotionCosts;
    }
    Composition(const Composition &c)
    {
        title = c.title;
        author = c.author;
        duration = c.duration;
        releases = c.releases;
        promotionCosts = c.promotionCosts;
    }
    Composition(double d) : Composition()
    {
        duration = d;
    }
    // Деструктор
    ~Composition() = default;

    // Методы get
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getDuration() const { return duration; }
    vector<string> getReleases() const { return releases; }
    vector<double> getPromotionCosts() const { return promotionCosts; }   

    // Методы set
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setDuration(double d) { duration = d; }
    void setReleases(const vector<string>& r) { releases = r; }
    void setPromotionCosts(const vector<double>& pc) { promotionCosts = pc; }

    // Дружественные методы ввода/вывода
    friend ostream& operator<<(ostream& os, const Composition& c);
    friend istream& operator>>(istream& is, Composition& c);

    double averagePromotionCost() const {
        if (promotionCosts.empty()) return 0.0;
        return accumulate(promotionCosts.begin(), promotionCosts.end(), 0.0) / promotionCosts.size();
    }

    // Перегруженные операции
    bool operator<(const Composition& other) const; // Сравнение по длительности
    Composition operator+(const Composition& other) const; // Сложение длительностей
    Composition& operator++(); // Префиксный инкремент
    Composition operator++(int); // Постфиксный инкремент
    Composition& operator=(const Composition& other); // Присваивание

};

#endif // KLIMOVA_LR3_4_CLASSMUSIC_H