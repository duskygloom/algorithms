#include <stdio.h>

#define TEXT_LENGTH 200
#define SUB_LENGTH 20

/**
 * ALGORITHM
 * for index in [0, length(sub)):
 *     if text[index] == sub[0]:
 *         if text[index+1:length(sub)] == sub[1:length(sub)]:
 *             return index
 */
int find_substring(const char *text, int textlen, const char *sub, int sublen)
{
	for (int i = 0; i < textlen; ++i) {
		if (text[i] == sub[0]) {
			int j = 1;
			for (; j < sublen; ++j)
				if (text[i+j] != sub[j])
					break;
			if (j == sublen)
				return i;
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
	int index = find_substring(text, textlen, sub, sublen);
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
