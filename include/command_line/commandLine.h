#ifndef COMMANDLINE_H
#define COMMANDLINE_H

    #include <string>
    #include <stdio.h>
    #include <iostream>
    #include <stdexcept>

    class commandLine
    {
    private:
        
        // class Singleton
        commandLine() = default;
        commandLine(const commandLine&) = delete;
        commandLine& operator=(const commandLine) = delete; 

        /*variables to arguments*/ 
        int entryPolicy;
        int sizeLine;
        int numberLines;
        int associability;
        int accessTimePerHit;
        std::string substituitionPolicy;
        int timeToReadWrite;

    public:
        // commandLine(/* args */);
        ~commandLine();

        //class singleton
        static commandLine& getInstance()
        {
            static commandLine instance;
            return instance;
        }


        //class functions
        void argumentsForClass(int argc, char *argv[]);
        bool checkNoPowerOfTwo(int number, bool possibility_to_number_one);
        void error_message(std::string msg);
        void checkArguments(int argc, char *argv[]);
        int getEntryPolicy();
        int getSizeLine();
        int getNumberLines();
        int getAssociability();
        int getAccessTimePerHit();
        std::string getSubstituitionPolicy();
        int getTimeToReadWrite();
    };
    
#endif