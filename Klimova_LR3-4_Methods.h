#ifndef KLIMOVA_LR3_4_METHODS_H
#define KLIMOVA_LR3_4_METHODS_H

#include "Klimova_LR3-4_ClassMusic.h"

// Глобальный вектор объектов класса Composition
vector<Composition> compositions;

// Функция для проверки ввода числа
double inputValidDuration() {
    double duration;
    while (true) {
        cout << "Введите действительную длительность (положительное число): ";
        cin >> duration;

        if (cin.fail() || duration <= 0) {
            cin.clear(); // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            cout << "Ошибка: введите положительное число.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            break;
        }
    }
    return duration;
}

// Функция для проверки ввода строки
string inputValidString(const string& prompt) {
    string str;
    while (true) {
        cout << prompt;
        getline(cin, str);

        if (str.empty()) {
            cout << "Ошибка: строка не может быть пустой.\n";
        } else {
            break;
        }
    }
    return str;
}

// Функция для проверки ввода целого числа
int inputValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < 0) {
            cin.clear(); // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            cout << "Ошибка: введите неотрицательное целое число.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            break;
        }
    }
    return value;
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
    Composition comp("Пример песенки", "Пример автора", 4.2, {"2022"}, {4.4});
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
     Composition comp1("Песенка по оси икс", "Артист по оси икс", 3.0, {"2021", "2022"}, {4.6});
    Composition comp2("Песенка по оси игрек", "Артист по оси игрек", 4.5, {"2022", "2023"}, {4.8});
    
    cout << "Сравнение (Песенка икс < Песенка игрек): \n" << (comp1 < comp2 ? "Ну тут всё кристально ясно" : "Пасмурно") << endl;

    Composition combined = comp1 + comp2;
    cout << "Прибавка (Песенка икс + Песенка игрек):\n" << combined << endl;
    
    cout << "Префикс инкремент:\n" << ++comp1 << endl;
    cout << "Постфикс инкремент:\n" << comp1++ << endl;
    cout << "После постфикс инкремента:\n" << comp1 << endl;
}

// Функция демонстрации работы с массивом объектов
void demoArray() {
    compositions.push_back(Composition("Каддилак", "Моргенштерн", 4.1, {"2021"}, {4.0}));
    compositions.push_back(Composition("Крутой трек", "Крутой артист", 2.5, {"2019"}, {4.1}));
    compositions.push_back(Composition("Не оч крутой трек", "Не оч крутой артист", 3.8, {"2020"}, {4.7}));
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
    Composition paramComp("Песенка А.", "Автор А.", 3.5, {"2020", "2021"}, {4.5});
    cout << "Параметрический конструктор:\n" << paramComp << endl;
}

void demoCopyConstructor() {
    Composition paramComp("Песенка Б.", "Автор Б.", 3.5, {"2020", "2021"}, {4.5});
    Composition copyComp(paramComp);
    cout << "Конструктор копирования:\n" << copyComp << endl;
}

void demoConversionConstructor() 
{
    double a = 2.0;
    Composition convertedComp = a;
    cout << "Конструктор преобразования:\n" << convertedComp << endl;
}

  // Функция демонстрации оператора <<
// void demoOutputOperator() {
//     Composition composition;

//     // Ввод названия композиции
//     string title = inputValidString("Введите название композиции: ");
//     composition.setTitle(title);

//     // Ввод автора композиции
//     string author = inputValidString("Введите автора композиции: ");
//     composition.setAuthor(author);

//     // Ввод длительности композиции
//     double duration = inputValidDuration();
//     composition.setDuration(duration);

//     // Ввод количества релизов
//     int releaseCount = inputValidInt("Введите количество релизов: ");

//     // Ввод названий релизов
//     vector<string> releases;
//     for (int i = 0; i < releaseCount; ++i) {
//         string release = inputValidString("Введите название релиза #" + to_string(i + 1) + ": ");
//         releases.push_back(release);
//     }
//     composition.setReleases(releases);

//     // Вывод информации о композиции с использованием оператора <<
//     cout << "\nИнформация о композиции:\n" << composition;
// }

#endif // KLIMOVA_LR3_4_METHODS_H