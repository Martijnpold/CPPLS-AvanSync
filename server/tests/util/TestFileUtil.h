#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <util/FileUtil.h>

namespace fs = std::filesystem;

class TestFileUtil {
public:
    static void deleteFile(const std::string& path) {
        try {
            fs::remove_all({FileUtil::encodeName(path)});
        } catch (std::exception& e) { std::cout << e.what() << std::endl; }
    }

    static void createFile(const std::string& path, char byte, int count) {
        try {
            std::ofstream stream {FileUtil::encodeName(path)};
            std::stringstream sstream {};
            for (int i = 0; i < count; i++)
                sstream << byte;
            stream << sstream.str();
            stream.close();
        } catch (std::exception& e) { std::cout << e.what() << std::endl; }
    }

    static void createDir(const std::string& path) {
        try {
            fs::create_directories(FileUtil::encodeName(path));
        } catch (std::exception& e) { std::cout << e.what() << std::endl; }
    }

    static bool exists(const std::string& path) {
        try {
            return fs::exists(FileUtil::encodeName(path));
        } catch (std::exception& e) { std::cout << e.what() << std::endl; }
        return false;
    }
};