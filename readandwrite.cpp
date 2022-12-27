//
// Created by 123 on 2022/12/4.
//
#include "readandwrite.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
template<class T>
block<T>::block() {
    block_len = 0;
}

template<class T>
void block<T>::block_insert(T a) {
    if (block_len == 0) {
        max = a;
        min = a;
        block_len++;
        data[1] = a;
        return;
    }
    int i = 1;
    if (a < min) min = a;
    if (a > max) {
        max = a;
        block_len++;
        data[block_len] = a;
    } else {
        for (; i <= block_len; ++i) {

            if (a <= data[i]) break;
        }
        T now_moving = data[i];
        T next_moving = data[i + 1];
        data[i] = a;
        for (; i <= block_len; ++i) {
            data[i + 1] = now_moving;
            now_moving = next_moving;
            next_moving = data[i + 2];
        }
        block_len++;
    }
}

template<class T>
void block<T>::block_delete(T a) {
    bool flag = false;
    int i = 1;
    for (; i <= block_len; ++i) {
        if (a == data[i]) {
            flag = true;
            break;
        }
        if (a < data[i]) break;
    }
    if (!flag) return;
    for (; i < block_len; ++i) {
        data[i] = data[i + 1];
    }
    block_len--;
    min = data[1];
    max = data[block_len];
}

template<class T>
block_linklist<T>::block_linklist() {
    length = 0;
    main_data.open("test");
    block<T> head;
    if (!main_data) {
        main_data.open("test", std::ios::out);
        main_data.close();
        main_data.open("test");
        head.next_pos = -1;
        main_data.seekp(0);
        main_data.write(reinterpret_cast<char *>(&head), sizeof(head));
        last = 0;
        length = 1;
        block_amount = 0;//块位置的最大值
    }else{
        length=0;
        block_amount=0;
        block<T> cur;
        for(int i=0;i!=-1;i=cur.next_pos){
            read_block(i,cur);
            if(cur.next_pos==-1) last=i;
            if(cur.next_pos>block_amount) block_amount=cur.next_pos;
            length++;
        }
    }
}

template<class T>
void block_linklist<T>::read_block(int pos, block<T> &cur) {
    main_data.seekg(pos * sizeof(block<T>));
    main_data.read(reinterpret_cast<char *>(&cur), sizeof(block<T>));
}

template<class T>
void block_linklist<T>::write(int pos, block<T> &cur) {
    main_data.seekp(pos * sizeof(block<T>));
    main_data.write(reinterpret_cast<char *>(&cur), sizeof(block<T>));
}

template<class T>
basic_message<T> block_linklist<T>::read_part(int pos) {
    basic_message<T> ans;
    main_data.seekg(pos * sizeof(block<T>));
    main_data.read(reinterpret_cast<char *>(&ans.min), sizeof(ans.min));
    main_data.read(reinterpret_cast<char *>(&ans.max), sizeof(ans.max));
    main_data.read(reinterpret_cast<char *>(&ans.next), sizeof(ans.next));
    main_data.read(reinterpret_cast<char *>(&ans.prev), sizeof(ans.prev));
    return ans;
}

template<class T>
int block_linklist<T>::find_pos(T a) {
    block<T> temp;
    basic_message<T> cur;
    int i;
    for (i = 0; i != -1; i = cur.next) {
        cur = read_part(i);
        if (a >= cur.min && a <= cur.max) break;
    }
    return i;
}

template<class T>
T *block_linklist<T>::find(T a) {
    int pos = find_pos(a);
    block<T> temp;
    read_block(pos, temp);
    for (int i = 1; i <= temp.block_len; ++i) {
        if (temp.data[i] == a) return *temp.data[i];
        if (temp.data[i] > a) break;
    }
    return nullptr;
}

template<class T>
void block_linklist<T>::insert(T a) {
    block<T> to_add;
    basic_message<T> cur;
    int i;
    if (length == 1) i = 0;
    else {
        for (i = 0; i != -1; i = cur.next) {
            cur = read_part(i);
            if (cur.max >= a) break;
        }
    }
    if (i == -1) {
        read_block(last, to_add);
        i = last;
    } else read_block(i, to_add);
    to_add.block_insert(a);
    write(i, to_add);
    if (to_add.block_len >= to_add.max_size) split(i);
}

template<class T>
void block_linklist<T>::split(int pos) {
    block_amount++;
    block<T> temp;
    read_block(pos, temp);
    block<T> new_block;
    if (pos == last) last = block_amount;
    new_block.next_pos = temp.next_pos;
    temp.next_pos = block_amount;
    temp.block_len = temp.min_size;
    new_block.block_len = new_block.min_size;
    for (int i = 1; i <= temp.min_size; ++i) {
        new_block.data[i] = temp.data[temp.min_size + i];
    }
    new_block.min = new_block.data[1];
    new_block.max = new_block.data[new_block.min_size];
    temp.max = temp.data[temp.min_size];
    length++;
    write(pos, temp);
    write(block_amount, new_block);
}

template<class T>
void block_linklist<T>::combine(int pos1, int pos2) {
    length--;
    block<T> temp1;
    block<T> temp2;
    read_block(pos1, temp1);
    read_block(pos2, temp2);
    if (temp1.block_len + temp2.block_len < temp1.max_size) {
        for (int i = 1; i <= temp2.block_len; ++i) {
            temp1.data[temp1.block_len + i] = temp2.data[i];
        }
        temp1.block_len = temp1.block_len + temp2.block_len;
        temp1.max = temp1.data[temp1.block_len];
        length--;
        temp1.next_pos = temp2.next_pos;
    }
    write(pos1, temp1);
}

template<class T>
void block_linklist<T>::erase(T a) {
    int pos;
    pos = find_pos(a);
    if (pos == -1) return;
    block<T> temp;
    read_block(pos, temp);
    temp.block_delete(a);
    write(pos, temp);
    if (temp.next_pos != -1 && temp.block_len < temp.min_size) {
        combine(pos, temp.next_pos);
    }
}
