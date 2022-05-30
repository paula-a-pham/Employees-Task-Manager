// include all liberaries we need;
#include "Users.h"

int Users::getCount_draft() const
{
    return count_draft;
}

void Users::setCount_draft(int newCount_draft)
{
    count_draft = newCount_draft;
}

int Users::getSize_draft() const
{
    return size_draft;
}

void Users::setSize_draft(int newSize_draft)
{
    size_draft = newSize_draft;
}

int Users::getCount() const
{
    return count;
}

void Users::setCount(int newCount)
{
    count = newCount;
}

int Users::getSize() const
{
    return size;
}

void Users::setSize(int newSize)
{
    size = newSize;
}

int Users::getCount_done() const
{
    return count_done;
}

void Users::setCount_done(int newCount_done)
{
    count_done = newCount_done;
}

int Users::getSize_done() const
{
    return size_done;
}

void Users::setSize_done(int newSize_done)
{
    size_done = newSize_done;
}


Task_data *Users::getArr_list() const
{
    return arr_list;
}

void Users::setArr_list(Task_data *newArr_list)
{
    arr_list = newArr_list;
}

Task_data *Users::getDraft_list() const
{
    return draft_list;
}

void Users::setDraft_list(Task_data *newDraft_list)
{
    draft_list = newDraft_list;
}

Task_data *Users::getDone_list() const
{
    return done_list;
}

void Users::setDone_list(Task_data *newDone_list)
{
    done_list = newDone_list;
}
//constructor fun;
Users::Users()
{
    count = count_draft = count_done = 0;
    size = size_draft = size_done = 20;
    arr_list = new Task_data[size];
    draft_list = new Task_data[size_draft];
    done_list = new Task_data[size_done];
}
//check deadline date for all tasks in array after read it and store expired tasks in draft list;
void Users::check_task()
{
    time_t ttime = time(0);
        int x, y, z;
        tm* local_time = localtime(&ttime);
        x = local_time->tm_mday;
        y = 1 + local_time->tm_mon;
        z = 1900 + local_time->tm_year;
        for (int i = 0; i < count; i++)
        {
            if (arr_list[i].getDeadline_date().year >= z)
            {
                if (arr_list[i].getDeadline_date().month == y)
                {
                    if (arr_list[i].getDeadline_date().day < x)
                    {
                        if (count_draft == size_draft)
                            arr_expand("draft");
                        draft_list[count_draft] = arr_list[i];
                        count_draft++;
                        arr_delete_at(i, "array");
                    }
                }
                else if (arr_list[i].getDeadline_date().month < y)
                {
                    if (count_draft == size_draft)
                        arr_expand("draft");
                    draft_list[count_draft] = arr_list[i];
                    count_draft++;
                    arr_delete_at(i, "array");
                }
            }
            else
            {
                if (count_draft == size_draft)
                    arr_expand("draft");
                draft_list[count_draft] = arr_list[i];
                count_draft++;
                arr_delete_at(i, "array");
            }
        }
}
//add a new task to list;
int Users::add_task(Task_data* task)
{
    if (arr_full(count, size))
        arr_expand("array");
    arr_list[count].setTask_name(task->getTask_name());
    arr_list[count].setTask_description(task->getTask_description());
    arr_list[count].setTask_priority(task->getTask_priority());
    arr_list[count].setStart_date(task->getStart_date());
    arr_list[count].setDeadline_date(task->getDeadline_date());
    count++;
    arr_list->sorting_task(arr_list, count);
    for(int i = 0 ; i<count ; i++)
    {
        arr_list[i].setIndex(i);
    }
    return arr_list[(count - 1)].getIndex();
}
//delete function from array when it done;
void Users::finish_task(string name , int index)
{
    if (name == "array")
    {
        if(arr_full(count_done,size_done))
            arr_expand("done");

        done_list[count_done] = arr_list[index];

        count_done++;
        arr_delete_at(index , name);
    }
    else
    {
        if(arr_full(count_done,size_done))
            arr_expand("done");
        done_list[count_done] = draft_list[index];
        count_done++;
        arr_delete_at(index , name);
    }
}
//add a new places in array;
void Users::arr_expand(string txt)
{
    if(txt == "array")
    {
        size += 1;
        Task_data* temp_arr = new Task_data[size];
        for (int i = 0; i < count; i++)
            temp_arr[i] = arr_list[i];
        delete[] arr_list;
        arr_list = temp_arr;
    }
    else if(txt == "draft")
    {
        size += 1;
        Task_data* temp_arr = new Task_data[size];
        for (int i = 0; i < count_draft; i++)
            temp_arr[i] = draft_list[i];
        delete[] draft_list;
        draft_list = temp_arr;
    }
    else
    {
        size += 1;
        Task_data* temp_arr = new Task_data[size];
        for (int i = 0; i < count_done; i++)
            temp_arr[i] = done_list[i];
        delete[] done_list;
        done_list = temp_arr;
    }
}
//delete data from spesific index;
void Users::arr_delete_at(int pos , string name)
{
    if (name == "array")
    {
        for (int i = pos; i <= (count - 1); i++)
            arr_list[i] = arr_list[i + 1];
        count--;
    }
    else
    {
        for (int i = pos; i <= (count_draft - 1); i++)
            draft_list[i] = draft_list[i + 1];
        count_draft--;
    }
}


//check if array empty;
bool Users::arr_empty(int count)
{
    return (count == 0);
}
//check if array full;
bool Users::arr_full(int count, int size)
{
    return (count == size);
}

//destructor of array;
Users::~Users()
{
    delete[] arr_list;
    delete[] draft_list;
    delete[] done_list;
}
