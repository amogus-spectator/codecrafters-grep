#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>


bool digit_check(const std::string& s) {
    bool check_flag = false;
    for (char c : s) {
        if (std::isdigit(c)) {
            check_flag = true;
            break;
        }
    }
    return check_flag;
}

bool word_check(const std::string& s) {
    bool check_flag = false;
    for (char c : s) {
        if (std::isalnum(c)) {
            check_flag = true;
            break;
        }
    }
    return check_flag;
}

bool match_pattern(const std::string& input_line, const std::string& pattern) {
    if (pattern.length() == 1) {
        return input_line.find(pattern) != std::string::npos;
    } else if (pattern == "\\d") {
        bool digit_flag = digit_check(input_line);
        return digit_flag? true: false;
    } else if (pattern == "\\w") {
        bool word_flag = word_check(input_line);
        return word_flag? true:false;
    }
    else {
        throw std::runtime_error("Unhandled pattern " + pattern);
    }
}

int main(int argc, char* argv[]) {
    // Flush after every std::cout / std::cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // You can use print statements as follows for debugging, they'll be visible when running tests.
    std::cerr << "Logs from your program will appear here" << std::endl;

    if (argc != 3) {
        std::cerr << "Expected two arguments" << std::endl;
        return 1;
    }

    std::string flag = argv[1];
    std::string pattern = argv[2];

    if (flag != "-E") {
        std::cerr << "Expected first argument to be '-E'" << std::endl;
        return 1;
    }

    // Uncomment this block to pass the first stage
    //
    std::string input_line;
    std::getline(std::cin, input_line);
    //
    try {
       if (match_pattern(input_line, pattern)) {
            std::cout << "0";
            return 0;
        } else {
            std::cout << "1";
            return 1;
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
}

