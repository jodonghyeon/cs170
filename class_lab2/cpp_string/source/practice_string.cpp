#include "practice_string.hpp"

 #include <cstddef>

namespace CS170
{
    practice_string::practice_string():string{new char[1]{0}},length{0}{}
    practice_string::practice_string(const_pointer cstring){
        length = const_string_length(cstring);
        string = new char[length];
        for(int i=0;i<length;++i)
        {
            string[i]=cstring[i];
        }
    }
    practice_string::practice_string(const practice_string& other) noexcept{}
    practice_string::~practice_string(){
        delete[] string;
    }

    int practice_string::const_string_length(const_pointer cstring)const{
        int temp=0;
        while(*(cstring)!='\0'){
            ++temp;
        }
        return temp;
    }

    int practice_string::string_length(const pointer cstring)const{
        int temp=0;
        while(*(cstring)!='\0'){
            ++temp;
        }
        return temp;
    }

    practice_string& practice_string::adding(const practice_string& other){
        
    }
}
