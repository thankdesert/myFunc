#include <stdio.h>


/**
 * ファイルバッファーかnバイト程読み込んでstrに保存する
 * @param char *str バッファーをコピーする文字列ポインタ
 * @param int n 読み込む文字数
 * @param FILE iop ファイルポインタ
 * @note マクロEOFは普通-1で宣言されるので、getc()の戻り値はint形。
 */
char* myfgets(char *str, int n, FILE* iop) {
    int readed_char;   /* getc()の戻り値はint*/
    char* cs;
    cs = str;

    /* n字もしくはファイルの最後尾に達するまで読み込む */
    while (--n > 0 && EOF != (readed_char = getc(iop))) {
        /* 改行文字まで読み込む */
        if ((*cs++ = readed_char) == '\n')
            break;
    }

    *cs = '\0';

    return (readed_char == EOF && cs == str) ? NULL : str;
}
