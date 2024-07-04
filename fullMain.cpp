#include<bits/stdc++.h>
#include <string>

using namespace std;

int listsize=0;

struct Task
{
    string name;
    string dueDate;

    void display()
    {
        cout << "Task: " << name << endl;
        cout << "Due Date: " << dueDate << endl;
    }
};

class ToDoList
{
private:
    vector<Task> tasks;

public:

    void addTask()
    {
        Task newTask;
        fflush(stdin);
        cout << "Enter task name: ";
        getline(cin, newTask.name);
        fflush(stdin);
        cout << "Enter due date (DD-MM-YYYY format): ";
        getline(cin, newTask.dueDate);


        tasks.push_back(newTask);
        listsize++;
        cout << "\nTask added successfully!" << endl;
    }

    void removeTask()
    {
        if (tasks.empty())
        {
            cout << "List is empty!" << endl;
            return;
        }

        int choice=0;
        cout << "\nTasks:" << endl;
        for (Task i:tasks)
        {
            cout << choice + 1 << ". ";
            choice++;
            i.display();
        }
        cout<<endl;
        cout << "Enter task number to remove: ";
        cin >> choice;

        if (choice > 0 && choice <= listsize)
        {
            tasks.erase(tasks.begin() + choice - 1);
            listsize--;
            cout << "\nTask removed successfully!" << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    void viewTasks()
    {
        if (tasks.empty())
        {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "\nTasks:" << endl;
        for (Task i : tasks)
        {
            i.display();
            cout << endl;
        }
    }
};

int main()
{
    ToDoList data;
    int choice;

    while (true)
    {
        cout << "\nTo-Do List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl;
        switch (choice)
        {
        case 1:
            data.addTask();
            break;
        case 2:
            data.removeTask();
            break;
        case 3:
            data.viewTasks();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
