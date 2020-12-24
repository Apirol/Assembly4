#include <fstream>
#include <iostream>

extern "C" void  REPLACE(char* initial_data, char* modified_data, char x, char y);
void Input(char* data, int file_size, char& x, char& y);
void Output(char* data, int file_size);


int main()
{
    const int size = 1024;
    char initial_data[size], modified_data[size], x, y;
    try
    {
        Input(initial_data, size, x, y);
        REPLACE(initial_data, modified_data, x, y);
        Output(modified_data, size);
    }
    catch (const char* msg)
    {
        std::cout << msg << std::endl;
    }

}

void Input(char* data, int file_size, char& x, char& y)
{
    std::ifstream input_file;
    std::string file_name;
    std::cout << "Enter the file name: ";
    std::cin >> file_name;

    input_file.open(file_name);
    if (!input_file.is_open())
        throw "Something wrong with file..";

    input_file.read(data, file_size);
    input_file.close();

    std::cout << "Enter a symbol to replace" << std::endl;
    std::cin >> x;

    std::cout << "Enter a symbol you want to replace" << std::endl;
    std::cin >> y;
}

void Output(char* data, int file_size)
{
    std::ofstream output_file;
    output_file.open("output.txt");
    output_file << data;
    output_file.close();
}
