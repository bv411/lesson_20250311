#include <iostream>
#include <stdio.h>


/*

В сети магазинов "Н-Аудио" проводится рекламная акция.
Каждый второй товар – бесплатно.
Естественно, кассирам дано указание пробивать товары в таком порядке,
чтобы магазин потерял как можно меньше денег.
По списку товаров определите максимальную сумму в чеке.

*/

/*
Домашнее задание 

По результатам олимпиады участники награждаются дипломами.
Набравшие одинаковые баллы получают дипломы одинаковой степени.
Призером олимпиады считается участник, получивший диплом не хуже III степени.
По результатам олимпиады определите количество призеров.



*/

void print(int a[], long size) {
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void gen(int a[], long size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 100;
    }    
}

//  Пузырек
void bubbleSort(int a[], long size) {
    
    int count{};
    for (int i = 0; i < size; i++) {
        bool isSwap{};
        
        for (int j = 0; j < size - 1; j++, count++) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                isSwap = true;
            }            
        }   
        //std::cout << i + 1 << " | ";
        //print(a, size);
          if (!isSwap)
            break;
    }
    std::cout << "Count (bubble) = " << count << std::endl;
}

// Вставки
void insertSort(int a[], long size) {
    int  temp;
    int count{};
    for (int i = 0; i < size; i++) {
        temp = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > temp; j--, count++)
            a[j + 1] = a[j];

       /* a[j + 1] = temp;
        std::cout << i + 1 << " | ";
        print(a, size);*/
    }
    std::cout << "Count (insert) = " << count << std::endl;
}


int main() {

    srand(time(NULL));
    const int SIZE = 20;
    int arr[SIZE]{};
    gen(arr, SIZE);
    print(arr, SIZE);

    int arr2[SIZE]{};

    for (int i = 0; i < SIZE; i++)
        arr2[i] = arr[i];

    
    bubbleSort(arr, SIZE);
    insertSort(arr2, SIZE);
    
    print(arr, SIZE);
    /*bubbleSort(arr, SIZE);

    int sum = 0;
    for (int i = 0, j = SIZE - 1; i <= j ; i++, j--) {
                
        std::cout << arr[j] << " ";
        if (i != j)
            std::cout << arr[i] << " ";

        sum += arr[j];

    }
    std::cout << std::endl;
    std::cout <<"Summa = "<< sum << std::endl;
    std::cout << std::endl;*/

    return 0;

    /*std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    bubbleSort(arr, SIZE);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    print(arr, SIZE);

    std::cout << "MIN = " << arr[0] << std::endl;
    std::cout << "MAX = " << arr[SIZE -1] << std::endl;
    
    */return 0;
}





#define PI 3.141592

#define LC(r) (2*PI*(r))

#define SQR(X) ((X) * (X))

#define MKSTR(s) #s

#define concat(a,b) a##b

//#define DEBUG

#define FOR1(it, str) \
for (int i = 0; i < it; i++) {\
    std::cout << str << std::endl; \
}

/*
https://learn.microsoft.com/ru-ru/cpp/preprocessor/predefined-macros?view=msvc-170

https://learn.microsoft.com/ru-ru/dotnet/csharp/language-reference/preprocessor-directives

https://learn.microsoft.com/ru-ru/cpp/preprocessor/pragma-directives-and-the-pragma-keyword?view=msvc-170
*/


/*
#if <константное_выражение>
#ifdef <идентификатор>
#ifndef <идентификатор>
#else
#endif
#elif
*/

void func1sdsdafsdafsdaf() {
#ifdef DEBUG
    std::cout << __FUNCTION__ << std::endl;
    std::cout << __FILE__ << std::endl;
    std::cout << __LINE__ << std::endl;
#endif // DEBUG


}

void func2() {
#ifdef DEBUG
    std::cout << __FUNCTION__ << std::endl;
    std::cout << __FILE__ << std::endl;
    std::cout << __LINE__ << std::endl;
#endif // DEBUG

}

void func3() {
#ifdef DEBUG
    std::cout << __FUNCTION__ << std::endl;
    std::cout << __FILE__ << std::endl;
    std::cout << __LINE__ << std::endl;
#endif // DEBUG

}

int mainVVV() {

    setlocale(LC_ALL, "Ru");

    func1sdsdafsdafsdaf();
    func2();
    func2();
    func3();
    return 0;

    std::cout << " I love \"C++\" " << std::endl;
    std::cout << MKSTR(I like "C++" but i don`t like python) << std::endl;

    int xy = 10;

    std::cout << concat(x, y); // std::cout << xy;

    return 0;

#ifdef PI
    std::cout << PI << std::endl; // std::cout << 3.14 << std::endl;
#endif


    int r = 5;
    double l{};
#ifdef PI
    l = LC(r);
#else
    l = 2 * 3.14 * r;
#endif

    std::cout << l << std::endl;

    FOR1(10, "sdfsdfsdf");

    std::cout << SQR(5+1) << std::endl;

    return 0;

}


