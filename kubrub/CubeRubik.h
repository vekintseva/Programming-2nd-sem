//
// Created by Виктория on 25.05.2022.
//



#include <iostream>
#include <fstream>
#include <vector>
#include "SmallCube.h"

using std::cin, std::cout, std::ifstream, std::ofstream;
using std::vector;
using std::setw, std::endl;

ofstream fout("output.txt");

#define right_center arr[1][2][1].get_cubik_right_plane()
#define left_center arr[1][0][1].get_cubik_left_plane()
#define up_center arr[1][1][2].get_cubik_up_plane()
#define down_center arr[1][1][0].get_cubik_down_plane()
#define front_center arr[2][1][1].get_cubik_front_plane()
#define back_center arr[0][1][1].get_cubik_back_plane()


class CubeRubik {
private:
    // Куб в виде трёхмерного вектора ( Координаты (1, 1, 1) имеет центральный кубик,
    // координаты (0, 0, 0) имеет левый нижний задний кубик, координаты (2, 2, 2) имеет правый верхний передний кубик)
    vector<vector<vector<SmallCube>>> arr;
    string steps = "";


    int count_of_turns_1_step = 0;
    int count_of_turns_2_step = 0;
    int count_of_turns_3_step = 0;
    int count_of_turns_5_step = 0;
    int count_of_turns_6_step = 0;


public:

