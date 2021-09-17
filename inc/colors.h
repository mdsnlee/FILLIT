#ifndef COLORS_H
#define COLORS_H


// #define DEFAULT std::cout << "\033[0M";
//example:
// BLUE;
// std::cout << "hello";
// DEFAULT;

#define DEFAULT	"\033[0m"
#define BLACK	"\033[30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define PURPLE  "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"



#define BG_RED     "\033[0;41m"
#define BG_GREEN   "\033[0;42m"
#define BG_YELLOW  "\033[0;43m"
#define BG_BLUE    "\033[0;44m"
#define BG_PURPLE  "\033[0;45m"
#define BG_CYAN    "\033[0;46m"
#define BG_WHITE   "\033[0;47m"

//std::cout << BLACK << "hello" << DEFAULT << std::endl;

#endif