/**
 * @file log.h
 * @author divilol
 * @brief 
 * @version 0.01
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<string.h>
#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<ctime>




class Log
{
public:
    


    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    void start();
    void send_log(const char *text);
    void send_log_in_color(const char *text,int color,const char* info);
};

void Log::start()
{

}

void Log::send_log(const char *text)
{
    time_t t = time(0);
    tm* tmp = localtime(&t);
    std::cout<<"["<<tmp->tm_hour<<":"<<tmp->tm_min<<":"<<tmp->tm_sec<<"]"<<" "<<text<<"\n";
}

void Log::send_log_in_color(const char *text,int color,const char* info)
{
    time_t t = time(0);
    tm* tmp = localtime(&t);
    SetConsoleTextAttribute(h,color);
    std::cout<<"["<<info<<"]"<<" "<<"["<<tmp->tm_hour<<":"<<tmp->tm_min<<":"<<tmp->tm_sec<<"]"<<" "<<text<<"\n";
    
 
}