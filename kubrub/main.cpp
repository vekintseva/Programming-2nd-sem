#include <iostream>
#include "CubeRubik.h"

using std::cin, std::cout;
using std::ofstream;

void menu() {
    cout << "\x1b[31m" << "\nМеню:\n" << "\x1b[0m";
    cout << "1) Сделать кубик базовым\n";
    cout << "2) Прочитать развертку кубика из файла\n";
    cout << "3) Вывести развертку кубика в консоль\n";
    cout << "4) Вывести развертку кубика в файл\n";
    cout << "5) Перемешать кубик\n";
    cout << "6) Собрать кубик\n";
    cout << "7) Cобран ли сейчас кубик?\n";
    cout << "8) Сделать повороты вручную\n";
    cout << "9) Корректен ли кубик?\n";
    cout << "0) Завершить программу\n";
    cout << "\x1b[33m" << "\nКоманда: " << "\x1b[0m";
}

void menu_of_rotate() { //меню поворотов
    cout << "\x1b[31m" << "\t\tВарианты поворотов:\n" << "\x1b[0m";
    cout << "1) F\n";
    cout << "2) F'\n";
    cout << "3) R\n";
    cout << "4) R'\n";
    cout << "5) B\n";
    cout << "6) B'\n";
    cout << "7) L\n";
    cout << "8) L'\n";
    cout << "9) U\n";
    cout << "10) U'\n";
    cout << "11) D'\n";
    cout << "12) D'\n";
    cout << "13) Вывести развертку в консоль\n";
    cout << "14) Вывести развертку в файл\n";
    cout << "0) Вернуться в меню\n";
    cout << "\x1b[33m" << "\n\t\tКоманда: " << "\x1b[0m";
}

void doing_rotate(CubeRubik& cube) {
    int cmd;
    while (true) {
        cin >> cmd;
        switch (cmd) {
            case 0:
                return;
            case 1:
                cube.rotate_front(' ');
                break;
            case 2:
                cube.rotate_front('\'');
                break;
            case 3:
                cube.rotate_right(' ');
                break;
            case 4:
                cube.rotate_right('\'');
                break;
            case 5:
                cube.rotate_back(' ');
                break;
            case 6:
                cube.rotate_back('\'');
                break;
            case 7:
                cube.rotate_left(' ');
                break;
            case 8:
                cube.rotate_left('\'');
                break;
            case 9:
                cube.rotate_up(' ');
                break;
            case 10:
                cube.rotate_up('\'');
                break;
            case 11:
                cube.rotate_down(' ');
                break;
            case 12:
                cube.rotate_down('\'');
                break;
            case 13:
                cube.print_cube();
                break;
            case 14:
                cube.print_cube_in_file();
                break;
            default:
                cout << "Введи норм команду\n";
                break;
        }
    }
}

void robot(CubeRubik& cube) {
    int cmd;

    while (true) {
        menu();
        cin >> cmd;
        cout << "\x1b[32m" << "Ответ...\n" << "\x1b[0m";
        switch (cmd) {
            case 0:
                return;
            case 1:
                cube.create_cube_rubik();
                break;
            case 2:
                cube.read_cube_from_file("input.txt");
                break;
            case 3:
                cube.print_cube();
                break;
            case 4:
                cube.print_cube_in_file();
                break;
            case 5:
                if (!cube.is_correct()) {
                    cout << "\nВаш кубик некорректен, и, к сожалению, мы вынуждены сбросить его до заводских настроек, и только после этого перемешать\n\n";
                    cube.create_cube_rubik();
                }
                cube.shuffle_cube();
                break;
            case 6:
                if (cube.is_correct()) {
                    cube.build_with_steps();
                    cout << "\x1b[32m" << "Кубик Рубика собран\n\n" << "\x1b[0m";
                }
                else {
                    cout << "Кубик нереально собрать, он у вас какой-то не такой\n";
                    cout << "Но мы починили, теперь как новенький (базовый/собранный)\n";
                    cube.create_cube_rubik();
                }
                break;
            case 7:
                cout << (cube.is_cube_done() ? "Yes\n" : "No\n");
                break;
            case 8:
                menu_of_rotate();
                doing_rotate(cube);
                break;
            case 9:
                cout << (cube.is_correct() ? "Yes\n" : "No\n");
                break;
            default:
                cout << "Введи норм команду\n";
                break;
        }
    }
}

int main() {

    CubeRubik cube;
    robot(cube);

    return 0;
}

