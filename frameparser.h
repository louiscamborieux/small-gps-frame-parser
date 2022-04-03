#ifndef frameparser
#define frameparser
#define MAX_FIELD_SIZE 20

int checkframe(char* s);

void extract_fields (char* s, char fields[3][MAX_FIELD_SIZE]);


#endif