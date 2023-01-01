//
// Created by 123 on 2022/12/4.
//
#include "book.h"
#include "error.h"
#include <cstring>

ISBN::ISBN() {
    a[0] = '\0';
}

ISBN::ISBN(std::string b) {
    if (b.length() > 20) error();
    else {
        for (int i = 0; i < b.length(); ++i) {
            a[i] = b[i];
        }
        a[b.length()] = '\0';
    }
}

bool ISBN::operator==(const ISBN &b) {
    return strcmp(a, b.a) == 0;
}

bool ISBN::operator!=(const ISBN &b) {
    return strcmp(a, b.a) != 0;
}

bool ISBN::operator<(const ISBN &b) {
    return strcmp(a, b.a) < 0;
}

bool ISBN::operator>(const ISBN &b) {
    return strcmp(a, b.a) > 0;
}

bool ISBN::operator<=(const ISBN &b) {
    return strcmp(a, b.a) <= 0;
}

bool ISBN::operator>=(const ISBN &b) {
    return strcmp(a, b.a) >= 0;
}
ISBN &ISBN::operator=(const ISBN &b) {
    for(int i=0;i<21;++i){
        a[i]=b.a[i];
    }
    return *this;
}

my_string::my_string() {
    a[0] = '\0';
}

my_string::my_string(std::string b) {
    if (b.length() > 60) error();
    else {
        for (int i = 0; i < b.length(); ++i) {
            a[i] = b[i];
        }
        a[b.length()] = '\0';
    }
}

bool my_string::operator==(const my_string &b) {
    return strcmp(a, b.a) == 0;
}

bool my_string::operator!=(const my_string &b) {
    return strcmp(a, b.a) != 0;
}

bool my_string::operator<(const my_string &b) {
    return strcmp(a, b.a) < 0;
}

bool my_string::operator>(const my_string &b) {
    return strcmp(a, b.a) > 0;
}

bool my_string::operator<=(const my_string &b) {
    return strcmp(a, b.a) <= 0;
}

bool my_string::operator>=(const my_string &b) {
    return strcmp(a, b.a) >= 0;
}

my_string &my_string::operator=(const my_string &b) {
    for(int i=0;i<61;++i){
        a[i]=b.a[i];
    }
    return *this;
}

Book::Book(std::string book_name_,
           std::string author_,
           std::string isbn_,
           std::string keyword_,
           int quantity_,
           double price_) {
    book_name=book_name_;
    author=author_;
    quantity=quantity_;
    price=price_;
    isbn=isbn_;
    my_string temp;
    int key_number=0;
    int temp_now=0;
    for(int i=0;i<keyword_.length();++i){
        if(keyword_[i]!='|'){
            temp.a[temp_now]=keyword_[i];
            temp_now++;
        }else{
            temp.a[temp_now+1]='\0';
            key_word[key_number]=temp;
            key_number++;
            for(int j=1;j<=temp_now+1;++j){
                temp.a[j]=0;
            }
            temp.a[0]='\0';
            temp_now=0;
        }
    }
    temp.a[temp_now]='\0';
    key_word[key_number]=temp;
}