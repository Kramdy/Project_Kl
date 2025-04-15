#include <iostream>
#include <cstring>
using namespace std;

// ===== ���� String =====
class String {
private:
    char* str;
    int size;

public:
    // ����������� �� �������������
    String() {
        size = 80;
        str = new char[size];
        str[0] = '\0';
    }

    // ����������� � �������
    String(int s) {
        size = s;
        str = new char[size];
        str[0] = '\0';
    }

    // ����������� � ������������ ������
    String(const char* input) {
        size = strlen(input) + 1;
        str = new char[size];
        strcpy_s(str, size, input);
    }

    // ����������� ���������
    String(const String& other) {
        size = other.size;
        str = new char[size];
        strcpy_s(str, size, other.str);
    }

    // ����������
    ~String() {
        delete[] str;
    }

    // ��� �����
    void Input() {
        cout << "������ �����: ";
        cin.getline(str, size);
    }

    // ���� �����
    void Output() const {
        cout << "�����: " << str << endl;
    }
};

// ===== ���� Array =====
class Array {
private:
    int* data;
    int size;

public:
    // ����������� �� �������������
    Array() {
        size = 10;
        data = new int[size] {};
    }

    // ����������� � �������
    Array(int s) {
        size = s;
        data = new int[size] {};
    }

    // ����������� ���������
    Array(const Array& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    // ����������
    ~Array() {
        delete[] data;
    }

    // ���������� ������
    void Fill() {
        cout << "������ " << size << " ��������: ";
        for (int i = 0; i < size; i++)
            cin >> data[i];
    }

    // ��������� ������
    void Print() const {
        cout << "�����: ";
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    // ���� ������ ������
    void Resize(int newSize) {
        int* newData = new int[newSize] {};
        for (int i = 0; i < (newSize < size ? newSize : size); i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        size = newSize;
    }

    // ���������� (������)
    void Sort() {
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (data[i] > data[j])
                    swap(data[i], data[j]);
    }

    // ̳������� ��������
    int Min() const {
        int min = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] < min) min = data[i];
        return min;
    }

    // ����������� ��������
    int Max() const {
        int max = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] > max) max = data[i];
        return max;
    }
};

// ===== ������� ������� =====
int main() {
    cout << "--- ������ � ������ String ---" << endl;
    String s1;
    s1.Input();
    s1.Output();

    String s2("�����, ����!");
    s2.Output();

    String s3(s2); // ����
    s3.Output();

    cout << "\n--- ������ � ������ Array ---" << endl;
    Array a1(5);
    a1.Fill();
    a1.Print();

    cout << "̳����: " << a1.Min() << ", ��������: " << a1.Max() << endl;

    cout << "����������..." << endl;
    a1.Sort();
    a1.Print();

    cout << "���� ������ �� 7..." << endl;
    a1.Resize(7);
    a1.Fill();
    a1.Print();

    return 0;
}