#ifndef BYTE_H
#define BYTE_H

#include <string>
#include <vector>

std::string getFileName(const std::string& filePath);
std::string getFileBaseName(const std::string& fileName);
std::vector<unsigned char> readFile(const std::string& filePath);
void writeByteCodeToFile(const std::string& fileName, const std::vector<unsigned char>& data);
std::string openFileDialog();

#endif
