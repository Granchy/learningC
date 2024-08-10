#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define PARSE_SUCCESSFUL 1
#define PARSE_FAILURE 0

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);



void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);

// void reverse(void *v[], int len);

int order = 1;
int (*comp)(void *, void*) = estrcmp;



int main(int argc, char const *argv[])
{
    int nlines;
    int numeric = 0, rev = 0;


    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if(argc > 1 && (strcmp(argv[1], "-r") || strcmp(argv[2], "-r")))
        rev = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void **) lineptr, 0, nlines-1,
            (int (*)(void*, void*))(numeric ? numcmp: strcmp));
    if(rev) reverse((void **) lineptr, nlines);
        writelines(lineptr,nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }



}

void qsort(void *v[], int left, int right, int (*comp)(void *, void*)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
        swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1,right,comp);
}

int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) return -1 * order;
    else if (v1 > v2) return 1 * order;
    else return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int parse_arg_list(int argc, char *argv[]) {
    if(argc == 1) return PARSE_FAILURE;

    for(int i = 0; i < argc ; i++) {

        if(argv[i][0] == '-') {
            size_t len = strlen(argv[i]);
            for(int j = 1; j < len; j++) {
                switch(argv[i][j]) {
                    case 'n':
                        comp = numcmp;
                        break;
                    case 'r':
                        order = -1;
                        break;
                    default:
                        return PARSE_FAILURE;
                        break;
                }
            }
        }
        else return PARSE_FAILURE;
    }
    return PARSE_SUCCESSFUL;
}

int estrcmp(char *s1, char *s2) {
    return order * strcmp(s1, s2);
}

// void reverse(void *v[], int len) {
//     for(int i = 0; i<len/2; i++) {
//         int j = len-1-i;
//         swap(v, i, j);
//     }
// }