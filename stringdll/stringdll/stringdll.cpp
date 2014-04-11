/*
*@file		functions.cpp
*@brief		implements functions for working with C string defined in file my_string.h
*/
#include "stdafx.h"
#include "my_string.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>



unsigned int my_strprintf(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	while (*str != STREND)
	{
		printf("%c", *(str));
		++str;
	}
	return 1;
}

/********************************************************************************/
int my_strlen(const char* str)
{
	int len = 0;
	if (str == NULL)
	{
		return ERROR;
	}
	while (*str++ != STREND)
	{
		++len;
	}
	return len;
}

/********************************************************************************/
char* my_strcpy(char* destination, const char* source)
{
	int len;
	if (source == NULL)
	{
		return NULL;
	}
	len = my_strlen(source);
	destination = (char*)malloc(sizeof(char)* len);
	if (destination == NULL)
	{
		return NULL;
	}
	memcpy(destination, source, len + 1);
	return destination;
}

/********************************************************************************/
char* my_strncpy_s(char* destination, const char* source, size_t num)
{
	int len;
	if (source == NULL)
	{
		return NULL;
	}
	len = my_strlen(source);
	num = num < len ? num : len;
	destination = (char*)malloc(sizeof(char)* num);
	if (destination == NULL)
	{
		return NULL;
	}
	memcpy(destination, source, num);
	destination[num] = STREND;
	return destination;
}

/********************************************************************************/
char* my_strcat(char* destination, const char* source)
{
	int len_d, len_s;
	char* temp;
	if (destination == NULL || source == NULL)
	{
		return NULL;
	}
	len_d = my_strlen(destination);
	len_s = my_strlen(source);
	temp = (char*)malloc(sizeof(char)* (len_s + len_d + 1));
	if (temp == NULL)
	{
		return NULL;
	}
	memcpy(temp, destination, len_d);
	memcpy(temp + len_d, source, len_s + 1);
	destination = temp;
	return destination;
}

/*******************************************************************************/
char* my_strncat(char* destination, const char* source, size_t num)
{
	int len_d, len_s;
	char* temp;
	if (destination == NULL || source == NULL)
	{
		return NULL;
	}
	len_d = my_strlen(destination);
	len_s = my_strlen(source);
	num = num < len_s ? num : len_s;
	temp = (char*)malloc(sizeof(char)* (len_d + num + 1));
	if (temp == NULL)
	{
		return NULL;
	}
	memcpy(temp, destination, len_d);
	memcpy(temp + len_d, source, num);
	*(temp + len_d + len_s) = STREND;
	destination = temp;
	return destination;
}

/******************************************************************************/
int my_strcmp(const char* str1, const char* str2)
{
	int len1, len2;
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	len1 = my_strlen(str1);
	len2 = my_strlen(str2);
	if (len1 > len2)
	{
		return 1;
	}
	else if (len1 < len2)
	{
		return -1;
	}
	else
	{
		return memcmp(str1, str2, len1);
	}
}

/******************************************************************************/
int my_strncmp(const char* str1, const char* str2, size_t num)
{
	int len1, len2;
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	len1 = my_strlen(str1);
	len2 = my_strlen(str2);
	if (len1 < num || len2 < num)
	{
		if (len1 > len2)
		{
			return 1;
		}
		else if (len2 > len1)
		{
			return -1;
		}
	}

	return memcmp(str1, str2, num);
}

/******************************************************************************/  
char* my_strchr(const char* str, const char character)
{
	if (str == NULL)
	{
		return NULL;
	}
	return (char*)memchr(str, character, my_strlen(str));
}

/*****************************************************************************/
const char* my_strrchr(const char* str, const char character)
{
	int len;
	if (str == NULL)
	{
		return NULL;
	}
	len = my_strlen(str);
	str += len;
	while (len)
	{
		if (*str == character)
		{
			return str;
		}
		else
		{
			--str;
			--len;
		}
	}
	return NULL;
}

/*****************************************************************************/
size_t my_strcspn(const char * str1, const char * str2)
{
	int len2, i;
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	len2 = my_strlen(str2);
	for (i = 0; *str1 != STREND; ++i, ++str1)
	{
		if (memchr(str2, *str1, len2) != NULL)
		{
			return i;
		}
	}
	return i;
}

/*****************************************************************************/
size_t my_strspn(const char* str1, const char* str2)
{
	int len2, i;
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	len2 = my_strlen(str2);
	for (i = 0; *str1 != STREND; ++i, ++str1)
	{
		if (memchr(str2, *str1, len2) == NULL)
		{
			break;
		}
	}
	return i;
}

/****************************************************************************/
char* my_strpbrk(char* str1, const char* str2)
{
	int i, len2;
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	len2 = my_strlen(str2);
	for (i = 0; *str1 != STREND; ++i, ++str1)
	{
		if ((char*)memchr(str2, *str1, len2) != NULL)
		{
			return str1;
		}
	}
	return NULL;
}

/****************************************************************************/
const char* my_strstr(const char* str1, const char* str2)
{
	int len2;
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	len2 = my_strlen(str2);
	for (; *str1 != STREND; ++str1)
	{
		if (*str1 == *str2)
		{
			if (memcmp(str1, str2, len2) == 0)
			{
				return str1;
			}
		}
	}
	return NULL;
}

/****************************************************************************/
char* my_strtok(char* str, const char* delimiters)
{
	static char* last = NULL;
	char* tokenbeg;
	char* tokenend;
	if (delimiters == NULL)
	{
		return NULL;
	}
	if (str != NULL)
	{
		last = str;
	}
	if ((*last == STREND) && (str == NULL))
	{
		return NULL;
	}
	tokenbeg = last;
	tokenend = my_strpbrk(tokenbeg, delimiters);
	if (tokenend == NULL)
	{
		last += my_strlen(last);
		return tokenbeg;
	}
	while ((tokenend - tokenbeg) < 1)
	{
		tokenbeg = tokenend + 1;
		tokenend = my_strpbrk(tokenend + 1, delimiters);

	}
	last = tokenend + 1;
	*tokenend = STREND;
	return tokenbeg;
}