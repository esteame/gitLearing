#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[]) {
	FILE *fp;
	int count = 0;
	if ((fp=fopen(argv[2], "r")) == NULL) {
		puts("error!\n");
		return 0;
	}
	if (argv[1][1] == 'w') {
		char s[1024];
		while (fscanf(fp, "%s", s) != EOF) {
			count ++;
			for (int i = 1; i < strlen(s) - 1; i ++)
				if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',')
					count++;
		}
		printf("µ¥´ÊÊý: %d\n", count);
	} else if (argv[1][1] == 'c') {
		char c;
		while ((c = fgetc(fp)) != EOF) count++;
		printf("×Ö·ûÊý: %d", count);
	}
	fclose(fp);
	return 0;
}
