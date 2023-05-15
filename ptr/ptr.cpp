/*Передавая указатель на массив в int* arr, мы  передаем его по значению т.е. 
создается новый указатель, в который присваивается адрес массива. По-этому arr из параметров функции и 
arr из main- совершенно разные указатели, указывающие на один и тот же массив. Изменить этот массив 
можно как из функции, так и из main. Но изменение адреса указателя(arr) в функции никак не повлияет 
на указатель(arr) из main.

Передавая указатель на массив в int*& arr, мы передаем его(указатель) по ссылке т.е. 
arr из функции- ссылка на arr(указатель) из main. Это значит, что все изменения с arr
из функции отразятся на arr из main. Значит, ссылка на указатель(int *&) позволяет передать 
указатель в функцию не по значению,  а по ссылке. Это в свою очередь позволяет производить изменения
напрямую с arr из main (как с данными так и с самим указателем (допустим, присвоить указателю новый 
массив))

 */
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
void insert1(int*& arr, int& size, int index, const int value) {
    int* new_arr = new int[index + 1];

    for (int i = 0; i < index; i++) {
    new_arr[i] = arr[i];
    new_arr[index] = value;
}

    for (int i = index + 1; i < size + 1; i++) {
        new_arr[i] = arr[i - 1];

        size++;
    }

    delete[] arr;
    arr = new_arr;
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