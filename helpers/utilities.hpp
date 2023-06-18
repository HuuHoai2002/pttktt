#include <string>
#include <iostream>
#include <fstream>
#include <vector>

/**
 * Print any type of data
 * @param str: Dữ liệu cần in ra màn hình
 */
template <typename T>
void print(T str)
{
    std::cout << str << std::endl;
}

/**
 * Hàm đọc file có một dòng, dữ liệu là nhiều số nguyên cách nhau bởi dấu cách
 * Độ phức tạp: O(n)
 * @param fileName: Tên file cần đọc
 * @param data: Mảng chứa dữ liệu đọc được từ file
 */
void readFileSpaceSeparated(std::string fileName, std::vector<int> &data)
{
    std::ifstream file(fileName);
    std::string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::string temp = "";
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ' ')
                {
                    data.push_back(std::stoi(temp));
                    temp = "";
                }
                else
                {
                    temp += line[i];
                }
            }
            data.push_back(std::stoi(temp));
        }
        file.close();
    }
}

/**
 *  Hàm đọc file có nhiều dòng, mỗi dòng có nhiều số nguyên cách nhau bởi dấu cách
 *  Độ phức tạp: O(n)
 * @param fileName: Tên file cần đọc
 * @param data: Mảng 2 chiều chứa dữ liệu đọc được từ file
 */
void readFileSpaceSeparatedMultipleLines(std::string fileName, std::vector<std::vector<int>> &data)
{
    std::ifstream file(fileName);
    std::string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::vector<int> temp;
            std::string tempStr = "";
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ' ')
                {
                    temp.push_back(std::stoi(tempStr));
                    tempStr = "";
                }
                else
                {
                    tempStr += line[i];
                }
            }
            temp.push_back(std::stoi(tempStr));
            data.push_back(temp);
        }
        file.close();
    }
}

void sortAsc(std::vector<int> &data)
{
    for (int i = 0; i < data.size() - 1; i++)
    {
        for (int j = i + 1; j < data.size(); j++)
        {
            if (data[i] > data[j])
            {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void sortDesc(std::vector<int> &data)
{
    for (int i = 0; i < data.size() - 1; i++)
    {
        for (int j = i + 1; j < data.size(); j++)
        {
            if (data[i] < data[j])
            {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

enum SortType
{
    ASC,
    DESC
};

void toSortedArray(std::vector<int> &data, SortType type = ASC)
{
    switch (type)
    {
    case ASC:
        sortAsc(data);
        break;
    case DESC:
        sortDesc(data);
        break;
    default:
        sortAsc(data);
        break;
    }
}