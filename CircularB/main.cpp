#include <iostream>
#include "exception.h"
#include <algorithm>
#include "CB.h"
using namespace std;
/*

int main() {
    const int size = 5;

    try {
        buffer<int> buf(size);

        buf.push_front(1);
        buf.push_front(5);
        buf.push_back(-7);
        buf.push_front(0);
        buf.push_front(-8);

        cout << "Unsorted buffer: " << endl;
        buf.print();

        sort(buf.begin(), buf.end());

        cout << "Sorted buffer: " << endl;
        buf.print();

    } catch (Exception & exception) {
        cout << exception.what() << endl;
        return 1;
    }

}
*/
int main() {

    buffer<int> buf(2);

    buf.addLast(4);
    buf.addLast(1);
    buf.addLast(6);
    buf.addLast(7);
    for (int Iterator: buf) {  //тк мощность буфера = 2, то попадут только 2 последних введенных значения
        cout << Iterator << " ";
    }
    cout << endl;
    buf.removeLast(); //удаление последнего элемента
    buf.removeLast();

    buf.addFirst(2);
    buf.addFirst(5);
    buf.resize(5);
    buf.print(); //должен вывести элемент, который остался в буфере с прошлой мощностью

    buf.addLast(3);
    buf.addLast(14);
    buf.addLast(52);
    buf.addLast(80);
    buf.print();

    buf.resize(4);
    buf.addLast(12);
    buf.print();

    buf.addFirst(145);
    buf.print();

    cout << count(buf.begin(), buf.end(), 5) << endl; //Подсчет элементов = 5


    buffer<int> buffer(3);
    buffer.addLast(44);
    buffer.addLast(33);
    buffer.addLast(22);
    buffer.addLast(11);
    sort(buffer.begin(), buffer.end());
    cout<<"sorted:"<<endl;
    buffer.print();
    buffer.removeFirst();
    buffer.print();

    return 0;
}