/*#include <iostream>
#include "MaxElement.h"
#include "TArray.h"
#include "Exception.h"
using namespace std;

int main() {
    int N;

    cout << "length of your array: " << endl;
    cin >> N;
    int array[N];
    cout << "Enter N values: " << endl;
    for (int i = 0; i < N; i++) {
       cin >> array[i];
    }
    cout << "Max element is: " << MaxElement(array, N) << endl;


    cout << "Now we will work with integer type" << endl;
    cout << " length of your array: " << endl;
    cin >> N;
    Array<int> arrInt(N); //создание массива на n элементов
    cout << "Array's length: " << arrInt.GetLength() << endl; //длина массива
    cout << "Enter N int values: " << endl;
    arrInt.FillArray();
    int index;
    cout << "Enter an index and I will show the element: " << endl;
    cin >> index;

    try {  //при возникновении исключения обратимся к catch
        cout << arrInt[index] << endl; //что может вызвать исключение
    }
    catch (Exception& exception) { //описано, что делать при встрече с исключением
        cout << "Error: " << exception.what() << endl;
        exit(1);
    }

    cout << "Now we will work with double type" << endl;
    cout << "length of your array: " << endl;
    cin >> N;
    Array<double> arrD(N);
    cout << "Array's length: " << arrD.GetLength() << endl;
    cout << "Enter N double values: " << endl;
    arrD.FillArray();
    cout << "Enter an index and I will show the element: " << endl;
    cin >> index;

    try {
        cout << arrD[index] << endl;

    }
    catch (Exception& exception) {
        cout << "Error: " << exception.what() << endl;
        exit(1);
    }

    cout << "look at your double array: " << endl;
    arrD.ShowArray();
    arrD.DeleteArray(); //"чистим память"


    return 0;
} */

#include <iostream>
#include "MaxElement.h"
#include "TArray.h"
#include "Exception.h"
using namespace std;

int main() {
    int N;

    cout << "length of your array: " << endl;
    cin >> N;
    int array[N];
    cout << "Enter N values: " << endl;
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    cout << "Max element is: " << MaxElement(array, N) << endl;


    cout << "Now we will work with integer type" << endl;
    Array<int,5> arrInt; //создание массива на n элементов
    cout << "Array's length: " << arrInt.GetLength() << endl; //длина массива
    cout << "Enter 5 int values: " << endl;
    arrInt.FillArray();
    int index;
    cout << "Enter an index and I will show the element: " << endl;
    cin >> index;

    try {  //при возникновении исключения обратимся к catch
        cout << arrInt[index] << endl; //что может вызвать исключение
    }
    catch (Exception& exception) { //описано, что делать при встрече с исключением
        cout << "Error: " << exception.what() << endl;
        exit(1);
    }

    cout << "look at your array: " << endl;
    arrInt.ShowArray();
    arrInt.DeleteArray(); //"чистим память"


    return 0;
}