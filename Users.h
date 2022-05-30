#ifndef USERS_H
#define USERS_H
//include task data.h to inherite all thing in it;
#include "Task_data.h"
class Users
{
//use private to achive encapsulation concept of oop;
private:
    Task_data* arr_list;
    Task_data* draft_list;
    Task_data* done_list;
    int count, count_draft, count_done;
    int size, size_draft, size_done;
public:
    //constructor fun;
    Users();
    //check deadline date for all tasks in array after read it and store expired tasks in draft list;
    void check_task();
    //add new task to array;
    int add_task(Task_data* task);
    //delete task from array and move it to done list;
    void finish_task(string name , int index);
    //add more places in array when it full;
    void arr_expand(string txt);
    //delete data from spesific index;
    void arr_delete_at( int pos , string name);
    //check if array is empty;
    bool arr_empty(int count);
    //check if array is full or not;
    bool arr_full(int count, int size);
    //destructor fun;
    ~Users();
    //get and set all atribute to use it in different classes;
    int getCount_draft() const;
    void setCount_draft(int newCount_draft);
    int getSize_draft() const;
    void setSize_draft(int newSize_draft);
    int getCount() const;
    void setCount(int newCount);
    int getSize() const;
    void setSize(int newSize);
    int getCount_done() const;
    void setCount_done(int newCount_done);
    int getSize_done() const;
    void setSize_done(int newSize_done);
    Task_data *getArr_list() const;
    void setArr_list(Task_data *newArr_list);
    Task_data *getDraft_list() const;
    void setDraft_list(Task_data *newDraft_list);
    Task_data *getDone_list() const;
    void setDone_list(Task_data *newDone_list);
};

#endif // USERS_H
