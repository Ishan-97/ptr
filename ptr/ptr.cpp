// ptr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
void FillArr(int* const arr,const int size) {

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}


void ShowArr(const int* const arr, const int size) {

    for (size_t i = 0; i < size; i++)
    {
        std::cout<< arr[i]<<"\t";
    }std::cout<< "\n";
}
void push_back(int*& arr, int& size, const int value) {
    int* newArr = new int[size+1];
    for (size_t i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[size++] = value;
    

    delete[]arr;
    arr = newArr;
}
void pop_back(int*& arr, int& size ) {
    size--;
    int* newArr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    delete[]arr;
    arr = newArr;
}
void push_Forward(int*& arr, int& size, const int value) {
    int* newArr = new int[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        newArr[i+1] = arr[i];
    }
    newArr[0] = value;


    delete[]arr;
    arr = newArr;
}
void pop_back(int*& arr, int& size ) {
    size--;
    int* newArr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    delete[]arr;
    arr = newArr;
}

int main()
{
    srand(time(NULL));

    int size = 10;
    int* FirAr = new int[size];
    int* SecAr = new int[size];

    FillArr(FirAr, size);
    FillArr(SecAr, size);

    std::cout << "First array \n";
    ShowArr(FirAr, size);
    std::cout << "Second array \n";
    ShowArr(FirAr, size);

    push_back(FirAr, size, 100);
    for (size_t i = 0; i < size; i++)
    {
         std::cout  << FirAr[i]<< "\t";
    }
   
   

    delete[]FirAr;
    delete[]SecAr;
/*
    int rows = 5;
    int cols = 5;

    int** arr = new int*[rows];

    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    /////////

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {

           arr[i][j]=rand()%200;
           
        }
    }system("cls");

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {

            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }
    

        /////////udalenie massiva
        for (size_t i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        */
        return 0;
    
}
;