    // Конструктор
    CubeRubik()
    {
        arr.resize(3, vector<vector<SmallCube>>(3, vector<SmallCube>(3)));
        for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 3; ++y)
                for (SmallCube &el: arr[x][y])
                    el = SmallCube();
        create_cube_rubik();
    }

    // Операторы
    CubeRubik& operator=(const CubeRubik& cube) {
        count_of_turns_1_step = cube.count_of_turns_1_step;
        count_of_turns_2_step = cube.count_of_turns_2_step;
        count_of_turns_3_step = cube.count_of_turns_3_step;
        count_of_turns_5_step = cube.count_of_turns_5_step;
        count_of_turns_6_step = cube.count_of_turns_6_step;
        steps = cube.steps;
        arr = cube.arr;

        return *this;
    }

    // Обнуление всех счетчиков
    void start_pos() {
        steps = "";
        count_of_turns_1_step = 0;
        count_of_turns_2_step = 0;
        count_of_turns_3_step = 0;
        count_of_turns_5_step = 0;
        count_of_turns_6_step = 0;
    }


    // Функция для раскраски граней изначальными цветами
    void create_cube_rubik()
    {
        arr[1][1][1] = SmallCube();
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[i][j][2].set_cubik_up_plane("Y");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[i][j][0].set_cubik_down_plane("W");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[i][0][j].set_cubik_left_plane("O");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[i][2][j].set_cubik_right_plane("R");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[2][i][j].set_cubik_front_plane("G");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[0][i][j].set_cubik_back_plane("B");

        steps = "";
    }

    void rotate_up(char direction)
    {
        string left_color_0 = arr[0][0][2].get_cubik_left_plane();
        string left_color_1 = arr[1][0][2].get_cubik_left_plane();
        string left_color_2 = arr[2][0][2].get_cubik_left_plane();

        string front_color_0 = arr[2][0][2].get_cubik_front_plane();
        string front_color_1 = arr[2][1][2].get_cubik_front_plane();
        string front_color_2 = arr[2][2][2].get_cubik_front_plane();

        string right_color_0 = arr[2][2][2].get_cubik_right_plane();
        string right_color_1 = arr[1][2][2].get_cubik_right_plane();
        string right_color_2 = arr[0][2][2].get_cubik_right_plane();

        string back_color_0 = arr[0][2][2].get_cubik_back_plane();
        string back_color_1 = arr[0][1][2].get_cubik_back_plane();
        string back_color_2 = arr[0][0][2].get_cubik_back_plane();

        string up_color_0_0 = arr[0][0][2].get_cubik_up_plane();
        string up_color_0_1 = arr[0][1][2].get_cubik_up_plane();
        string up_color_0_2 = arr[0][2][2].get_cubik_up_plane();
        string up_color_1_0 = arr[1][0][2].get_cubik_up_plane();
        string up_color_1_2 = arr[1][2][2].get_cubik_up_plane();
        string up_color_2_0 = arr[2][0][2].get_cubik_up_plane();
        string up_color_2_1 = arr[2][1][2].get_cubik_up_plane();
        string up_color_2_2 = arr[2][2][2].get_cubik_up_plane();

        if (direction == '\'')
        {
            arr[0][0][2].set_cubik_up_plane(up_color_0_2);
            arr[0][1][2].set_cubik_up_plane(up_color_1_2);
            arr[0][2][2].set_cubik_up_plane(up_color_2_2);
            arr[1][0][2].set_cubik_up_plane(up_color_0_1);
            arr[1][2][2].set_cubik_up_plane(up_color_2_1);
            arr[2][0][2].set_cubik_up_plane(up_color_0_0);
            arr[2][1][2].set_cubik_up_plane(up_color_1_0);
            arr[2][2][2].set_cubik_up_plane(up_color_2_0);

            arr[0][0][2].set_cubik_left_plane(back_color_0);
            arr[1][0][2].set_cubik_left_plane(back_color_1);
            arr[2][0][2].set_cubik_left_plane(back_color_2);

            arr[2][0][2].set_cubik_front_plane(left_color_0);
            arr[2][1][2].set_cubik_front_plane(left_color_1);
            arr[2][2][2].set_cubik_front_plane(left_color_2);

            arr[2][2][2].set_cubik_right_plane(front_color_0);
            arr[1][2][2].set_cubik_right_plane(front_color_1);
            arr[0][2][2].set_cubik_right_plane(front_color_2);

            arr[0][2][2].set_cubik_back_plane(right_color_0);
            arr[0][1][2].set_cubik_back_plane(right_color_1);
            arr[0][0][2].set_cubik_back_plane(right_color_2);
        }
        else
        {
            arr[0][0][2].set_cubik_up_plane(up_color_2_0);
            arr[0][1][2].set_cubik_up_plane(up_color_1_0);
            arr[0][2][2].set_cubik_up_plane(up_color_0_0);
            arr[1][0][2].set_cubik_up_plane(up_color_2_1);
            arr[1][2][2].set_cubik_up_plane(up_color_0_1);
            arr[2][0][2].set_cubik_up_plane(up_color_2_2);
            arr[2][1][2].set_cubik_up_plane(up_color_1_2);
            arr[2][2][2].set_cubik_up_plane(up_color_0_2);

            arr[0][0][2].set_cubik_left_plane(front_color_0);
            arr[1][0][2].set_cubik_left_plane(front_color_1);
            arr[2][0][2].set_cubik_left_plane(front_color_2);

            arr[2][0][2].set_cubik_front_plane(right_color_0);
            arr[2][1][2].set_cubik_front_plane(right_color_1);
            arr[2][2][2].set_cubik_front_plane(right_color_2);

            arr[2][2][2].set_cubik_right_plane(back_color_0);
            arr[1][2][2].set_cubik_right_plane(back_color_1);
            arr[0][2][2].set_cubik_right_plane(back_color_2);

            arr[0][2][2].set_cubik_back_plane(left_color_0);
            arr[0][1][2].set_cubik_back_plane(left_color_1);
            arr[0][0][2].set_cubik_back_plane(left_color_2);
        }
    }

    void rotate_down(char direction)
    {
        string left_color_0 = arr[0][0][0].get_cubik_left_plane();
        string left_color_1 = arr[1][0][0].get_cubik_left_plane();
        string left_color_2 = arr[2][0][0].get_cubik_left_plane();

        string front_color_0 = arr[2][0][0].get_cubik_front_plane();
        string front_color_1 = arr[2][1][0].get_cubik_front_plane();
        string front_color_2 = arr[2][2][0].get_cubik_front_plane();

        string right_color_0 = arr[2][2][0].get_cubik_right_plane();
        string right_color_1 = arr[1][2][0].get_cubik_right_plane();
        string right_color_2 = arr[0][2][0].get_cubik_right_plane();

        string back_color_0 = arr[0][2][0].get_cubik_back_plane();
        string back_color_1 = arr[0][1][0].get_cubik_back_plane();
        string back_color_2 = arr[0][0][0].get_cubik_back_plane();

        string down_color_0_0 = arr[0][0][0].get_cubik_down_plane();
        string down_color_0_1 = arr[0][1][0].get_cubik_down_plane();
        string down_color_0_2 = arr[0][2][0].get_cubik_down_plane();
        string down_color_1_0 = arr[1][0][0].get_cubik_down_plane();
        string down_color_1_2 = arr[1][2][0].get_cubik_down_plane();
        string down_color_2_0 = arr[2][0][0].get_cubik_down_plane();
        string down_color_2_1 = arr[2][1][0].get_cubik_down_plane();
        string down_color_2_2 = arr[2][2][0].get_cubik_down_plane();

        if (direction == '\'')
        {
            arr[0][0][0].set_cubik_down_plane(down_color_2_0);
            arr[0][1][0].set_cubik_down_plane(down_color_1_0);
            arr[0][2][0].set_cubik_down_plane(down_color_0_0);
            arr[1][0][0].set_cubik_down_plane(down_color_2_1);
            arr[1][2][0].set_cubik_down_plane(down_color_0_1);
            arr[2][0][0].set_cubik_down_plane(down_color_2_2);
            arr[2][1][0].set_cubik_down_plane(down_color_1_2);
            arr[2][2][0].set_cubik_down_plane(down_color_0_2);

            arr[0][0][0].set_cubik_left_plane(front_color_0);
            arr[1][0][0].set_cubik_left_plane(front_color_1);
            arr[2][0][0].set_cubik_left_plane(front_color_2);

            arr[2][0][0].set_cubik_front_plane(right_color_0);
            arr[2][1][0].set_cubik_front_plane(right_color_1);
            arr[2][2][0].set_cubik_front_plane(right_color_2);

            arr[2][2][0].set_cubik_right_plane(back_color_0);
            arr[1][2][0].set_cubik_right_plane(back_color_1);
            arr[0][2][0].set_cubik_right_plane(back_color_2);

            arr[0][2][0].set_cubik_back_plane(left_color_0);
            arr[0][1][0].set_cubik_back_plane(left_color_1);
            arr[0][0][0].set_cubik_back_plane(left_color_2);
        }
        else
        {
            arr[0][0][0].set_cubik_down_plane(down_color_0_2);
            arr[0][1][0].set_cubik_down_plane(down_color_1_2);
            arr[0][2][0].set_cubik_down_plane(down_color_2_2);
            arr[1][0][0].set_cubik_down_plane(down_color_0_1);
            arr[1][2][0].set_cubik_down_plane(down_color_2_1);
            arr[2][0][0].set_cubik_down_plane(down_color_0_0);
            arr[2][1][0].set_cubik_down_plane(down_color_1_0);
            arr[2][2][0].set_cubik_down_plane(down_color_2_0);

            arr[0][0][0].set_cubik_left_plane(back_color_0);
            arr[1][0][0].set_cubik_left_plane(back_color_1);
            arr[2][0][0].set_cubik_left_plane(back_color_2);

            arr[2][0][0].set_cubik_front_plane(left_color_0);
            arr[2][1][0].set_cubik_front_plane(left_color_1);
            arr[2][2][0].set_cubik_front_plane(left_color_2);

            arr[2][2][0].set_cubik_right_plane(front_color_0);
            arr[1][2][0].set_cubik_right_plane(front_color_1);
            arr[0][2][0].set_cubik_right_plane(front_color_2);

            arr[0][2][0].set_cubik_back_plane(right_color_0);
            arr[0][1][0].set_cubik_back_plane(right_color_1);
            arr[0][0][0].set_cubik_back_plane(right_color_2);
        }
    }

    void rotate_left(char direction)
    {
        string up_color_0 = arr[0][0][2].get_cubik_up_plane();
        string up_color_1 = arr[1][0][2].get_cubik_up_plane();
        string up_color_2 = arr[2][0][2].get_cubik_up_plane();

        string front_color_0 = arr[2][0][2].get_cubik_front_plane();
        string front_color_1 = arr[2][0][1].get_cubik_front_plane();
        string front_color_2 = arr[2][0][0].get_cubik_front_plane();

        string down_color_0 = arr[2][0][0].get_cubik_down_plane();
        string down_color_1 = arr[1][0][0].get_cubik_down_plane();
        string down_color_2 = arr[0][0][0].get_cubik_down_plane();

        string back_color_0 = arr[0][0][0].get_cubik_back_plane();
        string back_color_1 = arr[0][0][1].get_cubik_back_plane();
        string back_color_2 = arr[0][0][2].get_cubik_back_plane();

        string left_color_0_0 = arr[0][0][0].get_cubik_left_plane();
        string left_color_0_1 = arr[0][0][1].get_cubik_left_plane();
        string left_color_0_2 = arr[0][0][2].get_cubik_left_plane();
        string left_color_1_0 = arr[1][0][0].get_cubik_left_plane();
        string left_color_1_2 = arr[1][0][2].get_cubik_left_plane();
        string left_color_2_0 = arr[2][0][0].get_cubik_left_plane();
        string left_color_2_1 = arr[2][0][1].get_cubik_left_plane();
        string left_color_2_2 = arr[2][0][2].get_cubik_left_plane();

        if (direction == '\'')
        {
            arr[0][0][0].set_cubik_left_plane(left_color_0_2);
            arr[0][0][1].set_cubik_left_plane(left_color_1_2);
            arr[0][0][2].set_cubik_left_plane(left_color_2_2);
            arr[1][0][0].set_cubik_left_plane(left_color_0_1);
            arr[1][0][2].set_cubik_left_plane(left_color_2_1);
            arr[2][0][0].set_cubik_left_plane(left_color_0_0);
            arr[2][0][1].set_cubik_left_plane(left_color_1_0);
            arr[2][0][2].set_cubik_left_plane(left_color_2_0);

            arr[0][0][2].set_cubik_up_plane(front_color_0);
            arr[1][0][2].set_cubik_up_plane(front_color_1);
            arr[2][0][2].set_cubik_up_plane(front_color_2);

            arr[2][0][2].set_cubik_front_plane(down_color_0);
            arr[2][0][1].set_cubik_front_plane(down_color_1);
            arr[2][0][0].set_cubik_front_plane(down_color_2);

            arr[2][0][0].set_cubik_down_plane(back_color_0);
            arr[1][0][0].set_cubik_down_plane(back_color_1);
            arr[0][0][0].set_cubik_down_plane(back_color_2);

            arr[0][0][0].set_cubik_back_plane(up_color_0);
            arr[0][0][1].set_cubik_back_plane(up_color_1);
            arr[0][0][2].set_cubik_back_plane(up_color_2);
        }
        else
        {
            arr[0][0][0].set_cubik_left_plane(left_color_2_0);
            arr[0][0][1].set_cubik_left_plane(left_color_1_0);
            arr[0][0][2].set_cubik_left_plane(left_color_0_0);
            arr[1][0][0].set_cubik_left_plane(left_color_2_1);
            arr[1][0][2].set_cubik_left_plane(left_color_0_1);
            arr[2][0][0].set_cubik_left_plane(left_color_2_2);
            arr[2][0][1].set_cubik_left_plane(left_color_1_2);
            arr[2][0][2].set_cubik_left_plane(left_color_0_2);

            arr[0][0][2].set_cubik_up_plane(back_color_0);
            arr[1][0][2].set_cubik_up_plane(back_color_1);
            arr[2][0][2].set_cubik_up_plane(back_color_2);

            arr[2][0][2].set_cubik_front_plane(up_color_0);
            arr[2][0][1].set_cubik_front_plane(up_color_1);
            arr[2][0][0].set_cubik_front_plane(up_color_2);

            arr[2][0][0].set_cubik_down_plane(front_color_0);
            arr[1][0][0].set_cubik_down_plane(front_color_1);
            arr[0][0][0].set_cubik_down_plane(front_color_2);

            arr[0][0][0].set_cubik_back_plane(down_color_0);
            arr[0][0][1].set_cubik_back_plane(down_color_1);
            arr[0][0][2].set_cubik_back_plane(down_color_2);
        }
    }

    void rotate_right(char direction)
    {
        string up_color_0 = arr[0][2][2].get_cubik_up_plane();
        string up_color_1 = arr[1][2][2].get_cubik_up_plane();
        string up_color_2 = arr[2][2][2].get_cubik_up_plane();

        string front_color_0 = arr[2][2][2].get_cubik_front_plane();
        string front_color_1 = arr[2][2][1].get_cubik_front_plane();
        string front_color_2 = arr[2][2][0].get_cubik_front_plane();

        string down_color_0 = arr[2][2][0].get_cubik_down_plane();
        string down_color_1 = arr[1][2][0].get_cubik_down_plane();
        string down_color_2 = arr[0][2][0].get_cubik_down_plane();

        string back_color_0 = arr[0][2][0].get_cubik_back_plane();
        string back_color_1 = arr[0][2][1].get_cubik_back_plane();
        string back_color_2 = arr[0][2][2].get_cubik_back_plane();

        string right_color_0_0 = arr[0][2][2].get_cubik_right_plane();
        string right_color_0_1 = arr[0][2][1].get_cubik_right_plane();
        string right_color_0_2 = arr[0][2][0].get_cubik_right_plane();
        string right_color_1_0 = arr[1][2][2].get_cubik_right_plane();
        string right_color_1_2 = arr[1][2][0].get_cubik_right_plane();
        string right_color_2_0 = arr[2][2][2].get_cubik_right_plane();
        string right_color_2_1 = arr[2][2][1].get_cubik_right_plane();
        string right_color_2_2 = arr[2][2][0].get_cubik_right_plane();

        if (direction == '\'')
        {
            arr[0][2][2].set_cubik_right_plane(right_color_0_2);
            arr[0][2][1].set_cubik_right_plane(right_color_1_2);
            arr[0][2][0].set_cubik_right_plane(right_color_2_2);
            arr[1][2][2].set_cubik_right_plane(right_color_0_1);
            arr[1][2][0].set_cubik_right_plane(right_color_2_1);
            arr[2][2][2].set_cubik_right_plane(right_color_0_0);
            arr[2][2][1].set_cubik_right_plane(right_color_1_0);
            arr[2][2][0].set_cubik_right_plane(right_color_2_0);

            arr[0][2][2].set_cubik_up_plane(back_color_0);
            arr[1][2][2].set_cubik_up_plane(back_color_1);
            arr[2][2][2].set_cubik_up_plane(back_color_2);

            arr[2][2][2].set_cubik_front_plane(up_color_0);
            arr[2][2][1].set_cubik_front_plane(up_color_1);
            arr[2][2][0].set_cubik_front_plane(up_color_2);

            arr[2][2][0].set_cubik_down_plane(front_color_0);
            arr[1][2][0].set_cubik_down_plane(front_color_1);
            arr[0][2][0].set_cubik_down_plane(front_color_2);

            arr[0][2][0].set_cubik_back_plane(down_color_0);
            arr[0][2][1].set_cubik_back_plane(down_color_1);
            arr[0][2][2].set_cubik_back_plane(down_color_2);
        }
        else
        {
            arr[0][2][2].set_cubik_right_plane(right_color_2_0);
            arr[0][2][1].set_cubik_right_plane(right_color_1_0);
            arr[0][2][0].set_cubik_right_plane(right_color_0_0);
            arr[1][2][2].set_cubik_right_plane(right_color_2_1);
            arr[1][2][0].set_cubik_right_plane(right_color_0_1);
            arr[2][2][2].set_cubik_right_plane(right_color_2_2);
            arr[2][2][1].set_cubik_right_plane(right_color_1_2);
            arr[2][2][0].set_cubik_right_plane(right_color_0_2);

            arr[0][2][2].set_cubik_up_plane(front_color_0);
            arr[1][2][2].set_cubik_up_plane(front_color_1);
            arr[2][2][2].set_cubik_up_plane(front_color_2);

            arr[2][2][2].set_cubik_front_plane(down_color_0);
            arr[2][2][1].set_cubik_front_plane(down_color_1);
            arr[2][2][0].set_cubik_front_plane(down_color_2);

            arr[2][2][0].set_cubik_down_plane(back_color_0);
            arr[1][2][0].set_cubik_down_plane(back_color_1);
            arr[0][2][0].set_cubik_down_plane(back_color_2);

            arr[0][2][0].set_cubik_back_plane(up_color_0);
            arr[0][2][1].set_cubik_back_plane(up_color_1);
            arr[0][2][2].set_cubik_back_plane(up_color_2);
        }
    }

    void rotate_front(char direction)
    {
        string up_color_0 = arr[2][0][2].get_cubik_up_plane();
        string up_color_1 = arr[2][1][2].get_cubik_up_plane();
        string up_color_2 = arr[2][2][2].get_cubik_up_plane();

        string right_color_0 = arr[2][2][2].get_cubik_right_plane();
        string right_color_1 = arr[2][2][1].get_cubik_right_plane();
        string right_color_2 = arr[2][2][0].get_cubik_right_plane();

        string down_color_0 = arr[2][2][0].get_cubik_down_plane();
        string down_color_1 = arr[2][1][0].get_cubik_down_plane();
        string down_color_2 = arr[2][0][0].get_cubik_down_plane();

        string left_color_0 = arr[2][0][0].get_cubik_left_plane();
        string left_color_1 = arr[2][0][1].get_cubik_left_plane();
        string left_color_2 = arr[2][0][2].get_cubik_left_plane();

        string front_color_0_0 = arr[2][0][2].get_cubik_front_plane();
        string front_color_0_1 = arr[2][1][2].get_cubik_front_plane();
        string front_color_0_2 = arr[2][2][2].get_cubik_front_plane();
        string front_color_1_0 = arr[2][0][1].get_cubik_front_plane();
        string front_color_1_2 = arr[2][2][1].get_cubik_front_plane();
        string front_color_2_0 = arr[2][0][0].get_cubik_front_plane();
        string front_color_2_1 = arr[2][1][0].get_cubik_front_plane();
        string front_color_2_2 = arr[2][2][0].get_cubik_front_plane();

        if (direction == '\'')
        {
            arr[2][0][2].set_cubik_front_plane(front_color_0_2);
            arr[2][1][2].set_cubik_front_plane(front_color_1_2);
            arr[2][2][2].set_cubik_front_plane(front_color_2_2);
            arr[2][0][1].set_cubik_front_plane(front_color_0_1);
            arr[2][2][1].set_cubik_front_plane(front_color_2_1);
            arr[2][0][0].set_cubik_front_plane(front_color_0_0);
            arr[2][1][0].set_cubik_front_plane(front_color_1_0);
            arr[2][2][0].set_cubik_front_plane(front_color_2_0);

            arr[2][0][2].set_cubik_up_plane(right_color_0);
            arr[2][1][2].set_cubik_up_plane(right_color_1);
            arr[2][2][2].set_cubik_up_plane(right_color_2);

            arr[2][2][2].set_cubik_right_plane(down_color_0);
            arr[2][2][1].set_cubik_right_plane(down_color_1);
            arr[2][2][0].set_cubik_right_plane(down_color_2);

            arr[2][2][0].set_cubik_down_plane(left_color_0);
            arr[2][1][0].set_cubik_down_plane(left_color_1);
            arr[2][0][0].set_cubik_down_plane(left_color_2);

            arr[2][0][0].set_cubik_left_plane(up_color_0);
            arr[2][0][1].set_cubik_left_plane(up_color_1);
            arr[2][0][2].set_cubik_left_plane(up_color_2);
        }
        else
        {
            arr[2][0][2].set_cubik_front_plane(front_color_2_0);
            arr[2][1][2].set_cubik_front_plane(front_color_1_0);
            arr[2][2][2].set_cubik_front_plane(front_color_0_0);
            arr[2][0][1].set_cubik_front_plane(front_color_2_1);
            arr[2][2][1].set_cubik_front_plane(front_color_0_1);
            arr[2][0][0].set_cubik_front_plane(front_color_2_2);
            arr[2][1][0].set_cubik_front_plane(front_color_1_2);
            arr[2][2][0].set_cubik_front_plane(front_color_0_2);

            arr[2][0][2].set_cubik_up_plane(left_color_0);
            arr[2][1][2].set_cubik_up_plane(left_color_1);
            arr[2][2][2].set_cubik_up_plane(left_color_2);

            arr[2][2][2].set_cubik_right_plane(up_color_0);
            arr[2][2][1].set_cubik_right_plane(up_color_1);
            arr[2][2][0].set_cubik_right_plane(up_color_2);

            arr[2][2][0].set_cubik_down_plane(right_color_0);
            arr[2][1][0].set_cubik_down_plane(right_color_1);
            arr[2][0][0].set_cubik_down_plane(right_color_2);

            arr[2][0][0].set_cubik_left_plane(down_color_0);
            arr[2][0][1].set_cubik_left_plane(down_color_1);
            arr[2][0][2].set_cubik_left_plane(down_color_2);
        }
    }

    void rotate_back(char direction)
    {
        string up_color_0 = arr[0][0][2].get_cubik_up_plane();
        string up_color_1 = arr[0][1][2].get_cubik_up_plane();
        string up_color_2 = arr[0][2][2].get_cubik_up_plane();

        string right_color_0 = arr[0][2][2].get_cubik_right_plane();
        string right_color_1 = arr[0][2][1].get_cubik_right_plane();
        string right_color_2 = arr[0][2][0].get_cubik_right_plane();

        string down_color_0 = arr[0][2][0].get_cubik_down_plane();
        string down_color_1 = arr[0][1][0].get_cubik_down_plane();
        string down_color_2 = arr[0][0][0].get_cubik_down_plane();

        string left_color_0 = arr[0][0][0].get_cubik_left_plane();
        string left_color_1 = arr[0][0][1].get_cubik_left_plane();
        string left_color_2 = arr[0][0][2].get_cubik_left_plane();

        string back_color_0_0 = arr[0][0][2].get_cubik_back_plane();
        string back_color_0_1 = arr[0][1][2].get_cubik_back_plane();
        string back_color_0_2 = arr[0][2][2].get_cubik_back_plane();
        string back_color_1_0 = arr[0][0][1].get_cubik_back_plane();
        string back_color_1_2 = arr[0][2][1].get_cubik_back_plane();
        string back_color_2_0 = arr[0][0][0].get_cubik_back_plane();
        string back_color_2_1 = arr[0][1][0].get_cubik_back_plane();
        string back_color_2_2 = arr[0][2][0].get_cubik_back_plane();

        if (direction == '\'')
        {
            arr[0][0][2].set_cubik_back_plane(back_color_2_0);
            arr[0][1][2].set_cubik_back_plane(back_color_1_0);
            arr[0][2][2].set_cubik_back_plane(back_color_0_0);
            arr[0][0][1].set_cubik_back_plane(back_color_2_1);
            arr[0][2][1].set_cubik_back_plane(back_color_0_1);
            arr[0][0][0].set_cubik_back_plane(back_color_2_2);
            arr[0][1][0].set_cubik_back_plane(back_color_1_2);
            arr[0][2][0].set_cubik_back_plane(back_color_0_2);

            arr[0][0][2].set_cubik_up_plane(left_color_0);
            arr[0][1][2].set_cubik_up_plane(left_color_1);
            arr[0][2][2].set_cubik_up_plane(left_color_2);

            arr[0][2][2].set_cubik_right_plane(up_color_0);
            arr[0][2][1].set_cubik_right_plane(up_color_1);
            arr[0][2][0].set_cubik_right_plane(up_color_2);

            arr[0][2][0].set_cubik_down_plane(right_color_0);
            arr[0][1][0].set_cubik_down_plane(right_color_1);
            arr[0][0][0].set_cubik_down_plane(right_color_2);

            arr[0][0][0].set_cubik_left_plane(down_color_0);
            arr[0][0][1].set_cubik_left_plane(down_color_1);
            arr[0][0][2].set_cubik_left_plane(down_color_2);
        }
        else
        {
            arr[0][0][2].set_cubik_back_plane(back_color_0_2);
            arr[0][1][2].set_cubik_back_plane(back_color_1_2);
            arr[0][2][2].set_cubik_back_plane(back_color_2_2);
            arr[0][0][1].set_cubik_back_plane(back_color_0_1);
            arr[0][2][1].set_cubik_back_plane(back_color_2_1);
            arr[0][0][0].set_cubik_back_plane(back_color_0_0);
            arr[0][1][0].set_cubik_back_plane(back_color_1_0);
            arr[0][2][0].set_cubik_back_plane(back_color_2_0);

            arr[0][0][2].set_cubik_up_plane(right_color_0);
            arr[0][1][2].set_cubik_up_plane(right_color_1);
            arr[0][2][2].set_cubik_up_plane(right_color_2);

            arr[0][2][2].set_cubik_right_plane(down_color_0);
            arr[0][2][1].set_cubik_right_plane(down_color_1);
            arr[0][2][0].set_cubik_right_plane(down_color_2);

            arr[0][2][0].set_cubik_down_plane(left_color_0);
            arr[0][1][0].set_cubik_down_plane(left_color_1);
            arr[0][0][0].set_cubik_down_plane(left_color_2);

            arr[0][0][0].set_cubik_left_plane(up_color_0);
            arr[0][0][1].set_cubik_left_plane(up_color_1);
            arr[0][0][2].set_cubik_left_plane(up_color_2);
        }
    }



    void run_some_steps(string comands)
    {
        for (int i = 0; i < comands.size();)
        {
            string b;
            if (comands[i + 1] == ' ') {
                b = " ";
            }
            else b = "\' ";

            if (comands[i] == 'F') {
                rotate_front(comands[i + 1]);
                steps += "F" + b;
            }
            else if (comands[i] == 'R') {
                rotate_right(comands[i + 1]);
                steps += "R" + b;
            }
            else if (comands[i] == 'B') {
                rotate_back(comands[i + 1]);
                steps += "B" + b;
            }
            else if (comands[i] == 'L') {
                rotate_left(comands[i + 1]);
                steps += "L" + b;
            }
            else if (comands[i] == 'U') {
                rotate_up(comands[i + 1]);
                steps += "U" + b;
            }
            else if (comands[i] == 'D') {
                rotate_down(comands[i + 1]);
                steps += "D" + b;
            }

            if (comands[i + 1] == '\'')
                i += 3;
            else
                i += 2;
        }
    }

    string get_steps() const {
        return steps;
    }



    bool is_1_step_completed()
    {
        return (front_center == arr[2][1][0].get_cubik_front_plane()) &&
               (right_center == arr[1][2][0].get_cubik_right_plane()) &&
               (back_center == arr[0][1][0].get_cubik_back_plane()) &&
               (left_center == arr[1][0][0].get_cubik_left_plane()) &&

               (down_center == arr[2][1][0].get_cubik_down_plane()) &&
               (down_center == arr[1][2][0].get_cubik_down_plane()) &&
               (down_center == arr[0][1][0].get_cubik_down_plane()) &&
               (down_center == arr[1][0][0].get_cubik_down_plane());
    }

    void cross_on_down_plane(int count_of_rotate_up_plane = 0)
    {
        bool config_is_done = false;

        ++count_of_turns_1_step;
        if (count_of_turns_1_step > 128) {
            throw -1;
        }

        if (!is_1_step_completed())
        {
            if (front_center == arr[2][1][2].get_cubik_front_plane() && down_center == arr[2][1][2].get_cubik_up_plane()) {
                run_some_steps("F F ");
                config_is_done = true;
            }

            if (right_center == arr[1][2][2].get_cubik_right_plane() && down_center == arr[1][2][2].get_cubik_up_plane()) {
                run_some_steps("R R ");
                config_is_done = true;
            }

            if (back_center == arr[0][1][2].get_cubik_back_plane() && down_center == arr[0][1][2].get_cubik_up_plane()) {
                run_some_steps("B B ");
                config_is_done = true;
            }

            if (left_center == arr[1][0][2].get_cubik_left_plane() && down_center == arr[1][0][2].get_cubik_up_plane()) {
                run_some_steps("L L ");
                config_is_done = true;
            }



            if (front_center == arr[2][1][2].get_cubik_up_plane() && down_center == arr[2][1][2].get_cubik_front_plane()) {
                run_some_steps("U' R' F R ");
                config_is_done = true;
            }

            if (right_center == arr[1][2][2].get_cubik_up_plane() && down_center == arr[1][2][2].get_cubik_right_plane()) {
                run_some_steps("U' B' R B ");
                config_is_done = true;
            }

            if (back_center == arr[0][1][2].get_cubik_up_plane() && down_center == arr[0][1][2].get_cubik_back_plane()) {
                run_some_steps("U' L' B L ");
                config_is_done = true;
            }

            if (left_center == arr[1][0][2].get_cubik_up_plane() && down_center == arr[1][0][2].get_cubik_left_plane()) {
                run_some_steps("U' F' L F ");
                config_is_done = true;
            }



            if (down_center == arr[2][2][1].get_cubik_front_plane()) {
                run_some_steps("F' U' F ");
                config_is_done = true;
            }

            if (down_center == arr[0][2][1].get_cubik_right_plane()) {
                run_some_steps("R' U' R ");
                config_is_done = true;
            }

            if (down_center == arr[0][0][1].get_cubik_back_plane()) {
                run_some_steps("B' U' B ");
                config_is_done = true;
            }

            if (down_center == arr[2][0][1].get_cubik_left_plane()) {
                run_some_steps("L' U' L ");
                config_is_done = true;
            }



            if (down_center == arr[2][0][1].get_cubik_front_plane()) {
                run_some_steps("F U' F' ");
                config_is_done = true;
            }

            if (down_center == arr[2][2][1].get_cubik_right_plane()) {
                run_some_steps("R U' R' ");
                config_is_done = true;
            }

            if (down_center == arr[0][2][1].get_cubik_back_plane()) {
                run_some_steps("B U' B' ");
                config_is_done = true;
            }

            if (down_center == arr[0][0][1].get_cubik_left_plane()) {
                run_some_steps("L U' L' ");
                config_is_done = true;
            }



            if (down_center == arr[2][1][0].get_cubik_front_plane()) {
                run_some_steps("F' F' U' F' F' ");
                config_is_done = true;
            }

            if (down_center == arr[1][2][0].get_cubik_right_plane()) {
                run_some_steps("R' R' U' R' R' ");
                config_is_done = true;
            }

            if (down_center == arr[0][1][0].get_cubik_back_plane()) {
                run_some_steps("B' B' U' B' B' ");
                config_is_done = true;
            }

            if (down_center == arr[1][0][0].get_cubik_left_plane()) {
                run_some_steps("L' L' U' L' L' ");
                config_is_done = true;
            }



            if (down_center == arr[2][1][0].get_cubik_down_plane() && front_center != arr[2][1][0].get_cubik_front_plane()) {
                run_some_steps("F' F' U' F' F' ");
                config_is_done = true;
            }

            if (down_center == arr[1][2][0].get_cubik_down_plane() && right_center != arr[1][2][0].get_cubik_right_plane()) {
                run_some_steps("R' R' U' R' R' ");
                config_is_done = true;
            }

            if (down_center == arr[0][1][0].get_cubik_down_plane() && back_center != arr[0][1][0].get_cubik_back_plane()) {
                run_some_steps("B' B' U' B' B' ");
                config_is_done = true;
            }

            if (down_center == arr[1][0][0].get_cubik_down_plane() && left_center != arr[1][0][0].get_cubik_left_plane()) {
                run_some_steps("L' L' U' L' L' ");
                config_is_done = true;
            }


            if (!is_1_step_completed()) {
                if (!config_is_done && count_of_rotate_up_plane < 4) {
                    run_some_steps("U ");
                    ++count_of_rotate_up_plane;
                } else if (config_is_done) {
                    count_of_rotate_up_plane = 0;
                } else if (count_of_rotate_up_plane == 4) {
                    throw -1;
                }

                cross_on_down_plane(count_of_rotate_up_plane);
            }
        }
    }




    bool is_2_step_completed()
    {
        bool first_step_is_completed = is_1_step_completed();

        bool down_plane =
                down_center == arr[0][0][0].get_cubik_down_plane() &&
                down_center == arr[0][2][0].get_cubik_down_plane() &&
                down_center == arr[2][0][0].get_cubik_down_plane() &&
                down_center == arr[2][2][0].get_cubik_down_plane();

        bool corners_of_side_planes =
                front_center == arr[2][0][0].get_cubik_front_plane() && front_center == arr[2][2][0].get_cubik_front_plane() &&
                right_center == arr[2][2][0].get_cubik_right_plane() && right_center == arr[0][2][0].get_cubik_right_plane() &&
                back_center == arr[0][2][0].get_cubik_back_plane() && back_center == arr[0][0][0].get_cubik_back_plane() &&
                left_center == arr[0][0][0].get_cubik_left_plane() && left_center == arr[2][0][0].get_cubik_left_plane();

        return down_plane && corners_of_side_planes;
    }

    void corners_on_down_plane(int count_of_rotate_up_plane = 0)
    {
        ++count_of_turns_2_step;
        if (count_of_turns_2_step > 80) {
            throw -1;
        }

        if (is_1_step_completed()) {
            if (!is_2_step_completed()) {
                bool config_is_done = false;

                if (arr[2][2][2].get_cubik_up_plane() == front_center &&
                    arr[2][2][2].get_cubik_right_plane() == right_center &&
                    arr[2][2][2].get_cubik_front_plane() == down_center) {
                    run_some_steps("F' U' F ");
                    config_is_done = true;
                }

                if (arr[0][2][2].get_cubik_up_plane() == right_center &&
                    arr[0][2][2].get_cubik_back_plane() == back_center &&
                    arr[0][2][2].get_cubik_right_plane() == down_center) {
                    run_some_steps("R' U' R ");
                    config_is_done = true;
                }

                if (arr[0][0][2].get_cubik_up_plane() == back_center &&
                    arr[0][0][2].get_cubik_left_plane() == left_center &&
                    arr[0][0][2].get_cubik_back_plane() == down_center) {
                    run_some_steps("B' U' B ");
                    config_is_done = true;
                }

                if (arr[2][0][2].get_cubik_up_plane() == left_center &&
                    arr[2][0][2].get_cubik_front_plane() == front_center &&
                    arr[2][0][2].get_cubik_left_plane() == down_center) {
                    run_some_steps("B' U' B ");
                    config_is_done = true;
                }


                if (arr[2][2][2].get_cubik_up_plane() == right_center &&
                    arr[2][2][2].get_cubik_right_plane() == down_center &&
                    arr[2][2][2].get_cubik_front_plane() == front_center) {
                    run_some_steps("R U R' ");
                    config_is_done = true;
                }

                if (arr[0][2][2].get_cubik_up_plane() == back_center &&
                    arr[0][2][2].get_cubik_back_plane() == down_center &&
                    arr[0][2][2].get_cubik_right_plane() == right_center) {
                    run_some_steps("B U B' ");
                    config_is_done = true;
                }

                if (arr[0][0][2].get_cubik_up_plane() == left_center &&
                    arr[0][0][2].get_cubik_left_plane() == down_center &&
                    arr[0][0][2].get_cubik_back_plane() == back_center) {
                    run_some_steps("L U L' ");
                    config_is_done = true;
                }

                if (arr[2][0][2].get_cubik_up_plane() == front_center &&
                    arr[2][0][2].get_cubik_front_plane() == down_center &&
                    arr[2][0][2].get_cubik_left_plane() == left_center) {
                    run_some_steps("F U F' ");
                    config_is_done = true;
                }


                if (arr[2][2][2].get_cubik_up_plane() == down_center &&
                    arr[2][2][2].get_cubik_right_plane() == front_center &&
                    arr[2][2][2].get_cubik_front_plane() == right_center) {
                    run_some_steps("R U' R' U' U' R U R' ");
                    config_is_done = true;
                }

                if (arr[0][2][2].get_cubik_up_plane() == down_center &&
                    arr[0][2][2].get_cubik_back_plane() == right_center &&
                    arr[0][2][2].get_cubik_right_plane() == back_center) {
                    run_some_steps("B U' B' U' U' B U B' ");
                    config_is_done = true;
                }

                if (arr[0][0][2].get_cubik_up_plane() == down_center &&
                    arr[0][0][2].get_cubik_left_plane() == back_center &&
                    arr[0][0][2].get_cubik_back_plane() == left_center) {
                    run_some_steps("L U' L' U' U' L U L' ");
                    config_is_done = true;
                }

                if (arr[2][0][2].get_cubik_up_plane() == down_center &&
                    arr[2][0][2].get_cubik_front_plane() == left_center &&
                    arr[2][0][2].get_cubik_left_plane() == front_center) {
                    run_some_steps("F U' F' U' U' F U F' ");
                    config_is_done = true;
                }


                if (arr[2][2][0].get_cubik_front_plane() == down_center) {
                    run_some_steps("F' U' F ");
                    config_is_done = true;
                }

                if (arr[0][2][0].get_cubik_right_plane() == down_center) {
                    run_some_steps("R' U' R ");
                    config_is_done = true;
                }

                if (arr[0][0][0].get_cubik_back_plane() == down_center) {
                    run_some_steps("B' U' B ");
                    config_is_done = true;
                }

                if (arr[2][0][0].get_cubik_left_plane() == down_center) {
                    run_some_steps("L' U' L ");
                    config_is_done = true;
                }


                if (arr[2][2][0].get_cubik_right_plane() == down_center) {
                    run_some_steps("F' U' F ");
                    config_is_done = true;
                }

                if (arr[0][2][0].get_cubik_back_plane() == down_center) {
                    run_some_steps("R' U' R ");
                    config_is_done = true;
                }

                if (arr[0][0][0].get_cubik_left_plane() == down_center) {
                    run_some_steps("B' U' B ");
                    config_is_done = true;
                }

                if (arr[2][0][0].get_cubik_front_plane() == down_center) {
                    run_some_steps("L' U' L ");
                    config_is_done = true;
                }


                if (arr[2][2][0].get_cubik_down_plane() == down_center &&
                    (arr[2][2][0].get_cubik_front_plane() != front_center ||
                     arr[2][2][0].get_cubik_right_plane() != right_center)) {
                    run_some_steps("R U' R' ");
                    config_is_done = true;
                }

                if (arr[0][2][0].get_cubik_down_plane() == down_center &&
                    (arr[0][2][0].get_cubik_right_plane() != right_center ||
                     arr[0][2][0].get_cubik_back_plane() != back_center)) {
                    run_some_steps("B U' B' ");
                    config_is_done = true;
                }

                if (arr[0][0][0].get_cubik_down_plane() == down_center &&
                    (arr[0][0][0].get_cubik_back_plane() != back_center ||
                     arr[0][0][0].get_cubik_left_plane() != left_center)) {
                    run_some_steps("L U' L' ");
                    config_is_done = true;
                }

                if (arr[2][0][0].get_cubik_down_plane() == down_center &&
                    (arr[2][0][0].get_cubik_left_plane() != left_center ||
                     arr[2][0][0].get_cubik_front_plane() != front_center)) {
                    run_some_steps("F U' F' ");
                    config_is_done = true;
                }


                if (!is_2_step_completed()) {
                    if (!config_is_done && count_of_rotate_up_plane < 4) {
                        run_some_steps("U ");
                        ++count_of_rotate_up_plane;
                    } else if (config_is_done) {
                        count_of_rotate_up_plane = 0;
                    } else if (count_of_rotate_up_plane == 4) {
                        throw -1;
                    }

                    corners_on_down_plane(count_of_rotate_up_plane);
                }
            }
        }
        else {
            cross_on_down_plane();
            corners_on_down_plane();
        }
    }




    bool is_3_step_completed()
    {
        bool second_step_is_completed = is_2_step_completed();

        bool second_layer =
                front_center == arr[2][0][1].get_cubik_front_plane() &&
                front_center == arr[2][2][1].get_cubik_front_plane() &&

                right_center == arr[2][2][1].get_cubik_right_plane() &&
                right_center == arr[0][2][1].get_cubik_right_plane() &&

                back_center == arr[0][2][1].get_cubik_back_plane() &&
                back_center == arr[0][0][1].get_cubik_back_plane() &&

                left_center == arr[0][0][1].get_cubik_left_plane() &&
                left_center == arr[2][0][1].get_cubik_left_plane();

        return second_step_is_completed && second_layer;
    }

    void edges_on_side_planes(int count_of_rotate_up_plane = 0)
    {
        ++count_of_turns_3_step;
        if (count_of_turns_3_step > 150) {
            throw -1;
        }

        if (is_2_step_completed()) {
            if (!is_3_step_completed()) {
                bool config_is_done = false;

                if (arr[2][1][2].get_cubik_front_plane() == front_center &&
                    arr[2][1][2].get_cubik_up_plane() == right_center) {
                    run_some_steps("U R U' R' U' F' U F ");
                    config_is_done = true;
                }

                if (arr[1][2][2].get_cubik_right_plane() == right_center &&
                    arr[1][2][2].get_cubik_up_plane() == back_center) {
                    run_some_steps("U B U' B' U' R' U R ");
                    config_is_done = true;
                }

                if (arr[0][1][2].get_cubik_back_plane() == back_center &&
                    arr[0][1][2].get_cubik_up_plane() == left_center) {
                    run_some_steps("U L U' L' U' B' U B ");
                    config_is_done = true;
                }

                if (arr[1][0][2].get_cubik_left_plane() == left_center &&
                    arr[1][0][2].get_cubik_up_plane() == front_center) {
                    run_some_steps("U F U' F' U' L' U L ");
                    config_is_done = true;
                }


                if (arr[2][1][2].get_cubik_front_plane() == front_center &&
                    arr[2][1][2].get_cubik_up_plane() == left_center) {
                    run_some_steps("U' L' U L U F U' F' ");
                    config_is_done = true;
                }

                if (arr[1][2][2].get_cubik_right_plane() == right_center &&
                    arr[1][2][2].get_cubik_up_plane() == front_center) {
                    run_some_steps("U' F' U F U R U' R' ");
                    config_is_done = true;
                }

                if (arr[0][1][2].get_cubik_back_plane() == back_center &&
                    arr[0][1][2].get_cubik_up_plane() == right_center) {
                    run_some_steps("U' R' U R U B U' B' ");
                    config_is_done = true;
                }

                if (arr[1][0][2].get_cubik_left_plane() == left_center &&
                    arr[1][0][2].get_cubik_up_plane() == back_center) {
                    run_some_steps("U' B' U B U L U' L' ");
                    config_is_done = true;
                }


                if (!is_3_step_completed()) {
                    if (!config_is_done && count_of_rotate_up_plane < 4) {
                        run_some_steps("U ");
                        ++count_of_rotate_up_plane;
                    }
                    else if (config_is_done) {
                        count_of_rotate_up_plane = 0;
                    }
                    else if (count_of_rotate_up_plane == 4) {
                        if (arr[2][2][1].get_cubik_front_plane() != front_center ||
                            arr[2][2][1].get_cubik_right_plane() != right_center) {
                            run_some_steps("U R U' R' U' F' U F ");
                            config_is_done = true;
                        }
                        else if (arr[0][2][1].get_cubik_right_plane() != right_center ||
                                 arr[0][2][1].get_cubik_back_plane() != back_center) {
                            run_some_steps("U B U' B' U' R' U R ");
                            config_is_done = true;
                        }
                        else if (arr[0][0][1].get_cubik_back_plane() != back_center ||
                                 arr[0][0][1].get_cubik_left_plane() != left_center) {
                            run_some_steps("U L U' L' U' B' U B ");
                            config_is_done = true;
                        }
                        else if (arr[2][0][1].get_cubik_left_plane() != left_center ||
                                 arr[2][0][1].get_cubik_front_plane() != front_center) {
                            run_some_steps("U F U' F' U' L' U L ");
                            config_is_done = true;
                        }
                        else {
                            throw -1;
                        }
                        count_of_rotate_up_plane = 0;
                    }

                    edges_on_side_planes(count_of_rotate_up_plane);
                }
            }
        }
        else {
            cross_on_down_plane();
            corners_on_down_plane();
            edges_on_side_planes();
        }
    }




    bool is_4_step_completed()
    {
        bool third_step_is_completed = is_3_step_completed();

        bool up_plane =
                up_center == arr[2][1][2].get_cubik_up_plane() &&
                up_center == arr[1][2][2].get_cubik_up_plane() &&
                up_center == arr[0][1][2].get_cubik_up_plane() &&
                up_center == arr[1][0][2].get_cubik_up_plane();

        return  third_step_is_completed && up_plane;
    }

    void cross_on_up_plane(int count = 0)
    {
        if (is_3_step_completed())
        {
            if (!is_4_step_completed())
            {
                if (count > 0) {
                    throw -1;
                }

                if (arr[2][1][2].get_cubik_front_plane() == up_center &&
                    arr[1][2][2].get_cubik_right_plane() == up_center &&
                    arr[0][1][2].get_cubik_up_plane() == up_center &&
                    arr[1][0][2].get_cubik_up_plane() == up_center) {
                    run_some_steps("F U R U' R' F' ");
                }
                else if (arr[1][2][2].get_cubik_right_plane() == up_center &&
                         arr[0][1][2].get_cubik_back_plane() == up_center &&
                         arr[1][0][2].get_cubik_up_plane() == up_center &&
                         arr[2][1][2].get_cubik_up_plane() == up_center) {
                    run_some_steps("R U B U' B' R' ");
                }
                else if (arr[0][1][2].get_cubik_back_plane() == up_center &&
                         arr[1][0][2].get_cubik_left_plane() == up_center &&
                         arr[2][1][2].get_cubik_up_plane() == up_center &&
                         arr[1][2][2].get_cubik_up_plane() == up_center) {
                    run_some_steps("B U L U' L' B' ");
                }
                else if (arr[1][0][2].get_cubik_left_plane() == up_center &&
                         arr[2][1][2].get_cubik_front_plane() == up_center &&
                         arr[1][2][2].get_cubik_up_plane() == up_center &&
                         arr[0][1][2].get_cubik_up_plane() == up_center) {
                    run_some_steps("L U F U' F' L' ");
                }
                else if (arr[2][1][2].get_cubik_front_plane() == up_center &&
                         arr[1][2][2].get_cubik_up_plane() == up_center &&
                         arr[0][1][2].get_cubik_back_plane() == up_center &&
                         arr[1][0][2].get_cubik_up_plane() == up_center) {
                    run_some_steps("F R U R' U' F' ");
                }
                else if (arr[1][2][2].get_cubik_right_plane() == up_center &&
                         arr[0][1][2].get_cubik_up_plane() == up_center &&
                         arr[1][0][2].get_cubik_left_plane() == up_center &&
                         arr[2][1][2].get_cubik_up_plane() == up_center) {
                    run_some_steps("R B U B' U' R' ");
                }
                else if (arr[2][1][2].get_cubik_front_plane() == up_center &&
                         arr[1][2][2].get_cubik_right_plane() == up_center &&
                         arr[0][1][2].get_cubik_back_plane() == up_center &&
                         arr[1][0][2].get_cubik_left_plane() == up_center) {
                    run_some_steps("F U R U' R' F' R B U B' U' R' ");
                }
                ++count;
                edges_on_side_planes(count);
            }
        }
    }




    bool is_5_step_completed()
    {
        bool fourth_step_is_completed = is_4_step_completed();

        bool side_planes =
                front_center == arr[2][1][2].get_cubik_front_plane() &&
                right_center == arr[1][2][2].get_cubik_right_plane() &&
                back_center == arr[0][1][2].get_cubik_back_plane() &&
                left_center == arr[1][0][2].get_cubik_left_plane();

        return  fourth_step_is_completed && side_planes;
    }

    void edges_on_up_plane()
    {
        if (count_of_turns_5_step > 80) {
            throw -1;
        }

        if (is_4_step_completed())
        {
            if (!is_5_step_completed())
            {
                if (arr[1][2][2].get_cubik_right_plane() == front_center) {
                    run_some_steps("U L' U' U' L U L' U L ");
                }
                else if (arr[1][0][2].get_cubik_left_plane() == front_center) {
                    run_some_steps("U B' U' U' B U B' U B ");
                }
                else if (arr[0][1][2].get_cubik_back_plane() == front_center) {
                    run_some_steps("U R' U' U' R U R' U R U B' U' U' B U B' U B U R' U' U' R U R' U R ");
                }

                if (arr[0][1][2].get_cubik_back_plane() == right_center) {
                    run_some_steps("U F' U' U' F U F' U F ");
                }
                else if (arr[1][0][2].get_cubik_left_plane() == right_center) {
                    run_some_steps("U B' U' U' B U B' U B U L' U' U' L U L' U L U B' U' U' B U B' U B ");
                }

                if (arr[1][0][2].get_cubik_left_plane() == back_center) {
                    run_some_steps("U R' U' U' R U R' U R ");
                }

                edges_on_up_plane();
            }
        }
        else {
            cross_on_down_plane();
            corners_on_down_plane();
            edges_on_side_planes();
            cross_on_up_plane();
        }
    }




    bool is_6_step_completed()
    {
        bool fifth_step_is_completed = is_5_step_completed();

        bool corner1 =
                (arr[2][0][2].get_cubik_front_plane() == front_center ||
                 arr[2][0][2].get_cubik_front_plane() == up_center ||
                 arr[2][0][2].get_cubik_front_plane() == left_center) &&

                (arr[2][0][2].get_cubik_up_plane() == front_center ||
                 arr[2][0][2].get_cubik_up_plane() == up_center ||
                 arr[2][0][2].get_cubik_up_plane() == left_center) &&

                (arr[2][0][2].get_cubik_left_plane() == front_center ||
                 arr[2][0][2].get_cubik_up_plane() == up_center ||
                 arr[2][0][2].get_cubik_up_plane() == left_center);

        bool corner2 =
                (arr[2][2][2].get_cubik_front_plane() == front_center ||
                 arr[2][2][2].get_cubik_front_plane() == up_center ||
                 arr[2][2][2].get_cubik_front_plane() == right_center) &&

                (arr[2][2][2].get_cubik_up_plane() == front_center ||
                 arr[2][2][2].get_cubik_up_plane() == up_center ||
                 arr[2][2][2].get_cubik_up_plane() == right_center) &&

                (arr[2][2][2].get_cubik_right_plane() == front_center ||
                 arr[2][2][2].get_cubik_right_plane() == up_center ||
                 arr[2][2][2].get_cubik_right_plane() == right_center);

        bool corner3 =
                (arr[0][2][2].get_cubik_back_plane() == back_center ||
                 arr[0][2][2].get_cubik_back_plane() == up_center ||
                 arr[0][2][2].get_cubik_back_plane() == right_center) &&

                (arr[0][2][2].get_cubik_up_plane() == back_center ||
                 arr[0][2][2].get_cubik_up_plane() == up_center ||
                 arr[0][2][2].get_cubik_up_plane() == right_center) &&

                (arr[0][2][2].get_cubik_right_plane() == back_center ||
                 arr[0][2][2].get_cubik_right_plane() == up_center ||
                 arr[0][2][2].get_cubik_right_plane() == right_center);

        bool corner4 =
                (arr[0][0][2].get_cubik_back_plane() == back_center ||
                 arr[0][0][2].get_cubik_back_plane() == up_center ||
                 arr[0][0][2].get_cubik_back_plane() == left_center) &&

                (arr[0][0][2].get_cubik_up_plane() == back_center ||
                 arr[0][0][2].get_cubik_up_plane() == up_center ||
                 arr[0][0][2].get_cubik_up_plane() == left_center) &&

                (arr[0][0][2].get_cubik_left_plane() == back_center ||
                 arr[0][0][2].get_cubik_left_plane() == up_center ||
                 arr[0][0][2].get_cubik_left_plane() == left_center);

        return fifth_step_is_completed && corner1 && corner2 && corner3 && corner4;
    }

    void corners_on_up_plane(int num_of_algo_made = 0)
    {
        ++count_of_turns_6_step;
        if (is_5_step_completed())
        {
            if (!is_6_step_completed())
            {
                if (count_of_turns_6_step > 64) {
                    throw -1;
                }

                if ((arr[2][0][2].get_cubik_left_plane() == front_center ||
                     arr[2][0][2].get_cubik_left_plane() == right_center ||
                     arr[2][0][2].get_cubik_left_plane() == up_center) &&

                    (arr[2][0][2].get_cubik_front_plane() == front_center ||
                     arr[2][0][2].get_cubik_front_plane() == right_center ||
                     arr[2][0][2].get_cubik_front_plane() == up_center) &&

                    (arr[2][0][2].get_cubik_up_plane() == front_center ||
                     arr[2][0][2].get_cubik_up_plane() == right_center ||
                     arr[2][0][2].get_cubik_up_plane() == up_center)) {
                    run_some_steps("F' L' F R' F' L F R ");
                    corners_on_up_plane(++num_of_algo_made);
                }
                else if ((arr[0][2][2].get_cubik_right_plane() == front_center ||
                          arr[0][2][2].get_cubik_right_plane() == right_center ||
                          arr[0][2][2].get_cubik_right_plane() == up_center) &&

                         (arr[0][2][2].get_cubik_back_plane() == front_center ||
                          arr[0][2][2].get_cubik_back_plane() == right_center ||
                          arr[0][2][2].get_cubik_back_plane() == up_center) &&

                         (arr[0][2][2].get_cubik_up_plane() == front_center ||
                          arr[0][2][2].get_cubik_up_plane() == right_center ||
                          arr[0][2][2].get_cubik_up_plane() == up_center)) {
                    run_some_steps("R' F' L' F R F' L F ");
                    corners_on_up_plane(++num_of_algo_made);
                }
                else if ((arr[0][0][2].get_cubik_left_plane() == front_center ||
                          arr[0][0][2].get_cubik_left_plane() == right_center ||
                          arr[0][0][2].get_cubik_left_plane() == up_center) &&

                         (arr[0][0][2].get_cubik_back_plane() == front_center ||
                          arr[0][0][2].get_cubik_back_plane() == right_center ||
                          arr[0][0][2].get_cubik_back_plane() == up_center) &&

                         (arr[0][0][2].get_cubik_up_plane() == front_center ||
                          arr[0][0][2].get_cubik_up_plane() == right_center ||
                          arr[0][0][2].get_cubik_up_plane() == up_center)) {
                    run_some_steps("F' L' B' L F L' B L ");
                    corners_on_up_plane(++num_of_algo_made);
                }
                else if ((arr[2][0][2].get_cubik_left_plane() == right_center ||
                          arr[2][0][2].get_cubik_left_plane() == back_center ||
                          arr[2][0][2].get_cubik_left_plane() == up_center) &&

                         (arr[2][0][2].get_cubik_front_plane() == right_center ||
                          arr[2][0][2].get_cubik_front_plane() == back_center ||
                          arr[2][0][2].get_cubik_front_plane() == up_center) &&

                         (arr[2][0][2].get_cubik_up_plane() == right_center ||
                          arr[2][0][2].get_cubik_up_plane() == back_center ||
                          arr[2][0][2].get_cubik_up_plane() == up_center)) {
                    run_some_steps("B' R' B L' B' R B L ");
                    corners_on_up_plane(++num_of_algo_made);
                }
                else if ((arr[0][0][2].get_cubik_left_plane() == right_center ||
                          arr[0][0][2].get_cubik_left_plane() == back_center ||
                          arr[0][0][2].get_cubik_left_plane() == up_center) &&

                         (arr[0][0][2].get_cubik_back_plane() == right_center ||
                          arr[0][0][2].get_cubik_back_plane() == back_center ||
                          arr[0][0][2].get_cubik_back_plane() == up_center) &&

                         (arr[0][0][2].get_cubik_up_plane() == right_center ||
                          arr[0][0][2].get_cubik_up_plane() == back_center ||
                          arr[0][0][2].get_cubik_up_plane() == up_center)) {
                    run_some_steps("F' L' B' L F L' B L ");
                    corners_on_up_plane(++num_of_algo_made);
                }
            }
        }
        else if (num_of_algo_made) {
            throw -1;
        }
    }




    bool is_cube_done()
    {
        bool sixth_step_is_completed = is_6_step_completed();

        bool corner1 =
                arr[2][0][2].get_cubik_front_plane() == front_center &&
                arr[2][0][2].get_cubik_up_plane() == up_center &&
                arr[2][0][2].get_cubik_left_plane() == left_center;

        bool corner2 =
                arr[2][2][2].get_cubik_front_plane() == front_center &&
                arr[2][2][2].get_cubik_up_plane() == up_center &&
                arr[2][2][2].get_cubik_right_plane() == right_center;

        bool corner3 =
                arr[0][2][2].get_cubik_back_plane() == back_center &&
                arr[0][2][2].get_cubik_up_plane() == up_center &&
                arr[0][2][2].get_cubik_right_plane() == right_center;

        bool corner4 =
                arr[0][0][2].get_cubik_back_plane() == back_center &&
                arr[0][0][2].get_cubik_up_plane() == up_center &&
                arr[0][0][2].get_cubik_left_plane() == left_center;

        return sixth_step_is_completed && corner1 && corner2 && corner3 && corner4;
    }

    void up_plane_completely()
    {
        for (int i = 0; i < 4; ++i)
        {
            if (!is_cube_done())
            {
                if (arr[2][2][2].get_cubik_right_plane() == up_center) {
                    run_some_steps("F' R F R' F' R F R' ");
                }
                else if (arr[2][2][2].get_cubik_front_plane() == up_center) {
                    run_some_steps("R F' R' F R F' R' F ");
                }

                run_some_steps("U ");
            }
            else {
                return;
            }
        }

        if (!is_cube_done()) {
            throw -1;
        }
    }




    // Ввод развёртки из файла
    void read_cube_from_file(const string& file)
    {
        ifstream fin(file);
        string color;

        // верхняя грань
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fin >> color;
                arr[i][j][2].set_cubik_up_plane(color);
            }
        }

        // левая грань
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fin >> color;
                arr[j][0][2 - i].set_cubik_left_plane(color);
            }
        }

        // передняя грань
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fin >> color;
                arr[2][j][2 - i].set_cubik_front_plane(color);
            }
        }

        // правая грань
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fin >> color;
                arr[2 - j][2][2 - i].set_cubik_right_plane(color);
            }
        }

        // задняя грань
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fin >> color;
                arr[0][2 - j][2 - i].set_cubik_back_plane(color);
            }
        }

        // нижняя грань
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fin >> color;
                arr[2 - i][j][0].set_cubik_down_plane(color);
            }
        }
    }

    void build_with_steps()
    {
        start_pos();
        steps += "Шаг 1: ";
        cross_on_down_plane();
        print_cube();
        steps += "\nШаг 2: ";
        corners_on_down_plane();
        print_cube();
        steps += "\nШаг 3: ";
        edges_on_side_planes();
        print_cube();
        steps += "\nШаг 4: ";
        cross_on_up_plane();
        print_cube();
        steps += "\nШаг 5: ";
        edges_on_up_plane();
        print_cube();
        steps += "\nШаг 6: ";
        corners_on_up_plane();
        print_cube();
        steps += "\nШаг 7: ";
        up_plane_completely();
        print_cube();
        cout << steps << '\n';
        start_pos();
    }

    // Вывод развёртки в консоль
    void print_cube()
    {
        cout << '\n';
        for (int i = 0; i < 3; i++)
        {
            cout << setw(15) << "|";
            for (int j = 0; j < 3; j++)
            {
                cout << setw(3) << arr[i][j][2].get_cubik_up_plane();
            }
            cout << setw(3) << "|" << endl;
        }

        cout <<  endl << setw(3) << "|";
        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[j][0][2].get_cubik_left_plane();
        cout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[2][j][2].get_cubik_front_plane();
        cout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[2 - j][2][2].get_cubik_right_plane();
        cout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[0][2 - j][2].get_cubik_back_plane();
        cout << setw(3) << "|" << '\n' << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[j][0][1].get_cubik_left_plane();
        cout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[2][j][1].get_cubik_front_plane();
        cout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[2 - j][2][1].get_cubik_right_plane();
        cout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[0][2 - j][1].get_cubik_back_plane();
        cout << setw(3) << "|" << '\n' << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[j][0][0].get_cubik_left_plane();
        cout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[2][j][0].get_cubik_front_plane();
        cout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[2 - j][2][0].get_cubik_right_plane();
        cout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            cout << setw(3) << arr[0][2 - j][0].get_cubik_back_plane();
        cout << setw(3) << "|" << "\n\n";

        for (int i = 0; i < 3; i++)
        {
            cout << setw(15) << "|";
            for (int j = 0; j < 3; j++)
                cout << setw(3) << arr[2 - i][j][0].get_cubik_down_plane();
            cout << setw(3) << "|" << endl;
        }
        cout << "\n";
    }

    // Вывод развёртки в файл
    void print_cube_in_file()
    {
        fout << '\n';
        for (int i = 0; i < 3; i++)
        {
            fout << setw(15) << "|";
            for (int j = 0; j < 3; j++)
            {
                fout << setw(3) << arr[i][j][2].get_cubik_up_plane();
            }
            fout << setw(3) << "|" << endl;
        }

        fout <<  endl << setw(3) << "|";
        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[j][0][2].get_cubik_left_plane();
        fout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[2][j][2].get_cubik_front_plane();
        fout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[2 - j][2][2].get_cubik_right_plane();
        fout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[0][2 - j][2].get_cubik_back_plane();
        fout << setw(3) << "|" << '\n' << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[j][0][1].get_cubik_left_plane();
        fout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[2][j][1].get_cubik_front_plane();
        fout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[2 - j][2][1].get_cubik_right_plane();
        fout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[0][2 - j][1].get_cubik_back_plane();
        fout << setw(3) << "|" << '\n' << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[j][0][0].get_cubik_left_plane();
        fout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[2][j][0].get_cubik_front_plane();
        fout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[2 - j][2][0].get_cubik_right_plane();
        fout << setw(3) << "|";

        for (int j = 0; j < 3; j++)
            fout << setw(3) << arr[0][2 - j][0].get_cubik_back_plane();
        fout << setw(3) << "|" << "\n\n";

        for (int i = 0; i < 3; i++)
        {
            fout << setw(15) << "|";
            for (int j = 0; j < 3; j++)
                fout << setw(3) << arr[2 - i][j][0].get_cubik_down_plane();
            fout << setw(3) << "|" << endl;
        }
        fout << "\n";
    }

    // Перемешивание кубика
    void shuffle_cube() {
        srand(time(nullptr));
        int count = 5 + rand() % (101 - 5 + 1);

        for (int i = 0; i < count; ++i) {

            int num = rand() % 12;

            switch (num) {
                case 0:
                    rotate_front(' ');
                    break;
                case 1:
                    rotate_front('\'');
                    break;
                case 2:
                    rotate_right(' ');
                    break;
                case 3:
                    rotate_right('\'');
                    break;
                case 4:
                    rotate_back(' ');
                    break;
                case 5:
                    rotate_back('\'');
                    break;
                case 6:
                    rotate_left(' ');
                    break;
                case 7:
                    rotate_left('\'');
                    break;
                case 8:
                    rotate_up(' ');
                    break;
                case 9:
                    rotate_up('\'');
                    break;
                case 10:
                    rotate_down(' ');
                    break;
                case 11:
                    rotate_down('\'');
                    break;
                default:
                    break;
            }
        }
    }

    bool is_correct() {
        CubeRubik new_cube(*this);
        vector<string> centers = { new_cube.arr[1][2][1].get_cubik_right_plane(),
                                   new_cube.arr[1][0][1].get_cubik_left_plane(),
                                   new_cube.arr[1][1][2].get_cubik_up_plane(),
                                   new_cube.arr[1][1][0].get_cubik_down_plane(),
                                   new_cube.arr[2][1][1].get_cubik_front_plane(),
                                   new_cube.arr[0][1][1].get_cubik_back_plane() };

        for (int i = 0; i < centers.size(); ++i) {
            for (int j = i + 1; j < centers.size(); ++j) {
                if (centers[i] == centers[j]) {
                    return false;
                }
            }
        }

        try {
            new_cube.start_pos();
            new_cube.cross_on_down_plane();
            new_cube.corners_on_down_plane();
            new_cube.edges_on_side_planes();
            new_cube.cross_on_up_plane();
            new_cube.edges_on_up_plane();
            new_cube.corners_on_up_plane();
            new_cube.up_plane_completely();
            new_cube.start_pos();

            return true;
        }
        catch (int) {
            return false;
        }
    }
};




