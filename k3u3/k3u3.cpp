#include <fstream>
#include <iostream>

int main2() {
    std::ofstream file1("file1.bin", std::ios::binary | std::ios::out);
    std::ofstream file2("file2.bin", std::ios::binary | std::ios::out);

    if (!file1 || !file2) {
        std::cerr << "Error opening files\n";
        return 1;
    }

    int data1[] = {1, 2, 3, 4, 5};
    int data2[] = {6, 7, 8, 9, 10};

    file1.write(reinterpret_cast<char*>(data1), sizeof(data1));
    file2.write(reinterpret_cast<char*>(data2), sizeof(data2));

    file1.close();
    file2.close();

    return 0;
}