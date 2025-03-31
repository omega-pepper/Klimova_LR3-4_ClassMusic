#include "Klimova_LR3-4_ClassMusic.h"
#include "Klimova_LR3-4_Methods.h"

int main() 
{
    setlocale(LC_ALL, "Russian");

    map<int, void(*)()> menu = {
        {1, demoDefaultConstructor},
        {2, demoParameterizedConstructor},
        {3, demoCopyConstructor},
        {4, demoConversionConstructor},
        {5, demoMethods},
        {6, demoOperators},
        {7, demoArray},
        {8, demoSorting}
    };

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Конструктор по умолчанию.\n";
        cout << "2. Параметризованный конструктор.\n";
        cout << "3. Конструктор копирования.\n";
        cout << "4. Конструктор преобразования.\n";
        cout << "5. Методы.\n";
        cout << "6. Операторы.\n";
        cout << "7. Список композиций (массив).\n";
        cout << "8. Сортировка по длительности.\n";
        cout << "0. Выход.\n";
        
        int choice;
        cout << "\nВведите число: ";
        cin >> choice;
        cout << endl;
  
        if (choice == 0) break;
        
        auto it = menu.find(choice);
        if (it != menu.end()) {
            it->second();
        } else {
            cout << "Ошибка: неверный ввод!\n";
        }
    }
    
    return 0;
}