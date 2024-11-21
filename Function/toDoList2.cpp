#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <ctime>
// my menu of function
static int point = 0;
void displayMenu()
{
    std::cout << "1. Add a new task\n"
              << "2. Complete a task\n"
            //   << "3. View all tasks\n"
              << "3. Delete a task\n"
              << "0. Save and exit\n";
}
// has missions create and add tasks in lists
void addTask(std::vector<std::string> &tasks)
{
    std::string task;
    std::cout << "Enter your new task: ";
    std::cin.ignore();
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added successfully!\n";
}
// finish task and save it on another file
void completeTask(std::vector<std::string> &tasks)
{
    if (tasks.empty())
    {
        std::cout << "No tasks to complete.\n";
        return;
    }
    std::ofstream saveCompleteTasks("CompletesTask.txt", std::ios::app);
    int index;
    std::cout << "Enter the number of the task you've completed: ";
    std::cin >> index;

    if (index < 1 || index > static_cast<int>(tasks.size()))
    {
        std::cout << "Invalid task number. Please try again.\n";
        return;
    }
    if (saveCompleteTasks.is_open())
    {
        std::cout << "Completed task: " << tasks[index - 1] << std::endl;
        saveCompleteTasks << "Finish : " << tasks[index - 1] << std::endl;
        point++;
        tasks.erase(tasks.begin() + index - 1);
    }
    saveCompleteTasks.close();
}

void viewTasks(const std::vector<std::string> &tasks)
{
    if (tasks.empty())
    {
        std::cout << "No tasks in the list.\n";
    }
    else
    {
        std::cout << "Your tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
        }
    }
}

void deleteTask(std::vector<std::string> &tasks)
{
    if (tasks.empty())
    {
        std::cout << "No tasks to delete.\n";
        return;
    }

    int index;
    std::cout << "Enter the number of the task you want to delete: ";
    std::cin >> index;

    if (index < 1 || index > static_cast<int>(tasks.size()))
    {
        std::cout << "Invalid task number. Please try again.\n";
        return;
    }

    std::cout << "Deleted task: " << tasks[index - 1] << std::endl;
    tasks.erase(tasks.begin() + index - 1);
}
void saveTask(std::vector<std::string> &tasks)
{
    // save any task not complete
    std::ofstream writeFile("task.txt", std::ios::app);
    if (writeFile.is_open())
    {
        int i = 1;
        for (auto x : tasks)
        {
            writeFile << "Task is not finish:" << i << " " << x << std::endl;
            i++;
        }
    }
    writeFile.close();
}
int main()
{
    std::vector<std::string> tasks;
    int choice;
    std::time_t now = std::time(nullptr);

    // transfer it in to string
    std::tm *local_time = std::localtime(&now);
    std::ofstream taskTxt("task.txt", std::ios::app);
    std::ofstream cplTask("CompletesTask.txt", std::ios::app);
    if (taskTxt.is_open() && cplTask.is_open())
    {
        taskTxt << "Time now: " << asctime(local_time) << std::endl;
        cplTask << "Time now: " << asctime(local_time) << std::endl;
    }
    while (true)
    {
        
        system("cls");
        displayMenu();
        viewTasks(tasks);
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "Saving and exiting. Goodbye!\n";
            saveTask(tasks);
            std::cout<<"\n Wow to day you have "<<point<<" point.\n Ho ray!"<<std::endl;
            return 0;
        case 1:
            addTask(tasks);
            break;
        case 2:
            completeTask(tasks);
            break;
        case 3:
            deleteTask(tasks);
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << std::endl;
    }

    return 0;
}
