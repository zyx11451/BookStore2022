//
// Created by 123 on 2022/12/4.
//
#include "user.h"
#include "error.h"
#include "readandwrite.h"
extern block_linklist<user> users("users");
extern block_linklist<Book> books("books");
extern std::vector<selection> current;
password_type::password_type() {
    a[0]='\0';
}
password_type::password_type(std::string b) {
    if(b.length()>30) error();
    else{
        for(int i=0;i<b.length();++i){
            if((b[i]>='a'&&b[i]<='z')||
               (b[i]>='A'&&b[i]<='Z')||
               (b[i]>='0'&&b[i]<='9')||
               (b[i]=='_')){
                a[i]=b[i];
            }
            else error();
        }
        a[b.length()]='\0';
    }
}
password_type &password_type::operator=(const password_type &b){
    for(int i=0;i<=30;++i){
        a[i]=b.a[i];
    }
    return *this;
}
bool password_type::operator==(const password_type &b){
    return strcmp(a,b.a)==0;
}
name_type::name_type() {
    a[0]='\0';
}
name_type::name_type(std::string b) {
    if(b.length()>30) error();
    else{
        for(int i=0;i<b.length();++i){
            a[i]=b[i];
        }
        a[b.length()]='\0';
    }
}
name_type &name_type::operator=(const name_type &b){
    for(int i=0;i<=30;++i){
        a[i]=b.a[i];
    }
    return *this;
}
user::user(std::string user_id_,std::string password_,std::string name_,int privilege_){
    user_id=user_id_;
    password=password_;
    name=name_;
}

void user::log_in(password_type user_id) {
    user temp;
    ISBN nothing;
    temp.user_id=user_id;
    if(users.find(temp)== nullptr){
     error();
    }else{
        if(users.find(temp)->privilege<privilege){
            selection s;
            s.now_user_id=user_id;
            s.now_book=nothing;
            current.push_back(s);
        }else{
            error();
        }
    }
}

void user::log_in(password_type user_id,password_type password){
    user temp;
    ISBN nothing;
    temp.user_id=user_id;
    if(users.find(temp)== nullptr){
        error();
    }else{
        if(users.find(temp)->password==password){
            selection s;
            s.now_user_id=user_id;
            s.now_book=nothing;
            current.push_back(s);
        }else{
            error();
        }
    }
}