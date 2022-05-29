//
// Created by Виктория on 19.05.2022.
//

#pragma once
using namespace std;

template<class T>
class buffer {
    class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
        T *Pointer = nullptr;

    public:
        using value_type = typename std::iterator<std::random_access_iterator_tag, T>::value_type;

        Iterator() {}

        Iterator(T *pointer) : Pointer(pointer) {}

        Iterator(const Iterator &iterator) : Pointer(iterator.Pointer) {}
        bool operator==(Iterator &iterator) { return Pointer == iterator.Pointer; }
        bool operator==(T *pointer) { return Pointer == pointer; }
        bool operator!=(Iterator &iterator) { return Pointer != iterator.Pointer; }
        bool operator!=(T *pointer) { return Pointer != pointer; }
        bool operator<(Iterator &iterator) { return Pointer < iterator.Pointer; }
        bool operator<(T *pointer) { return Pointer < pointer; }
        bool operator>(Iterator &iterator) { return Pointer > iterator.Pointer; }
        bool operator>(T *pointer) { return Pointer > pointer; }
        bool operator<=(Iterator &iterator) { return Pointer <= iterator.Pointer; }
        bool operator<=(T *pointer) { return Pointer <= pointer; }
        bool operator>=(Iterator &iterator) { return Pointer >= iterator.Pointer; }
        bool operator>=(T *pointer) { return Pointer >= pointer; }
        T &operator*() { return *Pointer; }
        T *operator->() { return Pointer; }
        Iterator &operator++() {
            Pointer++;
            return *this;
        }
        Iterator operator++(T) {
            Iterator iterator(*this);
            ++Pointer;
            return iterator;
        }
        Iterator &operator--() {
            Pointer--;
            return *this;
        }
        Iterator operator--(T) {
            Iterator iterator(*this);
            --Pointer;
            return iterator;
        }
        Iterator &operator+=(Iterator &iterator) {
            Pointer += iterator.Pointer;
            return *this;
        }
        Iterator &operator+=(value_type shift) {
            Pointer += shift;
            return *this;
        }
        Iterator &operator-=(Iterator &iterator) {
            Pointer -= iterator.Pointer;
            return *this;
        }
        Iterator operator+(value_type shift) { return Iterator(Pointer + shift); }
        Iterator operator-(value_type shift) { return Iterator(Pointer - shift); }
        Iterator &operator=(Iterator &iterator) {
            if (Pointer != iterator.Pointer) {
                Pointer = iterator.Pointer;
            }
            return *this;
        }
        Iterator &operator=(T *pointer) {
            if (Pointer != pointer) {
                Pointer = pointer;
            }
            return *this;
        }
        value_type operator-(Iterator &iterator) { return static_cast<int>(Pointer - iterator.Pointer); }
        value_type operator+(Iterator &iterator) { return Pointer - iterator.Pointer; }
    };
    T &operator[](int index) {
        return Data[index % Volume];
    }
    T *Data = nullptr;

    int Volume = 0;
    int Size = 0;

    Iterator Begin;
    Iterator End;

    int front_index = 0;
    int back_index = 0;

    void init(int begin_index, int end_index) {
        Data = new T[Volume];
        if (begin_index > -1) {
            Begin = &Data[begin_index];
        }
        End = &Data[end_index];
    }

    void de_init() {
        Begin = nullptr;
        End = nullptr;

        delete[] Data;
    }

