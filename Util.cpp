#include "Util.hpp"
#include <iostream>
#include <fstream>



char* readShaderSource(const char* path){
    FILE* fp = fopen(path, "r");
    if(fp == NULL){
        std::cout << "Failed to open file: " << path << std::endl;
        return NULL;
    }
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    rewind(fp); // fseek(fp, 0L, SEEK_SET);
    char* buf = new char[size + 1];
    fread(buf, 1, size, fp);
    buf[size] = '\0';
    fclose(fp);
    return buf;
}