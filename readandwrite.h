//
// Created by 123 on 2022/12/4.
//

#ifndef MAIN_CPP_READANDWRITE_H
#define MAIN_CPP_READANDWRITE_H

//块状链表相关
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

template<class T>
class basic_message {
public:
    T min;
    T max;
    int next;
    int prev;
};

template<class T>
class block {
public:
    T min;
    T max;
    int next_pos;
    int block_len;
    T data[2002];//用于存储数据的是1到2000

    const int max_size = 2000;
    const int min_size = 1000;


    block();

    void block_insert(T a);

    void block_delete(T a);
};

template<class T>
class block_linklist {
public:

    int length;
    int block_amount;
    int last;
    std::fstream main_data;
    const int end_pos = -1;
    block_linklist();

    ~block_linklist() = default;

    void insert(T a);

    void erase(T a);

    void split(int pos);

    void combine(int pos1, int pos2);

    T *find(T a);

    int find_pos(T a);

    void read_block(int pos, block<T> &cur);

    void write(int pos, block<T> &cur);

    basic_message<T> read_part(int pos);
};
//文件读写相关

#endif //MAIN_CPP_READANDWRITE_H
