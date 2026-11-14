/* Q6: Sparse matrix represented with arrays in triplet form (row, col, value).
 * Row 0 of the triplet array stores: rows, cols, number of non-zero terms. */
#include <stdio.h>

#define MAXR 20
#define MAXC 20
#define MAXT (MAXR * MAXC + 1)

int toSparse(int m[MAXR][MAXC], int r, int c, int sp[MAXT][3]) {
    int k = 1;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (m[i][j] != 0) { sp[k][0] = i; sp[k][1] = j; sp[k][2] = m[i][j]; k++; }
    sp[0][0] = r; sp[0][1] = c; sp[0][2] = k - 1;
    return k - 1;
}

void printSparse(int sp[MAXT][3]) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= sp[0][2]; i++)
        printf("%d\t%d\t%d\n", sp[i][0], sp[i][1], sp[i][2]);
}

void transpose(int sp[MAXT][3], int t[MAXT][3]) {
    int n = sp[0][2], k = 1;
    t[0][0] = sp[0][1]; t[0][1] = sp[0][0]; t[0][2] = n;
    for (int col = 0; col < sp[0][1]; col++)       /* emit terms ordered by column */
        for (int i = 1; i <= n; i++)
            if (sp[i][1] == col) { t[k][0] = col; t[k][1] = sp[i][0]; t[k][2] = sp[i][2]; k++; }
}

int main(void) {
    int m[MAXR][MAXC] = {0}, sp[MAXT][3], t[MAXT][3], r, c;
    printf("Enter rows and columns (max %d x %d): ", MAXR, MAXC);
    if (scanf("%d %d", &r, &c) != 2 || r < 1 || c < 1 || r > MAXR || c > MAXC) {
        printf("Invalid size\n"); return 1;
    }
    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (scanf("%d", &m[i][j]) != 1) return 1;

    int nz = toSparse(m, r, c, sp);
    printf("\nSparse representation (%d non-zero of %d):\n", nz, r * c);
    printSparse(sp);
    transpose(sp, t);
    printf("\nTranspose in sparse form:\n");
    printSparse(t);
    return 0;
}
