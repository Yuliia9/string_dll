/*
*@file		my_string.h
*@brief		header file that defines prototypes of functions for working with C strings
*/


#ifndef MY_STRING_H_
#define MY_STRING_H_

#include "stdafx.h"
#include <windows.h>

#define DllExp __declspec( dllexport)

/*character that defines the new end of C string*/

#define ERROR -1
typedef unsigned int size_t;
extern "C" extern DllExp const char STREND = '#';


/*
* @brief					Display C string (string with STREND end)
* @param	[in]			const char* str - a pointer to C string with STREND end.
* @return	unsigned int	Returns 0 if pointer is NULL otherwise:
return 1 if string was printed
*/
extern "C" DllExp unsigned int my_strprintf(const char* str);

/*
* @brief			Returns the length of the C string str
* @param	[in]	const char* str - a pointer to C string.
* @return	size_t	Return ERROR if pointer to C string is null pointer, otherwise:
return the length of string
*/
extern "C" DllExp int my_strlen(const char* str);

/*
* @brief				Created a copy of C string source and return pointer to this copy,
including the terminating STREND character
* @param	[in/out]	char* destination - a pointer to the destination C string where the content is to be copied.
[in]		const char* source - a pointer to C string to be copied.
* @return	char*		Return NULL if pointer to source is a null pointer, otherwise:
return a pointer to copied string
*/
extern "C" DllExp char* my_strcpy(char* destination, const char* source);

/*
* @brief				Copies the first num characters of source to destination
STREND-character is implicitly appended at the end of destination if source is longer than num.
* @param	[in/out]	char* destination - a pointer to the destination array where the content is to be copied.
[in]		const char* source - a pointer to C string to be copied.
[in]		size_t num - number or characters needed to be copied
* @return	char*		Return NULL if pointer to destination or source is a null pointer, otherwise:
return a pointer to copied string
*/
extern "C" DllExp char* my_strncpy_s(char* destination, const char* source, size_t num);

/*
* @brief				Appends a copy of the source string to the destination string an created new string for result
* @param	[in/out]	char* destination - a pointer to the destination array where the content is to be append.
[in]		const char* source - a pointer to C string to be copied.
* @return	char*		Return NULL if pointer to destination or source is a null pointer, otherwise:
return a pointer to copied string
*/
extern "C" DllExp char* my_strcat(char* destination, const char* source);

/*
* @brief				Appends the first num characters of source to destination, plus a terminating null-character.
* @param	[in/out]	char* destination - a pointer to the destination array where the content is to be copied.
[in]		const char* source - a pointer to C string to be copied.
* @return	char*		Return NULL if pointer to destination or source is a null pointer, otherwise:
return a pointer to copied string
*/
extern "C" DllExp char* my_strncat(char* destination, const char* source, size_t num);

/*
* @brief			Compares the C string str1 to the C string str2.
* @param	[in]	const char* str1 - a pointer to the first C string to be compared.
[in]	const char* str2 - a pointer to the second C string to be compared.
* @return	int		Return NULL if pointer to str1 or str2 is a null pointer, otherwise:
return a zero if both strings are equal.
return 1 if the first character that does not match has a greater value in str1
return -1 if the first character that does not match has a greater value in str2
*/
extern "C" DllExp int  my_strcmp(const char* str1, const char* str2);

/*
* @brief			Compares up to num characters of the C string str1 to those of the C string str2.
* @param	[in]	const char* str1 - a pointer to the first C string to be compared.
[in]	const char* str2 - a pointer to the second C string to be compared.
[in]	size_t num - a number of characters needed to be compared.
* @return	int		Return NULL if pointer to str1 or str2 is a null pointer, otherwise:
return a zero if both strings are equal.
return 1 if the first character that does not match has a greater value in str1
return -1 if the first character that does not match has a greater value in str2
*/
extern "C" DllExp int my_strncmp(const char* str1, const char* str2, size_t num);

/*
* @brief			Finds the first occurrence of character in the C string str.
* @param	[in]	const char* str - a pointer to the C string.
[in]	int character - Character to be located.
It is passed as its int promotion, but it is internally converted back to char for the comparison.
* @return	char*	Return NULL if pointer to str is a null pointer or if  the character is not found, otherwise:
return a pointer to the first occurrence of character in str.
*/
extern "C" DllExp char*  my_strchr(const char* str, const char character);

/*
* @brief			Finds the last occurrence of character in the C string str.
* @param	[in]	const char* str - a pointer to the C string.
[in]	int character - Character to be located.
* @return	char*	Return NULL if pointer to str is a null pointer or if  the character is not found, otherwise:
return a pointer to the first occurrence of character in str.
*/
extern "C" DllExp const char* my_strrchr(const char* str, const char character);

/*
* @brief			Scans str1 for the first occurrence of any of the characters that are part of str2,
returning the number of characters of str1 read before this first occurrence.
* @param	[in]	const char* str1 - a pointer to the C string to be scanned.
[in]	const char* str2- a pointer to the C string containing the characters to match.
* @return	size_t	Return NULL if pointer to destination or source is a null pointer, otherwise:
return the number of characters of str1 read before this first occurrence
The length of the initial part of str1 not containing any of the characters that are part of str2.
*/
extern "C" DllExp size_t my_strcspn(const char* str1, const char* str2);

/*
* @brief			Returns the length of the initial portion of str1 which consists only
of characters that are part of str2.
* @param	[in]	const char* str1 - a pointer to C string to be scanned.
[in]	const char* str2 - a pointer to C string containing the characters to match.
* @return	size_t	Return NULL if pointer to destination or source is a null pointer, otherwise:
the length of the initial portion of str1 containing only characters that appear in str2.
and if the first character in str1 is not in str2, the function returns zero.
*/
extern "C" DllExp size_t my_strspn(const char* str1, const char* str2);

/*
* @brief			Finds the first occurrence in str1 any of the characters
that are part of str2.
* @param	[in]	const char* str1 - a pointer to C string to be scanned.
[in]	const char* str2 - a pointer to C string containing the characters to match.
* @return	char*	Return NULL if pointer to str1 or str2 is a null pointer or if there are no matches, otherwise:
return a pointer to the first occurrence in str1 of any of the characters that are part of str2
*/
extern "C" DllExp char*  my_strpbrk(char* str1, const char* str2);

/*
* @brief			Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
* @param	[in]	const char* str1 - a pointer to C string to be scanned.
[in]	const char* str2 - a pointer to C string containing the sequence of characters to match.
* @return	char*	Return NULL if pointer to str1 or str2 is a null pointer or if the str2 is not present in str1, otherwise:
return a pointer to the first occurrence in str1 of the entire
sequence of characters specified in str2.
*/
extern "C" DllExp const char*  my_strstr(const char* str1, const char* str2);

/*
* @brief				Split str into tokens, which are sequences of contiguous characters
separated by any of the characters that are part of delimiters.
* @param	[in/out]	char* str - a pointer to C string to truncate.
[in]		const char* delimiters - a pointer to C string containing the delimiter characters.
* @return	char*		Return NULL if pointer to delimiters is a null pointer or  if there are no tokens left to retrieve, otherwise:
return a pointer to the last token found in string
*/
extern "C" DllExp char* my_strtok(char* str, const char* delimiters);

#endif