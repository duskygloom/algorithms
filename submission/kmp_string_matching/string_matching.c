#include <stdio.h>
#include <stdlib.h>

#define TEXT_LENGTH 1000
#define SUB_LENGTH 100

/**
 * ALGORITHM
 * length = length(string)
 * prefix_array = [length 0s]
 * for i in [1, length, 0)
 *     if (string[i] == string[0])
 *         prefix_array[i] = 1;
 *         for j in [i+1, length) and string[i+j] == string[j]
 *             prefix_array[i+j] = j + 1
 *             i += j
 *     i += 1
 */
int *get_prefix_array(const char *string, int length)
{
	int *prefix_array = calloc(length, sizeof(int));
	for (int i = 1; i < length;) {
		int j = 1;
		if (string[i] == string[0]) {
			prefix_array[i] = 1;
			for (; j < length && string[i+j] == string[j]; ++j)
				prefix_array[i+j] = j + 1;
		}
		i += j;
	}
	return prefix_array;
}

void print_array(const int *array, int length)
{
	if (length <= 0) {
		printf("[]\n");
		return;
	}
	printf("[%d", array[0]);
	for (int i = 1; i < length; ++i)
		printf(", %d", array[i]);
	printf("]\n");
}

/**
 * ALGORITHM
 * lookup = 0
 * matched = 0
 * prefixes = prefix_array(text)
 * for index in [0, length(sub), 0)
 *     if (matched == sublen)
 *         return index - lookup
 *     else if (text[index] == sub[lookup])
 *         j += 1
 *         matched += 1
 *     else if (matched > 0)
 *         lookup = prefixes[matched - 1]
 *         matched = 0
 */
int kmp_find_substring(const char *text, int textlen, const char *sub, int sublen, const int *prefixes)
{
	int lookup = 0;
	int matched = 0;
	for (int index = 0; index < textlen; ++index) {
		if (matched == sublen)
			return index - lookup;
		else if (text[index] == sub[lookup]) {
			++lookup;
			++matched;
		}
		else if (matched > 0) {
			lookup = prefixes[matched - 1];
			matched = 0;
		}
	}
	return -1;
}

/**
 * @param string
 * Reads characters and stores in string.
 * 
 * @param max_length
 * Maximum length of string.
 * 
 * @return
 * Length of the string read.
 */
int get_string(char *string, int max_length)
{
	int length = 0;
	int ch;
	while (length < max_length && (ch = getchar()) != '\n')
		string[length++] = ch;
	string[length] = '\0';
	return length;
}

int main()
{
	char text[TEXT_LENGTH+1];
	printf("Text (%d): ", TEXT_LENGTH);
	int textlen = get_string(text, TEXT_LENGTH);
	char sub[SUB_LENGTH+1];
	printf("Substring (%d): ", SUB_LENGTH);
	int sublen = get_string(sub, SUB_LENGTH);
	int *prefixes = get_prefix_array(sub, sublen);
	printf("Prefix array: ");
	print_array(prefixes, sublen);
	int index = kmp_find_substring(text, textlen, sub, sublen, prefixes);
	if (index == -1)
		printf("%s not found.\n", sub);
	else {
		printf("%s found at %d.\n", sub, index);
		char subtext[SUB_LENGTH];
		for (int i = 0; i < sublen; ++i)
			subtext[i] = text[index+i];
		subtext[sublen] = '\0';
		printf("In passage: %s\n", subtext);
	}
	return 0;
}

