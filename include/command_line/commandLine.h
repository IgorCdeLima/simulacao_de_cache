#ifndef COMMANDLINE_H
#define COMMANDLINE_H

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
    };
    
#endif