public:
    explicit buffer() {}

    explicit buffer(int volume) : Volume(volume) {
        if (Volume == 0) {
            buffer();
        } else if (Volume > 0) {
            init(-1, 0);
        } else {
            throw Exception("Invalid volume value!");
        }
    }

    ~buffer() {
        de_init();
    }

    Iterator begin() { return Begin; }
    Iterator end() { return End; }
    const Iterator begin() const { return Begin; }
    const Iterator end() const { return End; }

    void addLast(T object) {
        if (Volume > 0) {
            if (Size < Volume) {
                if (Begin == nullptr) {
                    *End = object;
                    Begin = End;

                    End++;
                    Size++;
                } else {
                    *End = object;

                    End++;
                    Size++;

                    if (Size == Volume) {
                        front_index = Volume - 1;
                    }
                }
            } else {
                Data[back_index] = object;

                back_index = (back_index + 1) % Volume;
            }
        } else {
            throw Exception("Volume is zero!");
        }
    }

    void addFirst(T object) {
        if (Volume > 0) {
            if (Size < Volume) {
                if (Begin == nullptr) {
                    *End = object;
                    Begin = End;

                    End++;
                    Size++;
                } else {
                    for (Iterator it = End - 1; it >= Begin; it--) {
                        *(it + 1) = *it;
                    }

                    *Begin = object;

                    End++;
                    Size++;

                    if (Size == Volume) {
                        front_index = Volume - 1;
                    }
                }
            } else {
                Data[front_index] = object;

                front_index = (front_index + Volume - 1) % Volume;
            }
        } else {
            throw Exception("Volume is zero!");
        }
    }

    void removeLast() {
        if (Size > 0) {
            End--;
            Size--;

            if (Size == 0) {
                Begin = nullptr;
            }
        } else {
            cout << "The buffer is empty!" << endl;
        }
    }

    void removeFirst() {
        if (Size > 0) {
            for (Iterator it = Begin + 1; it < End; it++) {
                *(it - 1) = *it;
            }
            End--;
            Size--;

            if (Size == 0) {
                Begin = nullptr;
            }
        } else {
            cout << "The buffer is empty!" << endl;
        }
    }

    void insert(Iterator position, T object) {
        if (position >= Begin && position < &Data[Volume]) {
            if (Size < Volume) {
                if (position == Begin) {
                    push_front(object);
                } else if (position == End) {
                    push_back(object);
                } else {
                    for (Iterator it = &Data[Size - 1]; it >= position; it--) {
                        *(it + 1) = *it;
                    }

                    *position = object;

                    End++;
                    Size++;
                }
            } else {
                *position = object;
            }
        } else {
            cout << "Invalid position!" << endl;
        }
    }

    void erase(Iterator position) {
        if (position >= Begin && position < &Data[Volume]) {
            if (Size > 0) {
                if (position == Begin) {
                    addFirst();
                } else if (position == &Data[Size - 1]) {
                    addLast();
                } else {
                    for (Iterator it = position; it < &Data[Size - 1]; it++) {
                        *it = *(it + 1);
                    }

                    End--;
                    Size--;
                }
            } else {
                cout << "The buffer is empty!" << endl;
            }
        } else {
            cout << "Invalid position!" << endl;
        }
    }

    void resize(int capacity) {
        if (capacity == 0) {
            de_init();

            back_index = 0;
            front_index = 0;
        } else if (capacity > 0 && Volume == 0) {
            Volume = move(capacity);

            init(-1, 0);

            front_index = Volume - 1;
        } else if (capacity >= Size) {
            Volume = move(capacity);
            T *temp_buffer = new T[Volume];

            for (int i = 0; i < Size; i++) {
                temp_buffer[i] = Data[i];
            }

            de_init();

            init(0, Size);

            for (int i = 0; i < Size; i++) {
                Data[i] = temp_buffer[i];
            }

            delete[] temp_buffer;
        } else if (capacity > 0 && capacity < Size) {
            Volume = move(capacity);
            Size = Volume;
            T *temp_buffer = new T[Volume];

            for (int i = 0; i < Volume; i++) {
                temp_buffer[i] = Data[i];
            }

            de_init();

            init(0, Volume);

            for (int i = 0; i < Volume; i++) {
                Data[i] = temp_buffer[i];
            }

            delete[] temp_buffer;

            front_index = Volume - 1;
        } else if (capacity < 0) {
            cout << "Invalid volume value!" << endl;
        }
    }

    void print() {
        cout << "Filled out: " << Size << endl;
        if (Size == 0) {
            cout << "The buffer is empty!" << endl;
        } else {
            for (int i = 0; i < Size; i++) {
                cout << Data[i] << ' ';
            }
            cout << endl;
        }
    }
};
 /*
#include <stdexcept>
#include <algorithm>

// шаблонный класс реализующий циклический буфер
template<typename T>
class ring_buffer
{
private:
    int cap;    // ёмкость буфера
    int count;  // количество элементов в буфере
    int head;   // позиция начала
    int tail;   // позиция конца
    T* buf;     // массив для хранения элементов буфера

public:
    // конструктор
    ring_buffer(int capacity)
    {
        if (capacity <= 0)
        {
            throw std::invalid_argument("Ёмкость буфера должна быть положительной");
        }
        cap = capacity;
        count = 0;
        head = 0;
        tail = 0;
        buf = new T[cap];
    }

    // деструктор
    ~ring_buffer()
    {
        delete[] buf;
    }

    // возвращает количество элементов в буфере
    int size() const
    {
        return count;
    }

    // возвращает ёмкость буфера
    int capacity() const
    {
        return cap;
    }

    // вовзращает пуст ли буфер
    bool empty() const
    {
        return count == 0;
    }

private:
    // вспомогательный метод для инкрементирования позиции начала буфера
    // также уменьшает счетчик количества
    void inc_head()
    {
        head++;
        count--;
        if (head == cap)
        {
            head = 0;
        }
    }

    // вспомогательный метод для инкрементирования позиции конца буфера
    // также увеличивает счетчик количества
    void inc_tail()
    {
        tail++;
        count++;
        if (tail == cap)
        {
            tail = 0;
        }
    }

    // вспомогательный метод для декрементирования позиции головы буфера
    // также увеличивает счетчик количества
    void dec_head()
    {
        head--;
        count++;
        if (head == -1)
        {
            head = cap - 1;
        }
    }

    // вспомогательный метод для декрементирования позиции конца буфера
    // также уменьшает счетчик количества
    void dec_tail()
    {
        tail--;
        count--;
        if (tail == -1)
        {
            tail = cap - 1;
        }
    }

public:
    // добавление в начало
    void push_front(const T& element)
    {
        if (count == 0)
        {
            buf[head] = element;
            tail = head;
            count++;
        }
        else if (count < cap)
        {
            dec_head();
            buf[head] = element;
        }
        else
        {
            dec_head();
            dec_tail();
            buf[head] = element;
        }
    }

    // добавление в конец
    void push_back(const T& element)
    {
        if (count == 0)
        {
            buf[head] = element;
            tail = head;
            count++;
        }
        else if (count < cap)
        {
            inc_tail();
            buf[tail] = element;
        }
        else
        {
            inc_tail();
            inc_head();
            buf[tail] = element;
        }
    }

    // чтение элемента из начала
    T& front()
    {
        if (count == 0)
        {
            throw std::out_of_range("Буфер пуст");
        }

        return buf[head];
    }

    // чтение элемента из конца
    T& back()
    {
        if (count == 0)
        {
            throw std::out_of_range("Буфер пуст");
        }

        return buf[tail];
    }

    // чтение элемента из начала неизменяемого буфера
    const T& front() const
    {
        if (count == 0)
        {
            throw std::out_of_range("Буфер пуст");
        }

        return buf[head];
    }

    // чтение элемента из конца неизменяемого буфера
    const T& back() const
    {
        if (count == 0)
        {
            throw std::out_of_range("Буфер пуст");
        }

        return buf[tail];
    }

    // чтение ссылки на элемент по его индексу от начала буфера
    T& operator[](int index)
    {
        if (index < 0 && index >= count)
        {
            throw std::out_of_range("Индекс не существует");
        }

        int pos = head + index;
        if (pos >= cap)
        {
            pos = pos - cap;
        }

        return buf[pos];
    }

    // чтение ссылки на элемент по его индексу от начала неизменяемого буфера
    const T& operator[](int index) const
    {
        if (index < 0 && index >= count)
        {
            throw std::out_of_range("Индекс не существует");
        }

        int pos = head + index;
        if (pos >= cap)
        {
            pos = pos - cap;
        }

        return buf[pos];
    }

    // удаление элемента из начала
    void pop_front()
    {
        if (count == 0)
        {
            throw std::out_of_range("Буфер пуст");
        }

        inc_head();
    }

    //  удаление элемента из конца
    void pop_back()
    {
        if (count == 0)
        {
            throw std::out_of_range("Буфер пуст");
        }

        dec_tail();
    }

    // изменение ёмкости
    // если новая ёмкость меньше предудущей, то какая-то часть элементов от начала буфера может быть обрезана
    void resize(int new_capacity)
    {
        if (new_capacity <= 0)
        {
            throw std::invalid_argument("Ёмкость буфера должна быть положительной");
        }
        if (new_capacity != cap)
        {
            T* new_buf = new T[new_capacity]; // новый массив новой ёмкости
            int new_count = std::min<T>(new_capacity, count); // выбираем значение количества элементов, которое вмещается
            for (int i = new_count - 1, pos = tail; i >= 0; i--)
            {
                // копируем существующие элементы с конца буфера
                new_buf[i] = buf[pos];
                pos--;
                if (pos == -1)
                {
                    pos = cap - 1;
                }
            }
            delete[] buf; // удаляем старый массив
            cap = new_capacity; // новая ёмкость
            buf = new_buf; // новый массив
            count = new_count; // новое количество элементов в буфере
            head = 0; // новая позииция начала буфера
            tail = (new_count != 0) ? (new_count - 1) : 0; // новая позиция конца буфера
        }
    }

    // очистка буфера
    void clear()
    {
        count = 0; // больше ничего нет
        head = 0;
        tail = 0;
    }

private:
    // вспомогательный метод для вставки элемента в позицию, указанную индексом от начала буфера
    void insert(int index, const T& element)
    {
        if (index >= count)
        {
            throw std::out_of_range("Индекс не существует");
        }

        // pos - позиция, куда попадет элемент
        int pos = head + index;
        if (pos >= cap)
        {
            pos = pos - cap;
        }

        if (count == cap)
        {
            // если места больше нет, освободим позицию, смещая элементы левее влево, теряя самый первый элемент
            for (int i = index, to = head; i > 0; i--)
            {
                int from = to + 1;
                if (from == cap)
                {
                    from = 0;
                }
                buf[to] = buf[from];
                to++;
                if (to == cap)
                {
                    to = 0;
                }
            }
            buf[pos] = element;
        }
        else
        {
            // если место есть, то освобождаем позицию, смещая элементы правее вправо на одну позицию
            for (int i = count - index, from = tail; i > 0; i-- )
            {
                int to = from + 1;
                if (to == cap)
                {
                    to = 0;
                }
                buf[to] = buf[from];
                from--;
                if (from == -1)
                {
                    from = cap - 1;
                }
            }
            buf[pos] = element;

            inc_tail(); // смещаем позицию конца буфера и увеличиваем количество элементов на 1
        }
    }

    // вспомогательный метод для удаления элемента указанного индексом от начала буфера
    void remove(int index)
    {
        if (index >= count)
        {
            throw std::out_of_range("Индекс не существует");
        }

        // pos - позиция, из которой удалится элемент
        int pos = head + index;
        if (pos >= cap)
        {
            pos = pos - cap;
        }

        // смещаем элементы правее удаляемого влево на одну позицию
        // удаляемый элемент заменяется правым соседом, если он есть
        for (int i = count - index, to = pos; i > 0; i--)
        {
            int from = to + 1;
            if (from == cap)
            {
                from = 0;
            }
            buf[to] = buf[from];
            to++;
            if (to == cap)
            {
                to = 0;
            }
        }

        dec_tail(); // смещаем позицию конца буфера и уменьшаем количество элементов на 1
    }

public:
    // итератор циклического буфера
    class iterator
    {
    private:
        ring_buffer* buf; // указатель на буфер, которому принадлежит итератор
        int ind; // индекс элемента от начала буфера, на который в данный момент установлен итератор
    public:
        // конструктор итератора, привязыыващий его к буферу и какому-то элементу в нем, указанного
        // индексом от начала буфера
        iterator(ring_buffer* buffer, int index)
        {
            buf = buffer;
            ind = index;
        }

        // конструктор копирования
        iterator(const iterator& that)
        {
            buf = that.buf;
            ind = that.ind;
        }

        // оператор разыменования, возвращает элемент буфера, на который в данный момент указывает итератор
        T& operator*()
        {
            return buf->operator[](ind);
        }

        // оператор сравнения итераторов
        bool operator==(const iterator& that) const
        {
            return this->ind == that.ind;
        }

        // оператор сравнения итераторов
        bool operator!=(const iterator& that) const
        {
            return this->ind != that.ind;
        }

        // оператор сравнения итераторов
        bool operator<(const iterator& that) const
        {
            return this->ind < that.ind;
        }

        // оператор сравнения итераторов
        bool operator<=(const iterator& that) const
        {
            return this->ind <= that.ind;
        }

        // оператор сравнения итераторов
        bool operator>(const iterator& that) const
        {
            return this->ind > that.ind;
        }

        // оператор сравнения итераторов
        bool operator>=(const iterator& that) const
        {
            return this->ind >= that.ind;
        }

        iterator& operator++()
        {
            ind++;
            if (ind == buf->size())
            {
                ind = 0;
            }
            return *this;
        }

        iterator operator++(int)
        {
            iterator old = iterator(buf, ind);
            ind++;
            if (ind == buf->size())
            {
                ind = 0;
            }
            return old;
        }

        iterator& operator--()
        {
            ind--;
            if (ind == -1)
            {
                ind = buf->size() - 1;
            }
            return *this;
        }

        iterator operator--(int)
        {
            iterator old = iterator(buf, ind);
            ind--;
            if (ind == -1)
            {
                ind = buf->size() - 1;
            }
            return old;
        }

        // операция вставки нового элемента в позицию в буфере, на которую установлен итератор
        void insert(const T& element)
        {
            buf->insert(this->ind, element);
        }

        // операция удаления элемента из позицию в буфере, на которую установлен итератор
        void remove()
        {
            buf->remove(this->ind);
        }
    };

    // метод возарвщает итератор установленный на начальный элемент в буфере
    // если буфер пуст, то возвращает итератор равный тому, что возвращает метод end()
    iterator begin()
    {
        return (count != 0) ? iterator(this, 0) : end();
    }

    // метод возвращает итератор установденный на элемент "следующий за последним" (несуществующий)
    iterator end()
    {
        return iterator(this, count);
    }
};*/