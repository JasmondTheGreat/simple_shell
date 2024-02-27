#include "shell.h"

/**
 * tokenize - tokenizes a string
 *
 * @str: string param
 * @delim: delimeter param
 *
 * Return: number of words separated by the delimeter
 */
size_t tokenize(char *str, char *delim)
{
	size_t numWords = 0;

	if (strtok(str, " ") != NULL)
		numWords++;

	while (strtok(NULL, " ") != NULL)
		numWords++;

	return (numWords);
}

/**
 * word_list - returns an array of words
 *
 * @str: string param
 * @delim: delimeter param
 *
 * Return: a list of words separated by a delimeter
 */
char **word_list(char *str, char *delim)
{
	char **arr, prevChar = '\0';
	size_t arr_itr, str_itr, strLen = strlen(str), numWords = tokenize(str, " ");

	arr_itr = 0;

	arr = malloc((sizeof(char *) * numWords) + 1);

	for (str_itr = 0; str_itr < strLen; str_itr++)
	{
		if (prevChar == '\0' && str[str_itr] != '\0')
		{
			arr[arr_itr] = &str[str_itr];
			arr_itr++;
		}
		prevChar = str[str_itr];
	}

	arr[numWords] = NULL;

	return (arr);
}
