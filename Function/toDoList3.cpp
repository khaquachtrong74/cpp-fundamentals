#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>

class Table
{
private:
    std::vector<std::vector<std::string>> table;
    int numbs;
    int col;

public:
    Table() : numbs(0), col(5)
    {
        table.resize(10, std::vector<std::string>(col));
        table[0][0] = "Numbs";
        table[0][1] = "Task";
        table[0][2] = "Time";
        table[0][3] = "Stage";
        table[0][4] = "Reward";
    }
    void view()
    {
        std::cout << std::setfill(' ') << std::endl;
        for (const auto &row : table)
        {
            for (const auto &cell : row)
            {
                std::cout << std::setw(30) << std::right << cell;
            }
            std::cout << std::endl;
        }
        // std::cout<<std::setw(30)<<std::setfill('-')<<std::setw(60)<<""<<std::setfill(' ')<<std::endl;
    }
    void addTask()
    {
        numbs++;
        if (numbs >= table.size())
        {
            table.resize(table.size() + 10, std::vector<std::string>(col));
        }
        std::string task;

        std::cout << "Input your new task: ";
        std::cin.ignore();
        getline(std::cin, task);
        std::time_t now = std::time(nullptr);
        std::tm *localTime = std::localtime(&now);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", localTime);
        table[numbs][0] = std::to_string(numbs);
        table[numbs][1] = task;
        table[numbs][2] = buffer;
        table[numbs][3] = "Not started.";
        table[numbs][4] = "Not rewards.";
        view();
    }
    void completeTask()
    {
        int idx;
        std::string reward;
        std::cout << "Input your finish task : (index) = ";
        std::cin >> idx;
        std::cout << "Input your reward: ";
        std::cin.ignore();
        getline(std::cin, reward);
        if (idx <= numbs && idx >= 0)
        {
            table[idx][3] = "Finish.";
            table[idx][4] = reward;
        }
        view();
    }
    void saveInformation()
    {
        std::ofstream saveInfo("saveInfo.txt", std::ios::app);
        if (saveInfo.is_open())
        {
            saveInfo << std::setfill(' ') << std::endl;
            for (const auto &row : table)
            {
                for (const auto &cell : row)
                {
                    saveInfo << std::setw(30) << std::right << cell;
                }
                saveInfo << std::endl;
            }
        }
    }
};
void menu()
{
    std::cout << "Menu\n1. Add task\n2. Finish task\n0. End program\n";
}
int main()
{
    Table test;
    int luaChon = 0;
    while (true)
    {
        system("cls");
        
        test.view();
        menu();
        std::cin >> luaChon;
        switch (luaChon)
        {
        case 1:
            /* code */
            test.addTask();
            break;
        case 2:
            test.completeTask();
            break;
        case 0:
            test.saveInformation();
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}