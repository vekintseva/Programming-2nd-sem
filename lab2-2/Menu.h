//
// Created by Виктория on 11.02.2022.
//

#pragma once //защита от повторного подключения

class Menu { //класс-пользовательский тип, реализует объектное ориентирование работ
private:
    int number;
public:  //создаем поля,которые будут доступны пользователю из вне
    Menu();
//static method which does not return anything.
//Static method can be called by directly by class name.
    static void ShowMenu(Menu&);
    static void MenuCase(Menu&, int);
};
