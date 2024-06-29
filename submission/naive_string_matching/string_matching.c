#include <stdio.h>

#define MATCH_LENGTH 20
#define STRING_LENGTH 200

const char passage[] = "A string-matching algorithm wants to find the starting index m \
in string S[] that matches the search word W[]. The most straightforward algorithm, known \
as the 'brute-force' or 'naive' algorithm, is to look for a word match at each index m, i.e. \
the position in the string being searched that corresponds to the character S[m]. At each position \
m the algorithm first checks for equality of the first character in the word being searched, i.e. S[m] \
=? W[0]. If a match is found, the algorithm tests the other characters in the word being searched by checking \
successive values of the word position index, i. The algorithm retrieves the character W[i] in the word being \
searched and checks for equality of the expression S[m+i] =? W[i]. If all successive characters match in W at \
position m, then a match is found at that position in the search string. If the index m reaches the end of the \
string then there is no match, in which case the search is said to 'fail'. Usually, the trial check will quickly \
reject the trial match. If the strings are uniformly distributed random letters, then the chance that characters \
match is 1 in 26. In most cases, the trial check will reject the match at the initial letter. The chance that the \
first two letters will match is 1 in 26 (1 in 26^2 chances of a match over 26 possible letters). So if the characters \
are random, then the expected complexity of searching string S[] of length n is on the order of n comparisons or O(n). \
The expected performance is very good. If S[] is 1 million characters and W[] is 1000 characters, then the string search \
should complete after about 1.04 million character comparisons. That expected performance is not guaranteed. If the \
strings are not random, then checking a trial m may take many character comparisons. The worst case is if the two strings \
match in all but the last letter. Imagine that the string S[] consists of 1 million characters that are all A, and that \
the word W[] is 999 A characters terminating in a final B character. The simple string-matching algorithm will now examine \
1000 characters at each trial position before rejecting the match and advancing the trial position. The simple string \
search example would now take about 1000 character comparisons times 1 million positions for 1 billion character comparisons. \
If the length of W[] is k, then the worst-case performance is O(k⋅n). The KMP algorithm has a better worst-case performance \
than the straightforward algorithm. KMP spends a little time precomputing a table (on the order of the size of W[], O(k)), \
and then it uses that table to do an efficient search of the string in O(n). The difference is that KMP makes use of previous \
match information that the straightforward algorithm does not. In the example above, when KMP sees a trial match fail on the \
1000th character (i = 999) because S[m+999] != W[999], it will increment m by 1, but it will know that the first 998 characters \
at the new position already match. KMP matched 999 A characters before discovering a mismatch at the 1000th character \
(position 999). Advancing the trial match position m by one throws away the first A, so KMP knows there are 998 A characters \
that match W[] and does not retest them; that is, KMP sets i to 998. KMP maintains its knowledge in the precomputed table and \
two state variables. When KMP discovers a mismatch, the table determines how much KMP will increase (variable m) and where it \
will resume testing (variable i).";

/**
 * ALGORITHM
 * for index in [0, length(match)):
 *     if string[index] == match[0]:
 *         if string[index+1:length(match)] == match[1:length(match)]:
 *             return index
 */
int match_string(const char *string, int string_length, const char *match, int match_length)
{
	for (int i = 0; i < string_length; ++i) {
		if (string[i] == match[0]) {
			int j = 1;
			for (; j < match_length; ++j)
				if (string[i+j] != match[j])
					break;
			if (j == match_length)
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
	return length;
}

int main()
{
	char string[STRING_LENGTH+1];
	printf("String (200): ");
	int string_length = get_string(string, STRING_LENGTH);
	char match[MATCH_LENGTH+1];
	printf("Match (20): ");
	int match_length = get_string(match, MATCH_LENGTH);
	int index = match_string(string, string_length, match, match_length);
	if (index == -1)
		printf("%s not found.\n", match);
	else {
		printf("%s found at %d.\n", match, index);
		char string_match[MATCH_LENGTH];
		for (int i = 0; i < match_length; ++i)
			string_match[i] = string[index+i];
		string_match[match_length] = '\0';
		printf("In passage: %s\n", string_match);
	}
	return 0;
}
