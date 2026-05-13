/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
*   Modul               : 5 - Foundation of Algorithm
*   Hari dan Tanggal    : Rabu, 13 Mei 2026
*   Nama (NIM)          : Christian Jonathan Hutajulu (13224108)
*   Nama File           : Soal2.c
*   Deskripsi           : Sebuah peta energi direpresentasikan sebagai grid biner, di mana sel bernilai 1 menunjukkan wilayah
                          aktif dan 0 menunjukkan wilayah kosong. Wilayah aktif yang saling terhubung secara vertikal atau
                          horizontal dianggap sebagai satu pulau energi. Tim analisis medan ingin mengetahui berapa banyak
                          pulau yang ada serta seberapa besar pulau terbesar yang muncul pada peta tersebut.
                          Hitung jumlah pulau dan ukuran pulau terbesar pada grid biner.
                          Kondisi/Aturan
                          1. Grid berukuran R x C
                          2. Setiap sel berisi 0 atau 1
                          3. Dua sel 1 dianggap terhubung jika berdampingan atas, bawah, kiri, atau kanan
                          4. Jumlah pulau = banyak komponen terhubung dari sel 1
                          5. Ukuran pulau = banyak sel 1 di komponen itu
                          6. Jika tidak ada pulau, ukuran terbesar = 0
**/

#include <stdio.h>
#include <string.h>
#define MAX 100

int R, C;
char grid[MAX][MAX];
int visited[MAX][MAX];

int dfs(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] == '0' || visited[r][c]) {
        return 0;
    }
    visited[r][c] = 1;
    int size = 1;
    size += dfs(r + 1, c);
    size += dfs(r - 1, c);
    size += dfs(r, c + 1);
    size += dfs(r, c - 1);
    return size;
}

int main() {
    if (scanf("%d %d", &R, &C) != 2) return 0;
    for (int i = 0; i < R; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < C; j++) {
            visited[i][j] = 0;
        }
    }

    int x = 0;
    int y = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                x++;
                int curr_size = dfs(i, j);
                if (curr_size > y) {
                    y = curr_size;
                }
            }
        }
    }

    printf("ISLANDS %d\n", x);
    printf("LARGEST %d\n", y);

    return 0;
}
