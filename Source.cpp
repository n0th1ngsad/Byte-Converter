#include "Byte.h"
#include <iostream>

int main() {
    std::string filePath = openFileDialog();

    if (filePath.empty()) {
        std::cerr << "No file selected.\n";
        return 1;
    }

    std::vector<unsigned char> fileData = readFile(filePath);
    std::string fileName = getFileName(filePath);

    writeByteCodeToFile(fileName, fileData);

    std::cout << "File has been converted and saved to Convert.txt.\n";
    return 0;
}