#ifndef KLIMOVA_LR3_4_METHODS_H
#define KLIMOVA_LR3_4_METHODS_H

#include "Klimova_LR3-4_ClassMusic.h"

// Глобальный вектор объектов класса Composition
vector<Composition> compositions;

// Функции проверки корректности входных данных
bool isValidDuration(double duration) {
    return duration > 0;
}

bool isValidString(const string& str) {
    return !str.empty();
}

// Функции ввода с проверкой корректности данных
double inputValidDuration() {
    double duration;
    do {
        cout << "Enter valid duration (positive number): ";
        cin >> duration;
    } while (!isValidDuration(duration));
    return duration;
}

string inputValidString(const string& prompt) {
    string str;
    do {
        cout << prompt;
        getline(cin, str);
    } while (!isValidString(str));
    return str;
}

// Функция отображения всех объектов
void displayAllCompositions() {
    for (const auto& comp : compositions) {
        cout << comp << endl;
    }
}

// Функция сортировки композиций по длительности
vector<Composition> getSortedByDuration() {
    vector<Composition> sorted = compositions;
    sort(sorted.begin(), sorted.end());
    return sorted;
}

#endif // KLIMOVA_LR3_4_METHODS_H