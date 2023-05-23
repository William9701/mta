#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "shell.h"


/**
 * _strncpy - _strncpy
 * @dest: destinatiom
 * @src: src
 * @n: n
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{

	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _strlen - _strlen
 * @s: letter to be checked with
 * Return: nothing
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _strchr - strchr
 * @s: chr to be chcked with
 * @c: same
 * Return: 0
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}

/**
 * _strstr - Locate a substring in a string
 * @haystack: The string to search in
 * @needle: The substring to search for
 * Return: Pointer
 */
char *_strstr(const char *haystack, const char *needle)
{
	const char *h;
	const char *n;

	if (*needle == '\0')
	{
		return ((char *) haystack);
	}
	while (*haystack)
	{
		h = haystack;
		n = needle;
		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}



/**
 * _strncmp - Compare two strings up to a given number of characters
 * @s1: The first string to compare
 * @s2: The second string to compare
 * @n: The maximum number of characters to compare
 * Return: int
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char c1, c2;

	while (n > 0)
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 != c2)
		{
			return (c1 - c2);
		}
		if (c1 == '\0')
		{
			return (0);
			n--;
		}
	}
	return (0);

}
