#include <iostream> // Підключення бібліотеки для вводу-виводу
#include <ctime>    // Підключення бібліотеки для роботи з часом
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //ЗАДАНИЕ 1
    //    В одномерном массиве, заполненном случайными числами,
    //    определить минимальный и максимальный элементы.

   
    const int size = 5;  
    int arr[size], min, max;

    srand(static_cast<unsigned int>(time(0))); 
    cout << " Масив: ";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Заповнення масиву випадковими числами (0-99)
        cout << arr[i] << " ";
    }
    cout << endl;

    min = arr[0]; // Початкове припущення для мінімального значення
    max = arr[0]; // Початкове припущення для максимального значення

    // Пошук мінімального та максимального елементів
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    cout << " Мінімальний елемент: " << min << endl;
    cout << " Максимальний елемент: " << max << endl;


    //ЗАДАНИЕ 2
    //    В одномерном массиве, заполненном случайными числами
    //    в заданном пользователем диапазоне, найти сумму элементов,
    //    значения которых меньше указанного пользователем.

    int threshold , sum = 0;

    cout << "\nВведіть число діапазону, для знаходження суми елементів менших за нього: ";
    cin >> threshold;

    
    for (int i = 0; i < size; i++) {
        if (arr[i] < threshold) sum += arr[i];
    }

    cout << "Сума елементів менше " << threshold << ": " << sum << endl;



    /*ЗАДАНИЕ 3
        Пользователь вводит прибыль фирмы за год(12 месяцев).
        Затем пользователь вводит диапазон(например, 3 и 6 — поиск
            между 3 - м и 6 - м месяцем).Необходимо определить месяц,
        в котором прибыль была максимальна и месяц, в котором
        прибыль была минимальна с учетом выбранного диапазона.*/

    const int months = 12;  
    int profit[months];    // масив для прибутку

    // Введення прибутку за 6 місяців
    cout << "\n Введіть прибуток за 12 місяців: \n";

    for (int i = 0; i < months; i++) 
    {
        cout << " Місяць "<<i+1<<": ";
        cin >> profit[i];
    }

    int start, end;
    cout << " Введіть діапазон місяців (наприклад, 3 5): ";
    cin >> start >> end;

    int minMonth = start, maxMonth = start;
    int minValue = profit[start - 1], maxValue = profit[start - 1];

    // Пошук місяців з мінімальним та максимальним прибутком у заданому діапазоні
    for (int i = start; i <= end; i++)
    {
        if (profit[i - 1] < minValue)
        {
            minValue = profit[i - 1];
            minMonth = i;
        }
        if (profit[i - 1] > maxValue) 
        {
            maxValue = profit[i - 1];
            maxMonth = i;
        }
    }

   
    cout << " Максимальний прибуток у місяці: " << maxMonth << " (" << maxValue << ")" << endl;
    cout << " Мінімальний прибуток у місяці: " << minMonth << " (" << minValue << ")" << endl;


  /*  ЗАДАНИЕ 4
        В одномерном массиве, состоящем из N вещественных
        чисел вычислить :
    ■ Сумму отрицательных элементов.
        ■ Произведение элементов, находящихся между min и max
        элементами.
        ■ Произведение элементов с четными номерами.
        ■ Сумму элементов, находящихся между первым и последним отрицательными элементами.*/
   
const int sizes = 5;
double arrD[sizes], negativeSum = 0, productBetweenMinMax = 1, productEven = 1, sumBetweenNegatives = 0;
int minIndex = 0, maxIndex = 0, firstNegative = -1, lastNegative = -1;

srand(time(0));

cout << "\n Масив дійсних чисел: ";
for (int i = 0; i < sizes; i++) {
    arrD[i] = (rand() % 200 - 100) / 10.0; // Випадкові числа від -10.0 до 9.9
    cout << arrD[i] << " ";

    if (arrD[i] < 0) negativeSum += arrD[i]; // Підрахунок суми від'ємних чисел
    if (i % 2 == 0) productEven *= arrD[i]; // Підрахунок добутку парних елементів

    if (arrD[i] < arrD[minIndex]) minIndex = i;
    if (arrD[i] > arrD[maxIndex]) maxIndex = i;

    if (arrD[i] < 0) {
        if (firstNegative == -1) firstNegative = i;
        lastNegative = i;
    }
}
cout << endl;


int start = min(minIndex, maxIndex) + 1, end = max(minIndex, maxIndex);
if (start < end) {
    for (int i = start; i < end; i++) productBetweenMinMax *= arrD[i];
}
else {
    productBetweenMinMax = 0;
}


if (firstNegative != -1 && lastNegative != -1 && firstNegative != lastNegative) {
    for (int i = firstNegative + 1; i < lastNegative; i++) sumBetweenNegatives += arrD[i];
}
else {
    sumBetweenNegatives = 0;
}


cout << " Сума від'ємних елементів: " << negativeSum << endl;
cout << " Добуток елементів між min і max: " << productBetweenMinMax << endl;
cout << " Добуток елементів із парними номерами: " << productEven << endl;
cout << " Сума елементів між першим і останнім від'ємними: " << sumBetweenNegatives << endl;

    return 0;
}