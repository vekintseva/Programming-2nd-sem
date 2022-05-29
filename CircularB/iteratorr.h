//
// Created by Виктория on 28.05.2022.
//

#ifndef MAIN_CPP_ITERATORR_H
#define MAIN_CPP_ITERATORR_H
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

    // оператор смещения итератора вправо, префиксная форма (++iterator)
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
};
#endif //MAIN_CPP_ITERATORR_H
