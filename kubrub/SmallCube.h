//
// Created by Виктория on 25.05.2022.
//


#include <iostream>
using std::string;

class SmallCube {
private:
    // Грани кубика. Видимые грани имеют цвет, а невидимые - чёрные
    string cubik_up_plane = "B";
    string cubik_down_plane = "B";
    string cubik_left_plane = "B";
    string cubik_right_plane = "B";
    string cubik_front_plane = "B";
    string cubik_back_plane = "B";

public:
    // Гетеры
    string get_cubik_up_plane() const {
        return cubik_up_plane;
    }
    string get_cubik_down_plane() const {
        return cubik_down_plane;
    }
    string get_cubik_left_plane() const {
        return cubik_left_plane;
    }
    string get_cubik_right_plane() const {
        return cubik_right_plane;
    }
    string get_cubik_front_plane() const {
        return cubik_front_plane;
    }
    string get_cubik_back_plane() const {
        return cubik_back_plane;
    }

    // Сеттеры
    void set_cubik_up_plane(const string& color) {
        cubik_up_plane = color;
    }
    void set_cubik_down_plane(const string& color) {
        cubik_down_plane = color;
    }
    void set_cubik_left_plane(const string& color) {
        cubik_left_plane = color;
    }
    void set_cubik_right_plane(const string& color) {
        cubik_right_plane = color;
    }
    void set_cubik_front_plane(const string& color) {
        cubik_front_plane = color;
    }
    void set_cubik_back_plane(const string& color) {
        cubik_back_plane = color;
    }

public:
    SmallCube() = default;

    SmallCube(string up, string down, string left, string right, string front, string back)
            : cubik_up_plane(move(up)), cubik_down_plane(move(down)), cubik_left_plane(move(left))
            , cubik_right_plane(move(right)), cubik_front_plane(move(front)), cubik_back_plane(move(back)) {}

    // Операторы
    SmallCube& operator=(const SmallCube& cube_piece) {
        cubik_up_plane = cube_piece.cubik_up_plane;
        cubik_down_plane = cube_piece.cubik_down_plane;
        cubik_left_plane = cube_piece.cubik_left_plane;
        cubik_right_plane = cube_piece.cubik_right_plane;
        cubik_front_plane = cube_piece.cubik_front_plane;
        cubik_back_plane = cube_piece.cubik_back_plane;

        return *this;
    }
};

