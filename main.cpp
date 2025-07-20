#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    //conf
    std::string manageDirectoryPath = "C:/Users/xuan/Downloads"; // path to the desired folder
    //----
    fs::path basePath = manageDirectoryPath;
    for (const auto& entry : fs::directory_iterator(basePath)) { //loop through files in folder
        fs::path srcPath = entry.path();
        fs::path destPath;
        if (entry.path().filename() == "desktop.ini" || entry.is_directory()) {
            continue; // Skip 'desktop.ini' file and directories
        }

        if(!fs::exists(entry.path().extension())) { 
            // Check if the extension directory exists
            // Create a directory for the file's extension if it doesn't exist
            fs::path extDirPath = manageDirectoryPath + '/' + entry.path().extension().string(); 
            extDirPath = manageDirectoryPath + '/' + entry.path().extension().string();
            fs::create_directories(extDirPath);
        }

        destPath = manageDirectoryPath + '/' + entry.path().extension().string() + '/' + entry.path().filename().string();
        fs::rename(srcPath,destPath); // Move the file to the new directory
        
    }
}