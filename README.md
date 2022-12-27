# BookStore 2022

这是大一程序设计课大作业，目的在于实现一个简单的书店管理系统

### 程序功能概述

账户系统：实现账户的记录，登入，登出，删除，创建，密码修改操作

图书系统：实现图书信息的记录、修改（包括购买时数量的变化）、查询、创建、删除

日志系统：实现交易记录的查询、展示

### 主体逻辑说明

创建一个user的基类和owner，assistant，visitor派生类，通过虚函数实现一些操作在不同权限下的差异

创建一个Book类来实现图书信息的存储

对于处理图书名、用户名无法重复，分别用一个set来保存已有的名字

在主程序中，实时更新当前选定的图书和当前正在操作的人，并通过vector来记录正在登录状态的人

其余信息分别保存在文件中，实时读取需要的部分并进行修改

### 代码文件结构

readandwrite负责文件的读写（包括图书信息文件、用户信息文件和日志文件）。

user负责存储用户信息和实现大部分和用户操作相关的函数。

log负责实现日志的查询与展示。

book负责图书类的定义。

指令的读入与理解在main.cpp中进行（目前的想法）

### 各个类的接口与成员函数说明
user.h:

    class user {

    private:

    int user_id;//用户id

    std::string password;//密码

    std::string name;//用户名

    public:

    user();//构造函数

    ~user();//析构函数

    virtual void log_in(int user_id);//登入

    virtual void log_out(int user_id);//登出

    virtual void change_password(int user_id);//更改密码

    virtual void delete_user(int user_id);//删除用户

    virtual void add_user();//添加用户

    virtual void user_register();//用户注册

    virtual void buy(std::string, int);//图书购买

    virtual void show();//图书信息展示

    virtual void select(std::string);//图书选择

    virtual void book_modify(std::string);//图书信息更改

    virtual void book_import(int quantity, double total_cost);//进货
    };
book.h:

    class Book {//图书信息

    private:

    std::string book_name;

    std::string author;

    std::string isbn;

    std::string key_word;

    int quantity;

    double price;

    public:

    friend user;

    };

readandwrite.h:

    template<class T>

    class block_linklist {//块状链表

    struct node {

    T *a;

    node *prev;

    node *next;

    };

    node *head;

    node *end;

    public:

    block_linklist();//构造函数

    ~block_linklist();//析构函数

    void insert(T a);//插入

    void erase(T a);//删除

    T *find(T a);//查找

    };

### 其他

可能之后在实现过程中，为了判断是否合法指令，添加一些用于判断格式是否正确的函数。

