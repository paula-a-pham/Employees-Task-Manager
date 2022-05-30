#include "Task_data.h"

const string &Task_data::getTask_name() const
{
    return task_name;
}

void Task_data::setTask_name(const string &newTask_name)
{
    task_name = newTask_name;
}

const string &Task_data::getTask_description() const
{
    return task_description;
}

void Task_data::setTask_description(const string &newTask_description)
{
    task_description = newTask_description;
}

int Task_data::getTask_priority() const
{
    return task_priority;
}

void Task_data::setTask_priority(int newTask_priority)
{
    task_priority = newTask_priority;
}

int Task_data::getIndex() const
{
    return index;
}

void Task_data::setIndex(int newIndex)
{
    index = newIndex;
}

const date_details &Task_data::getStart_date() const
{
    return start_date;
}

void Task_data::setStart_date(const date_details &newStart_date)
{
    start_date = newStart_date;
}

const date_details &Task_data::getDeadline_date() const
{
    return deadline_date;
}

void Task_data::setDeadline_date(const date_details &newDeadline_date)
{
    deadline_date = newDeadline_date;
}
//check if date valid or not;
bool Task_data::check_date(date_details start , date_details deadline)
{
    time_t ttime = time(0);
    int x, y, z;
    tm* local_time = localtime(&ttime);
    x = local_time->tm_mday;
    y = 1 + local_time->tm_mon;
    z = 1900 + local_time->tm_year;
    if (start.year >= z && deadline.year >= start.year)
    {
        if(start.month == y && deadline.month == start.month)
        {
            if(start.day >= x && deadline.day >= start.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(start.month == y && deadline.month > start.month)
        {
            if(start.day >= x)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(start.month > y && deadline.month == start.month)
        {
            if(deadline.day >= start.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(start.month > y && deadline.month > start.month)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int Task_data::partition(Task_data arr[], int start, int end)
{
    Task_data pivot = arr[start];

    int count_2 = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i].task_priority >= pivot.task_priority)
            count_2++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count_2;
    swap(arr[pivotIndex], arr[start]);
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i].task_priority >= pivot.task_priority)
        {
            i++;
        }
        while (arr[j].task_priority < pivot.task_priority)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

//quickSort array for sorting_task fun;
void Task_data::quickSort(Task_data arr[], int start, int end)
{
    // base case
    if (start >= end)
        return;
    // partitioning the array
    int p = partition(arr, start, end);
    // Sorting the left part
    quickSort(arr, start, p - 1);
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

//sort task refrence this periority with dessnding order;
void Task_data::sorting_task(Task_data arr_list[], int count)
{
    quickSort(arr_list, 0, count - 1);
}
