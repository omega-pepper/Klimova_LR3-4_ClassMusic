#include "Klimova_LR3-4_ClassMusic.h"
#include "Klimova_LR3-4_Methods.h"
#include "Klimova_LR3-4_ClassMusic.cpp"

struct MenuItem {
    string title;
    function<void()> action;
};

int main() 
{
    setlocale(LC_ALL, "Russian");

    map<int, MenuItem> menu = 
    {
        {1, {"Конструктор по умолчанию", demoDefaultConstructor}},
        {2, {"Параметризованный конструктор", demoParameterizedConstructor}},
        {3, {"Конструктор копирования",demoCopyConstructor}},
        {4, {"Конструктор преобразования",demoConversionConstructor}},
        {5, {"Методы",demoMethods}},
        {6, {"Операторы",demoOperators}},
        {7, {"Список композиций (массив)",demoArray}},
        {8, {"Сортировка по длительности",demoSorting}},
        {9, {"Ввод композиции (я хочу торт)", demoOutputOperator}},
    };

    unsigned choice = 0;
    while (true) 
    {
        cout << "Меню:\n";
        for (const auto& [key, item] : menu)
        cout << key << ". " << item.title << '\n';
        cout << "0. Выход.\n";

    int choice;
    cout << "\nВведите число: ";
    if (!(cin >> choice) || (choice != 0 && menu.find(choice) == menu.end())) 
    {
        cout << "Ошибка: введите допустимое целое число из меню!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) break;
                
        auto it = menu.find(choice);
        if (it != menu.end()) {
        it->second.action();
        } else {
            cout << "Ошибка: неверный ввод!\n";
        }
    }

    return 0;
}