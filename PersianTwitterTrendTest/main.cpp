#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#define PATH_TO_DICT "persian-words.txt"
int main() {
    std::ifstream file;
    file.open(PATH_TO_DICT, std::ios::in);
    std::string line;
    std::vector<std::string> words;
    std::vector<std::string> man_words;
    std::vector<std::string> ma_words;
    if(!file.is_open()){
        std::cout << "failed to open file" << std::endl;
        return 1;

    }
    std::string man_string = "من";
    std::string ma_string = "ما";
    while(std::getline(file, line)){
        std::istringstream buffer(line);
        std::string word;
        std::getline(buffer, word, ':');
        words.push_back(word);
        std::string first_part = word.substr(0, 4);
        if(first_part == man_string){
            man_words.push_back(word);
        }else if(first_part == ma_string){
            ma_words.push_back(word);
        }
    } // got all strings I need till here
    file.close();
    std::string result_sentence;
    //let's check for meaningfull words : 
    for(int i = 0; i < man_words.size(); i++){
        std::string word_without_man = man_words.at(i).substr(4);
        for(int j = 0; j < words.size(); j++){
            if(word_without_man == words.at(j)){
                result_sentence = "به من نگو " + word_without_man + "، " 
                + man_words.at(i) + "تو نیستم";
                std::cout << result_sentence << std::endl;
            }
        }
    }
    //checking in ma words
        for(int i = 0; i < ma_words.size(); i++){
        std::string word_without_ma = ma_words.at(i).substr(4);
        for(int j = 0; j < words.size(); j++){
            if(word_without_ma == words.at(j)){
                result_sentence = "به ما نگو " + word_without_ma + "، " 
                + ma_words.at(i) + "تو نیستیم";
                std::cout << result_sentence << std::endl;
            }
        }
    }
    
}