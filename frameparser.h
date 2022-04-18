#ifndef frameparser
#define frameparser
#define MAX_FIELD_SIZE 20

int checkframe(char* s);

void extract_fields (char* s, char fields[3][MAX_FIELD_SIZE]);

void format_time(char s[6], char* r);
void convert_coord(char s[11],char r[13], int offset);
#endif