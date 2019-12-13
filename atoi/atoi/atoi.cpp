#include <iostream>
#include <string.h>

int main(int argc, char** argv) {

	if (argc < 2) {
		printf("Nepateiktas parametras\n");
		return 0;
	}

	char* _str = argv[1];
	int _strLen = static_cast<int>(strlen(_str));

	int res = 0;

	__asm {
		mov ecx, _strLen
		mov esi, _str

		mov edx, 0
		mov eax, 0

		convert :
			// padauginam issaugota reiksme is 10
			imul edx, 10
			// paimam sekanti simboli
			mov al, [esi]
			// konvertuojam paimta simboli i skaiciu
			sub al, 48
			// pridedam nauja skaiciu prie issaugotos reiksmes
			add edx, eax
			// padidinam vienetu
			inc esi
			// kartojam cikla
			loop convert

		mov [res], edx
	}

	std::cout << res;

	return 0;
}