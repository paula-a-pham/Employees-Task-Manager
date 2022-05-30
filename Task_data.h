#ifndef TASK_DATA_H
#define TASK_DATA_H

#include<iostream>
//use ctime liberary to handel date;
#include <ctime>
//use cstdlib liberary to use atoi fun to convert string to intger;
#include <cstdlib>
//use fstream liberary to write and read files;
#include <fstream>
#include <string>
//use unordered map liberary to store user info;
#include <unordered_map>

using namespace std;
//make a new data type to store date;
struct date_details
{
    int day = 0, month = 0, year = 0;
};
class Task_data
{
//use private to achive encapsulation concept of oop;
private:
    string task_name , task_description;
    int task_priority , index;
    date_details start_date, deadline_date;
public:
    //check if date valid or not;
    bool check_date(date_details start , date_details deadline);
    //use partition, quicksort and sorting tasks to sort tasks in arry;
    int partition(Task_data arr[], int start, int end);
    void quickSort(Task_data arr[], int start, int end);
    void sorting_task(Task_data arr_list[], int count);
    //get and set all atribute to use it in different classes;
    const string &getTask_name() const;
    void setTask_name(const string &newTask_name);
    const string &getTask_description() const;
    void setTask_description(const string &newTask_description);
    int getTask_priority() const;
    void setTask_priority(int newTask_priority);
    int getIndex() const;
    void setIndex(int newIndex);
    const date_details &getStart_date() const;
    void setStart_date(const date_details &newStart_date);
    const date_details &getDeadline_date() const;
    void setDeadline_date(const date_details &newDeadline_date);
};

#endif // TASK_DATA_H
