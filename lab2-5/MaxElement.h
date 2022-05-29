//
// Created by Виктория on 07.04.2022.
//

#pragma once

template <typename TMax> //означает, что в алгоритме используется какой-то абстрактный тип TМах;

TMax MaxElement(TMax* array, TMax N) {
    TMax max = array[0];
    for (int i = 0; i < N; i++)
    {
        if (max < array[i])
            max = array[i];
    }
    return max;
}