#ifndef COMMANDLINE_H
#define COMMANDLINE_H

    #include <string>
    #include <stdio.h>
    #include <iostream>
    #include <stdexcept>

    class commandLine
    {
    private:
        /* data */
        commandLine() = default;
        commandLine(const commandLine&) = delete;
        commandLine& operator=(const commandLine) = delete; 

    public:
        // commandLine(/* args */);
        ~commandLine();

        static commandLine& getInstance()
        {
            static commandLine instance;
            return instance;
        }
        void argumentsForClass(int argv, char *argc[]);
        bool checkNoPowerOfTwo(int number, bool possibility_to_number_one);
        void error_message(std::string msg);
    };
    
#endif