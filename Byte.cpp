#include "byte.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

std::string getFileName(const std::string& filePath) {
    size_t pos = filePath.find_last_of("\\/");
    return (pos == std::string::npos) ? filePath : filePath.substr(pos + 1);
}

std::string getFileBaseName(const std::string& fileName) {
    size_t pos = fileName.find_last_of(".");
    return (pos == std::string::npos) ? fileName : fileName.substr(0, pos);
}

std::vector<unsigned char> readFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    return std::vector<unsigned char>((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

void writeByteCodeToFile(const std::string& fileName, const std::vector<unsigned char>& data) {
    std::ofstream outputFile("Convert.txt");
    if (outputFile.is_open()) {
        std::string variableName = getFileBaseName(fileName);
        outputFile << "unsigned char " << variableName << "[" << data.size() << "] = {\n";

        for (size_t i = 0; i < data.size(); ++i) {
            outputFile << "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i]);
            if (i < data.size() - 1) {
                outputFile << ",";
            }
            if ((i + 1) % 16 == 0) { 
                outputFile << "\n";
            }
        }

        outputFile << "\n};\n";
        outputFile.close();
    }
    else {
        std::cerr << "Error: Unable to open file for writing.\n";
    }
}

std::string openFileDialog() {
    OPENFILENAME ofn;      
    char fileName[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;  
    ofn.lpstrFilter = "All Files\0*.*\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn)) {
        return std::string(fileName);
    }

    return "";
}
