#include <algorithm>
#include <iostream>
#include <vector>
#include "Circle.h"
#include "Triangle.h"
using namespace std;

/*Функционал системы:
-Хранение множества фигур
-Динамическое добавление фигур пользователем. (через консоль)
-Отобразить все фигуры.
-Суммарная площадь всех фигур.
-Суммарный периметр всех фигур.
-Центр масс всей системы.
-Память, занимаемая всеми экземплярами классов.
-Сортировка фигур между собой по массе. */

enum Commands //перечисление команд
{
    ADD = 1,
    SHOW_ALL =2,
    SUM_PERIMETERS=3,
    SUM_AREAS=4,
    CENTRE_MASS=5,
    MEMORY=6,
    SORT=7,
    EXIT=8
};
enum Figure  //перечисление фигур
{
    CIRCLE = 1,
    TRIANGLE = 2,
};

double x, y, sumP, sumS, massAll;

int main() {
    cout<<"let's start! I've prepared a lot of intresting things in this lab"<<endl<<"(I really hope that it' right)";
    vector<IFigure*> system;
    int command;
    CVector2D centerMass;
    while(true) {
        cout << "1. Add figure " << endl;
        cout << "2. Show all figures" << endl;
        cout << "3. Sum all perimeters" << endl;
        cout << "4. Sum all areas" << endl;
        cout << "5. System weight center" << endl;
        cout << "6. Show figures memory" << endl;
        cout << "7. Sort" << endl;
        cout << "8. Exit" << endl;
        cout << "Add command: ";
        cin >> command; //необходимо ввести цифру, которая соответстует желаемой команде
        cout << endl;
        switch (command) { //если команда соответствует
            case ADD:
                cout << "\t1. Circle" << endl;
                cout << "\t2. Triangle" << endl;
                cout << "\tAdd command: ";
                cin >> command;
                cout << endl;
                    switch (command) //выбираем команду, если комада =... то
                   {
                       case CIRCLE:
                        system.push_back(new Circle()); //добавляем новый круг, добавляем для него память
                        break;
                       case TRIANGLE:
                        system.push_back(new Triangle()); //добавляем новй треугольник, добавляем  для него память
                        break;
                      default: //если выбирают не одну из выбрранный фгур, то по дефолту
                        cout << "\tFigure not found" << endl;
                        break;
                   }
                break;
                    //auto& figure : system) - направляет на использование наших фигур (используя адрес)
            case SHOW_ALL:
                for (auto& figure : system)
                    figure->draw(); //отображение фигуры
                break;
            case SUM_PERIMETERS:
                sumP = 0;
                for (auto& figure : system)
                    sumP += figure->perimeter(); //приметр
                cout << "Perimeter system: " << sumP << endl;
                cout << endl;
                break;
            case SUM_AREAS:
                sumS = 0;
                for (auto& figure : system)
                    sumS += figure->square(); //площадь
                cout <<"Area system: " << sumS << endl;
                cout << endl;
                break;
            case CENTRE_MASS:
                massAll = 0;
                x = 0;
                y = 0;
                for (auto& figure : system) {
                    x += figure->position().x * figure->mass();
                    y += figure->position().y * figure->mass();
                    massAll += figure->mass();
                }
                centerMass.x = x / massAll;
                centerMass.y = y / massAll;
                cout << "Center weight coords: " << centerMass << endl;
                cout << endl;
                break;
            case MEMORY:
                cout << "Figures memory: ";
                for (auto& figure : system)
                    cout << figure->size() << " "; //размер, занимаемый в памяти
                cout << endl;
                cout << endl;
                break;
            case SORT:
                //воспользуемся встроенным sort
                sort(system.begin(), system.end(), [](IFigure* x, IFigure* y) {return *x < *y; }); //при помощи[ ] перегружаем указатели на фигуры в {}
                cout << "Figures weight: ";

                for (auto& figure : system)
                    cout << figure->mass() << " "; // вывод массы фигуы при помощи  обращения к виртуальной функции
                cout << endl;
                break;

            case EXIT:
                cout<<"That's all, thank u, byeeeeee!";
                return 0;

            default:
                cout << "Command is not found,SORRY. You can try again, good luck:)" << endl;
                break;
        }
    }
}
