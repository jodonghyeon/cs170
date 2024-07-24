 /*!
@file my_string.c
@author Donghyeon Jo (donghyeon.jo)
@course cs170
@section String Library
@tutorial String Library
@date March 29, 2024
@brief In this 'my_string.c' file, functions that deal with strings are defined.
*//*______________________________________________________________________*/
#include <stddef.h>

/*!
@brief In 'my_strlen'function, the length of the string is returned using a while loop.
@param str - The string char* value to be targeted.
@return A size_t value that is the length of the string.
*//*______________________________________________________________*/
size_t my_strlen(const char *str) {
    size_t length = 0;
    while (*str != '\0') {
        length++;
        str++;

    }
    return length;
}

/*!
@brief A function that copies a string and returns a pointer.
@param dest - The char* value to be overwritten.
src - The char* value to be copied.
@return A char* value that is a string.
*//*______________________________________________________________*/
char *my_strcpy(char *dest, const char *src) {
    char *dest_origin = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
    return dest_origin;
}

/*!
@brief A function that combines two strings.
@param dest - A char* value that is a string to be combined at the front.
src - A char* value that is a string to be combined at the end.
@return A char* value that is a string.
*//*______________________________________________________________*/
char *my_strcat(char *dest, const char *src) {
    char *dest_origin = dest; 

    while (*dest !='\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    
    *dest = '\0'; 
    return dest_origin;
}

/*!
@brief A function that finds the difference between strings.
@param str1 - String to be compared1.
str2 - String char* value to be subtracted from string 1.
@return Subtract the length of str2 from str1
*//*______________________________________________________________*/
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

/*!
@brief A function that finds a string in a string and returns its address.
@param str1 - Target char* string.
str2 - The char* string you are looking for.
@return Address found.
*//*______________________________________________________________*/
char *my_strstr(const char *str1, const char *str2) {
    while (*str1 !='\0') {
        const char *ch1 = str1;
        const char *ch2 = str2;
        
        while (*ch1 == *ch2 && *ch2 != '\0') {
            ch1++;
            ch2++;
        }
        if (*ch2 == '\0') {
            return (char *)str1; 
        }
        str1++; 
    }
    return NULL; 
}