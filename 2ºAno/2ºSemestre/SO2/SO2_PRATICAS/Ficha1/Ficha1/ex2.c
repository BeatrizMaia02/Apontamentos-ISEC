//#include <stdio.h>
//#include <windows.h>
//#include <tchar.h>
//
//#define MAX 256
//
//int main(int argc, char *argv[]) {
//	char result[MAX] = "Ol�! ESte programa ainda n�o representa UNICODE\n";
//	printf("Frase:%s Tamanho:%d\n",result, strlen(result));
//	getchar();
//	return 0;
//}

/*
* char -> 1 byte (caracteres que est�o na tabela ASCII)
* wchar -> 2 bytes (armazena caracteres UNICODE)
* solu��o -> TCHAR ou para char ou para wchar, depende da propriedade do projeto Character Set
*/