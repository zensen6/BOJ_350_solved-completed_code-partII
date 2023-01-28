#include <stdio.h>
#include <string.h>
#define LM 100

char str[LM + 1];          /// 입력 문자열
char word[LM + 1][LM + 1]; /// 분리된 단어를 저장할 배열
int wcnt;                  /// 분리된 단어의 갯수

int main()
{
    int i, len;
    char *token;
    fgets(str, LM, stdin); /// 최대 LM - 1개의 문자가 입력된다.
    len = strlen(str);     /// 1이상 LM개 이하의 문자가 입력되었다고 가정

    strtok(str, "\r\n"); /// '\r'또는'\n' 제거

    token = strtok(str, " "); /// str문자열 시작부터 공백이 아닌 처음 위치(*sp)를 찾고
                              /// 그 이후등장하는 첫 공백 위치(*ep)를 찾아
                              /// 그 값을 '\0'로 하고 sp를 반환한다.
    while (token)
    {
        strcpy(word[wcnt++], token);
        token = strtok(NULL, " ");
        /// strtok함수의 첫 인자를 NULL로 주면 이전에 찾은
        /// ep위치 다음부터 공백이 아닌 처음 위치를 찾는다.
        /// 공백이 아닌 위치를 찾지 못하면 NULL을 리턴 한다.
    }
    for (i = 0; i < wcnt; ++i)
        puts(word[i]);

    return 0;
}
