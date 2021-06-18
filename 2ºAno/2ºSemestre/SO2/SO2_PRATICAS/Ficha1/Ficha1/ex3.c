#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

#define MAX 256

/*LPTSTR -> TCHAR *
* LPCTSTR -> const TCHAR *
*/

/*
int _tmain(int argc, LPTSTR argv[]) {
	TCHAR str[MAX], result[MAX] = TEXT("Ol�! Este programa � para aceitar UNICODE. Insira \'fim\' para sair\n");
	unsigned int i;
	//UNICODE: Por defeito, a consola Windows n�o processa caracteres wide.
	//A maneira mais f�cil para ter esta funcionalidade � chamar _setmode:
#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif
	do {
		_tprintf(result);
		fflush(stdin);
		_fgetts(str, MAX, stdin);
		//Retirar \n
		str[_tcslen(str) - 1] = '\0';
		//Mai�sculas
		for (i = 0; i < _tcslen(str); i++)
			str[i] = _totupper(str[i]);
		_stprintf_s(result, MAX, TEXT("Frase:%s, Tamanho:%d\n"), str, _tcslen(str));
	} while (_tcsicmp(TEXT("FIM"), str));

	/*
	* Cria��o de um processo ->  correr um programa j� compilado
	*/
/*
	//Nome do pr�prio programa -> argv[0] ou GetModuleFileName
	TCHAR text[256] = TEXT("notepad.exe");

	//Estruturas que retornam informa��o do processo criado
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si)); //igual ao memset mas com tudo a 0
	si.cb = sizeof(STARTUPINFO);
	ZeroMemory(&pi, sizeof(pi)); // resultado da fun�ao : pid do processo, tid da thread principal, handle (ponteiro para estrutura) do processo, handle para thread
								// pid �nico no sistema para cada processo, handle podem ser v�rios, cada uma com dada permiss�o


	if (CreateProcess(NULL,   // No module name (use command line)
		text,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		) {
		_tprintf(TEXT("Processo foi lan�ado, PID: %d , %d"), pi.dwProcessId, pi.dwThreadId);
	}
	else
		_tprintf(TEXT("Houve um erro a lan�ar o processo !"));

	// Esperar pelo processo terminar
	//WaitForSingleObject(pi.hProcess, INFINITE);
	return 0;
}
*/