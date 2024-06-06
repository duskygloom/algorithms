#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LENGTH 	20

#define CHAR_TO_INT(ch)		(ch - '0')
#define INT_TO_CHAR(num)	(num + '0')
#define IS_DIGIT(ch)		(ch >= '0' && ch <= '9')

#define IS_AP(ch)	(ch == 'A' || ch == 'a' || ch == 'P' || ch == 'p')
#define IS_M(ch)	(ch == 'M' || ch == 'm')


int get_line(char *s, int max_length)
{
	int length = 0;
	char ch;
	while (length-1 < max_length && (ch = getchar()) != '\n')
		s[length++] = ch;
	s[length] = '\0';
	return length;
}

int count_digits(int num)
{
	int count = 0;
	for (; num != 0; ++count, num /= 10);
	return count;
}

int power_10(int num)
{
	int result = 1;
	for (int i = 0; i < num; result *= 10, ++i);
	return result;
}

int get_nth_digit(int num, int n)
{
	return (num / power_10(n)) % 10;
}

void add_seperator(char *time_str)
{
	int index = 0;
	for (; index < MAX_STR_LENGTH && time_str[index]; ++index);
	if (index < MAX_STR_LENGTH) time_str[index++] = ':';
	if (index >= MAX_STR_LENGTH) index = MAX_STR_LENGTH-1;
	time_str[index] = '\0';
}

void add_value(char *time_str, int num)
{
	int index = 0;
	for (; index < MAX_STR_LENGTH && time_str[index]; ++index);
	int ndigits = count_digits(num);
	if (ndigits < 2)
		for (int i = 0; index < MAX_STR_LENGTH && i < 2-ndigits; ++i)
			time_str[index++] = '0';
	for (int i = ndigits-1; index < MAX_STR_LENGTH && i >= 0; --i)
		time_str[index++] = INT_TO_CHAR(get_nth_digit(num, i));
	if (index >= MAX_STR_LENGTH) index = MAX_STR_LENGTH-1;
	time_str[index] = '\0';
}

/**
 * @param[in]  time_12  12 hour format time in string format
 *
 * @return     an array of hour, minutes and seconds
 * 			   in 24 hour format.
 */
void time_12_to_24(const char *time_12, char *time_24)
{
	int index = 0;
	int time[3] = {0};
	for (int i = 0; i < 3; ++i) {
		while (time_12[index] != '\0' && IS_DIGIT(time_12[index]))
			time[i] = 10*time[i] + CHAR_TO_INT(time_12[index++]);
		// skip all non-digit characters except AM and PM
		for (; time_12[index] != '\0' && !IS_DIGIT(time_12[index]) && !(IS_AP(time_12[index]) && IS_M(time_12[index+1])); ++index);
	}
	// check if PM
	for (; time_12[index] != '\0' && !(IS_AP(time_12[index]) && IS_M(time_12[index+1])); ++index);
	// if (time[0] >= 1 && time[0] <= 12)
		time[0] += 12*(time_12[index] == 'P' || time_12[index] == 'p');
	// correct time
	time[1] += time[2] / 60;
	time[2] %= 60;
	time[0] += time[1] / 60;
	time[1] %= 60;
	time[0] %= 24;
	// time_24 string
	add_value(time_24, time[0]);
	add_seperator(time_24);
	add_value(time_24, time[1]);
	add_seperator(time_24);
	add_value(time_24, time[2]);
}

int main(int argc, char **argv)
{
	char time_12[MAX_STR_LENGTH];
	printf("12 hour time: ");
	get_line(time_12, MAX_STR_LENGTH);
	char time_24[MAX_STR_LENGTH];
	time_12_to_24(time_12, time_24);
	printf("\n12 hour time: %s\n", time_12);
	printf("24 hour time: %s\n", time_24);
	return 0;
}

