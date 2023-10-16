# sprintf

**형식화된 데이터를 버퍼로 출력**

## 형식
```C
#include <stdio.h>
int sprintf(char *buffer, const char *format-string, argument-list);
```

## 언어레벨
`ANSI`

## Thread-Safe
YES

## Detect Locale
이 함수의 작동은 현재 로케일의 `LC_CTYPE` & `LC_NUMERIC` 범주에 영향을 받을 수 있다. 작동은 `LOCALETYPE(*LOCALEUCS2)` 또는 `LOCALETYPE(*LOCALEUTF)`가ㅏ 컴파일 명령에서 지정되면 현재 로케일의 `LC_UNI_CTYPE` 범주에 영향을 받을 수도 있다. 자세한 정보는 <a href="https://www.ibm.com/docs/ko/ssw_ibm_i_73/rtref/understandccsid.htm#understandccsid">여기</a>의 내용을 참고

## 설명

`sprintf()` 함수는 *배열 버퍼*에 일련의 문자와 값의 형식을 지정하고 저장한다. *argument-list*가 변환되며 *format-string*의 해당 형식 스펙에 따라 만들어진다.

*format-string*은 일반 문자로 구성되고 `printf()` 함수에 대한 *format-string* 인수와 동일한 양식의 함수가 있다.

## 리턴값
`sprintf()` 함수는 끝 널 문자를 계산하지 않고 배열에 작성된 바이트 수를 리턴한다.

## Example

```c
#include <stdio.h>

char buffer[200];
int i, j;
double fp;
char *s = "baltimore";
char c;

int main(void)
{
	c = '1';
	i = 35;
	fp = 1.7320508;
	
	/* Format and print various data */
	j = sprintf(buffer, "%s\n", s);
	j += sprintf(buffer+j, "%c\n", c);
	j += sprintf(buffer+j, "%d\n", i);
	j += sprintf(buffer+j, "%f\n", fp);
	printf("string:\n%s\ncharacter count = %d\n", buffer, j);

	return 0;
}

/************************* Output should be similar to : ****************
 * 
string:
baltimore
1
35
1.732051

character count = 24                                                    */


```

## 출처
https://www.ibm.com/docs/ko/i/7.3?topic=functions-sprintf-print-formatted-data-buffer