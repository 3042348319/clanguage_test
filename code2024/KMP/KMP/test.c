#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<string.h>

void KMP(char major, char match, int sz_major, int sz_match);

int build_next(char match,int sz_match);

int main()
{
	int major[50] = { 0 };
	int match[5] = { 0 };
	int major_lengh = strlen(major);
	int match_lengh = strlen(match);
	KMP(major, match, major_lengh, match_lengh);
	return 0;
}

void KMP(char major[], char match[], int sz_major, int sz_match)
{
	int next[sz_match] = build_next(match,sz_match);
	int i = 0;
	int j = 0;
	while (j != sz_match)
	{
		if (major[i] == match[j])
		{
			i++;
			j++;
		}
		else
		{
			if (next[j - 1] == 0)
				i++;
			else
				j = next[j - 1];
		}
	}
}

int build_next(char match[], int sz_match)
{
	int i = 0;
	int j = 0;
	int affix_lengh = 0;
	int next[sz_match];
	while (i != sz_match)
	{
		if (i == 0)
		{
			next[j] = 0;
			i++;
			j++;
		}
		if (i > 0)
		{
			if (match[i] == match[affix_lengh])
			{
				i++;
				affix_lengh++;
				next[j] = affix_lengh;
				j++;
			}
			else
			{
				if (affix_lengh == 0)
				{
					next[j] == 0;
					i++;
					j++;
				}
				else
					affix_lengh = next[affix_lengh - 1];
			}
		}
	}
	return next;
}