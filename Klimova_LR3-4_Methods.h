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
        cout << "Введите действительную длительность (положительное число): ";
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

// Функция для демонстрации работы методов
void demoMethods() {
    Composition comp("Пример песенки", "Пример автора", 4.2, {"2022"});
    cout << "Оригинальная композиция: " << endl;
    cout << comp << endl;
    
    comp.setTitle("Новое название");
    comp.setAuthor("Новый автор");
    comp.setDuration(5.0);
    comp.setReleases({"2023", "2024"});
    
    cout << "Обновлённая композиция: " << endl;
    cout << comp << endl;

}

// Функция демонстрации перегруженных операций
void demoOperators() {
    Composition comp1("Песенка по оси икс", "Артист по оси икс", 3.0, {"2021"});
    Composition comp2("Песенка по оси игрек", "Артист по оси игрек", 4.5, {"2022"});
    
    cout << "Сравнение (Песенка икс < Песенка игрек): \n" << (comp1 < comp2 ? "Ну тут всё кристально ясно" : "Пасмурно") << endl;
    cout << "Прибавка (Песенка икс + Песенка игрек):\n" << (comp1 + comp2) << endl;
    
    cout << "Префикс инкремент:\n" << ++comp1 << endl;
    cout << "Постфикс инкремент:\n" << comp1++ << endl;
    cout << "После постфикс инкремента:\n" << comp1 << endl;
}

// Функция демонстрации работы с массивом объектов
void demoArray() {
    compositions.push_back(Composition("Каддилак", "Моргенштерн", 4.1, {"2021"}));
    compositions.push_back(Composition("Крутой трек", "Крутой артист", 2.5, {"2019"}));
    compositions.push_back(Composition("Не оч крутой трек", "Не оч крутой артист", 3.8, {"2020"}));
    displayAllCompositions();
}

// Функция демонстрации сортировки
void demoSorting() {
    vector<Composition> sorted = getSortedByDuration();
    cout << "Компоцзиции осортированы по длительности:\n";
    for (const auto& comp : sorted) {
        cout << comp << endl;
    }
}

// Функции для демонстрации конструкторов
void demoDefaultConstructor() {
    Composition defaultComp;
    cout << "Конструктор по умолчанию:\n" << defaultComp << endl;
}

void demoParameterizedConstructor() {
    Composition paramComp("Песенка А.", "Автор А.", 3.5, {"2020", "2021"});
    cout << "Параметрический конструктор:\n" << paramComp << endl;
}

void demoCopyConstructor() {
    Composition paramComp("Песенка Б.", "Автор Б.", 3.5, {"2020", "2021"});
    Composition copyComp(paramComp);
    cout << "Конструктор копирования:\n" << copyComp << endl;
}

void demoConversionConstructor() 
{
    Composition convertedComp("Конверторованная песенка.");
    cout << "Конструктор преобразования:\n" << convertedComp << endl;
}
#endif // KLIMOVA_LR3_4_METHODS_H