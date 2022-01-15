#include <stdio.h>
#include <string.h>

/*
struct tag { 
    member-list
    member-list 
    member-list  
    ...
} variable-list, variable-list2;
*/

// 声明一个叫 Book 的结构体
struct Books {
   char title[50];
   char author[50];
   char subject[100];
   int book_id;
} book0 ={"C++", "Nobody", "Programming", 0};
// 在结尾新建一个 book0

// 新建多个结构体
struct Books book1, book2, book3, book4;

// 在 book1 中编辑
int part1() {
    // book1.title = "Differentiation";
    // book1.author = "John";
    // book1.subject = "Math";
    // book1.book_id = "1";
    strcpy(book1.title, "Differentiation");
    strcpy(book1.author, "John");
    strcpy(book1.subject, "Math");
    book1.book_id = 1;
    
    struct Books *struct_pointer;
    struct_pointer = &book1;
    struct_pointer->title;
}

int main() {
    part1();
}