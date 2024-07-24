 /*!
@file q.h
@author Donghyeon Jo (donghyeon.jo)
@course cs170
@section String Library
@tutorial String Library
@date March 29, 2024
@brief In this 'q.h' file, functions to be defined in the 'q.c' file and used in the driver file are declared.
These are functions that deal with strings.
*//*______________________________________________________________________*/
#include <stdio.h>
#ifdef USE_STRING
#include <string.h>
#define STRLEN strlen
#define STRCPY strcpy
#define STRCAT strcat
#define STRCMP strcmp
#define STRSTR strstr
#else
#include "my_string.h"
#define STRLEN my_strlen
#define STRCPY my_strcpy
#define STRCAT my_strcat
#define STRCMP my_strcmp
#define STRSTR my_strstr
#endif

/*!
@brief This function dynamically allocates a value of type size_t. 
@param size - A size_t type value to receive dynamic allocation.
*//*______________________________________________________________*/
void* debug_malloc(
	size_t size
);

/*!
@brief This 'debug_free' function frees dynamic allocation.
*//*______________________________________________________________*/
void debug_free(
	void* ptr
);

/*!
@brief It receives these 'build_path' strings, combines them, and returns them as char* values.
@param parent - A char* value that is the string to be concatenated.
separator - A char* value that is the string to be concatenated.
folders - A char* array value that is the string to be concatenated.
count - A size_t value, which is the number of elements in the 'folders' array.
@return The char pointer value of the concatenated string.
*//*______________________________________________________________*/
const char* build_path(
	const char* parent,
	const char* separator,
	const char* const folders[],
	size_t count
);

/*!
@brief This 'compare_string' function prints the larger of two strings.
@param lhs - The char* value to be compared.
rhs - The char* value to be compared.
*//*______________________________________________________________*/
void compare_string(
	const char* lhs,
	const char* rhs
);

/*!
@brief This 'describe_string' function prints the length of the string.
@param text - *char value whose length will be counted.
*//*______________________________________________________________*/
void describe_string(const char* text);

/*!
@brief This 'find_string' function finds and prints the location of a specific string among strings.
@param string - Target char* string.
substring - The char* string you are looking for.
*//*______________________________________________________________*/
void find_string(
	const char* string,
	const char* substring
);
