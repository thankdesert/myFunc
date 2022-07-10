#include <stdio.h>

/**
 * stdinからnバイト程読み込む
 * @param char *s メモリー確報するアドレス
 * @param rsize_t 読み込むバイト
 * @return 読み込んだバイトが格納された文字列のポインタ
 * @note flushはしていない。
 */
char *mygets_s(char *s, rsize_t n) {
	char *str = s;
	int front_c = 0;	/* getchar()の戻り値の形はint形 */

	/* gets()は改行文字を読み込まない。*/
	while (n-- > 0 && '\n' != (front_c = getchar())) {
		printf("%c", front_c);
		*s++ = front_c;
	}
	*str = '\0';	/* 終端文字 */

	return str;
}
