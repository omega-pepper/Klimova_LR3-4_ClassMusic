#include "Klimova_LR3-4_ClassMusic.h"
#include "Klimova_LR3-4_ClassMusic.cpp"
#include "Klimova_LR3-4_Methods.h"

// Функция для демонстрации всех конструкторов
void demoConstructors() {
    Composition defaultComp;
    Composition paramComp("ПесенкААААААААААААААААААААААААА", "АААААААААААААААААААААААААвтор", 3.5, {"2020", "2021"});
    Composition copyComp(paramComp);
    Composition convertedComp("Конвертированная песенка.");
    
    cout << "Конструктор по умолчанию:\n" << defaultComp << endl;
    cout << "Параметрический конструктор:\n" << paramComp << endl;
    cout << "Конструктор копирования:\n" << copyComp << endl;
    cout << "Конверсионный конструктор:\n" << convertedComp << endl;
}

// Функция для демонстрации работы методов
void demoMethods() {
    Composition comp("Пример песенки", "Пример автора", 4.2, {"2022"});
    cout << "Оригинальная композиция: " << comp << endl;
    
    comp.setTitle("Новое название");
    comp.setAuthor("Новый автор");
    comp.setDuration(5.0);
    comp.setReleases({"2023", "2024"});
    
    cout << "Обновлённая композиция: " << comp << endl;
}

// Функция демонстрации перегруженных операций
void demoOperators() {
    Composition comp1("Песенка по оси икс", "Артист по оси икс", 3.0, {"2021"});
    Composition comp2("Песенка по оси игрек", "Артист по оси игрек", 4.5, {"2022"});
    
    cout << "Сравнение (Песенка икс < Песенка игрек): " << (comp1 < comp2 ? "Ну тут всё кристально ясно" : "Пасмурно") << endl;
    cout << "Прибавка (Песенка икс + Песенка игрек):\n" << (comp1 + comp2) << endl;
    
    cout << "Префикс инкремент:\n" << ++comp1 << endl;
    cout << "Постфикс инкремент:\n" << comp1++ << endl;
    cout << "После постфикс инкремента:\n" << comp1 << endl;
}

// Функция демонстрации работы с массивом объектов
void demoArray() {
    compositions.push_back(Composition("Крутой трек", "Крутой артист", 2.5, {"2019"}));
    compositions.push_back(Composition("Не оч крутой трек", "Не оч крутой артист", 3.8, {"2020"}));
    compositions.push_back(Composition("Каддилак", "Моргенштерн", 4.1, {"2021"}));
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

int main() {

    setlocale(LC_ALL, "Russian");

    map<int, void(*)()> menu = {
        {1, demoConstructors},
        {2, demoMethods},
        {3, demoOperators},
        {4, demoArray},
        {5, demoSorting}
    };
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Конструкторы.\n";
        cout << "2. Методы.\n";
        cout << "3. Операторы.\n";
        cout << "4. Список композиций (массив).\n";
        cout << "5. Сортировка по длительности.\n";
        cout << "0. Выход.\n";
        
        int choice;
        cout << "Введите число: ";
        cin >> choice;
        
        if (choice == 0) break;
        
        auto it = menu.find(choice);
        if (it != menu.end()) {
            it->second();
        } else {
            cout << "Фигня!\n";
        }
    }
    
    return 0;
}
