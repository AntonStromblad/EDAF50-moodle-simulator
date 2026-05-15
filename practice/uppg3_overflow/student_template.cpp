
/*Kör Tester!! Programmet kommer att krascha med ett nytt ASan-fel: stack-buffer-underflow.
Ditt mål är att läsa felmeddelandet, förstå varför det kraschar, och sedan rätta koden i så att testet passerar och utskriften blir grön.
#include <iostream> */
#include <iostream>

int* createReversedCopy(const int* arr, int size) {
    int* reversed = new int[size];

    for (int i = 0; i <= size; ++i) { 
        reversed[i] = arr[size - 1 - i];
    }

    return reversed;
}