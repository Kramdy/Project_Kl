#include <iostream>
#include <cstring>
using namespace std;

// ===== Клас String =====
class String {
private:
    char* str;
    int size;

public:
    // Конструктор за замовчуванням
    String() {
        size = 80;
        str = new char[size];
        str[0] = '\0';
    }

    // Конструктор з розміром
    String(int s) {
        size = s;
        str = new char[size];
        str[0] = '\0';
    }

    // Конструктор з ініціалізацією рядком
    String(const char* input) {
        size = strlen(input) + 1;
        str = new char[size];
        strcpy_s(str, size, input);
    }

    // Конструктор копіювання
    String(const String& other) {
        size = other.size;
        str = new char[size];
        strcpy_s(str, size, other.str);
    }

    // Деструктор
    ~String() {
        delete[] str;
    }

    // Ввід рядка
    void Input() {
        cout << "Введіть рядок: ";
        cin.getline(str, size);
    }

    // Вивід рядка
    void Output() const {
        cout << "Рядок: " << str << endl;
    }
};

// ===== Клас Array =====
class Array {
private:
    int* data;
    int size;

public:
    // Конструктор за замовчуванням
    Array() {
        size = 10;
        data = new int[size] {};
    }

    // Конструктор з розміром
    Array(int s) {
        size = s;
        data = new int[size] {};
    }

    // Конструктор копіювання
    Array(const Array& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Заповнення масиву
    void Fill() {
        cout << "Введіть " << size << " елементів: ";
        for (int i = 0; i < size; i++)
            cin >> data[i];
    }

    // Виведення масиву
    void Print() const {
        cout << "Масив: ";
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    // Зміна розміру масиву
    void Resize(int newSize) {
        int* newData = new int[newSize] {};
        for (int i = 0; i < (newSize < size ? newSize : size); i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        size = newSize;
    }

    // Сортування (просте)
    void Sort() {
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (data[i] > data[j])
                    swap(data[i], data[j]);
    }

    // Мінімальне значення
    int Min() const {
        int min = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] < min) min = data[i];
        return min;
    }

    // Максимальне значення
    int Max() const {
        int max = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] > max) max = data[i];
        return max;
    }
};

// ===== Головна функція =====
int main() {
    cout << "--- Робота з класом String ---" << endl;
    String s1;
    s1.Input();
    s1.Output();

    String s2("Привіт, світе!");
    s2.Output();

    String s3(s2); // копія
    s3.Output();

    cout << "\n--- Робота з класом Array ---" << endl;
    Array a1(5);
    a1.Fill();
    a1.Print();

    cout << "Мінімум: " << a1.Min() << ", Максимум: " << a1.Max() << endl;

    cout << "Сортування..." << endl;
    a1.Sort();
    a1.Print();

    cout << "Зміна розміру до 7..." << endl;
    a1.Resize(7);
    a1.Fill();
    a1.Print();

    return 0;
}