#include "Klimova_LR3-4_Methods.h"

// Функция для демонстрации всех конструкторов
void demoConstructors() {
    Composition defaultComp;
    Composition paramComp("Song A", "Author A", 3.5, {"2020", "2021"});
    Composition copyComp(paramComp);
    Composition convertedComp("Converted Song");
    
    cout << "Default Constructor:\n" << defaultComp << endl;
    cout << "Parameterized Constructor:\n" << paramComp << endl;
    cout << "Copy Constructor:\n" << copyComp << endl;
    cout << "Conversion Constructor:\n" << convertedComp << endl;
}

// Функция для демонстрации работы методов
void demoMethods() {
    Composition comp("Example Song", "Example Author", 4.2, {"2022"});
    cout << "Original composition:\n" << comp << endl;
    
    comp.setTitle("New Title");
    comp.setAuthor("New Author");
    comp.setDuration(5.0);
    comp.setReleases({"2023", "2024"});
    
    cout << "Updated composition:\n" << comp << endl;
}

// Функция демонстрации перегруженных операций
void demoOperators() {
    Composition comp1("Song X", "Artist X", 3.0, {"2021"});
    Composition comp2("Song Y", "Artist Y", 4.5, {"2022"});
    
    cout << "Comparison (comp1 < comp2): " << (comp1 < comp2 ? "True" : "False") << endl;
    cout << "Addition (comp1 + comp2):\n" << (comp1 + comp2) << endl;
    
    cout << "Prefix Increment:\n" << ++comp1 << endl;
    cout << "Postfix Increment:\n" << comp1++ << endl;
    cout << "After Postfix Increment:\n" << comp1 << endl;
}

// Функция демонстрации работы с массивом объектов
void demoArray() {
    compositions.push_back(Composition("Track 1", "Artist 1", 2.5, {"2019"}));
    compositions.push_back(Composition("Track 2", "Artist 2", 3.8, {"2020"}));
    compositions.push_back(Composition("Track 3", "Artist 3", 4.1, {"2021"}));
    displayAllCompositions();
}

// Функция демонстрации сортировки
void demoSorting() {
    vector<Composition> sorted = getSortedByDuration();
    cout << "Sorted compositions by duration:\n";
    for (const auto& comp : sorted) {
        cout << comp << endl;
    }
}

int main() {
    map<int, void(*)()> menu = {
        {1, demoConstructors},
        {2, demoMethods},
        {3, demoOperators},
        {4, demoArray},
        {5, demoSorting}
    };
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Demonstrate Constructors\n";
        cout << "2. Demonstrate Methods\n";
        cout << "3. Demonstrate Operators\n";
        cout << "4. Demonstrate Array of Compositions\n";
        cout << "5. Demonstrate Sorting\n";
        cout << "0. Exit\n";
        
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 0) break;
        
        auto it = menu.find(choice);
        if (it != menu.end()) {
            it->second();
        } else {
            cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}
