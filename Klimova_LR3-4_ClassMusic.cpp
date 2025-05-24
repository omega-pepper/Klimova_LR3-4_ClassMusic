#include "Klimova_LR3-4_ClassMusic.h"
#include "Klimova_LR3-4_Methods.h"

// Дружественная функция вывода 
ostream& operator<<(ostream& os, const Composition& c) {
    os << "Название: " << c.title << "\n";
    os << "Автор: " << c.author << "\n";
    os << "Длительность: " << c.duration << " мин.\n";
    os << "Релизы: ";
    
    for (const auto& r : c.releases) os << r << " ";
        os << "\nЗатраты на продвижение: ";
    for (double cost : c.promotionCosts) os << cost << " ";
        os << "\nСредние затраты: " << c.averagePromotionCost() << "\n";

    if (c.releases.empty()) {
        os << "Нет релизов";
    } 
    os << "\n";
    return os;
}

// Дружественная функция ввода 
istream& operator>>(istream& is, Composition& c) 
    {
    cout << "Введите название: ";
    getline(is >> ws, c.title);
    cout << "Введите автора: ";
    getline(is >> ws, c.author);
    cout << "Введите длительность (в минутах): ";
    while (!(is >> c.duration) || c.duration < 0) 
    {
        cout << "Некорректный ввод. Повторите (неотрицательное число): ";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  int n;
    cout << "Сколько релизов? ";
    while (!(is >> n) || n < 0) {
        cout << "Некорректный ввод. Повторите (0 или больше): ";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    is.ignore();
    c.releases.clear();
    for (int i = 0; i < n; ++i) {
        string r;
        cout << "Релиз #" << (i + 1) << ": ";
        getline(is, r);
        c.releases.push_back(r);
    }

    cout << "Сколько затрат на продвижение? ";
    while (!(is >> n) || n < 0) {
        cout << "Некорректный ввод. Повторите (0 или больше): ";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    c.promotionCosts.clear();
    for (int i = 0; i < n; ++i) {
        double cost;
        cout << "Затрата #" << (i + 1) << ": ";
        while (!(is >> cost) || cost < 0) {
            cout << "Введите неотрицательное значение: ";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        c.promotionCosts.push_back(cost);
    }

    is.ignore();
    return is;
    }
    
void demoOutputOperator()
{
    Composition c;
    cin >> c;
    cout << c;
}

// Перегруженная операция сравнения (по длительности)
bool Composition::operator<(const Composition& other) const {
    return duration < other.duration;
}

// Перегруженная операция сложения (суммирование длительностей)
Composition Composition::operator+(const Composition& other) const {
    set<string> uniqueReleases(releases.begin(), releases.end());  // Добавляем релизы из первого объекта
    uniqueReleases.insert(other.releases.begin(), other.releases.end());  // Добавляем релизы второго объекта

    vector<string> combinedReleases(uniqueReleases.begin(), uniqueReleases.end());  // Преобразуем set обратно в vector
    
    return Composition(title + " & " + other.title, author + " & " + other.author, duration + other.duration, combinedReleases, promotionCosts);
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
        promotionCosts = other.promotionCosts;
    }
    return *this;
}
