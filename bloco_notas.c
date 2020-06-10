#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearFileName(char fileName[50]){
	for(int i=0; i<50; i++){
		fileName[i] = '\0';
	}
}

void getFileName(char fileName[50]){
	printf("\n\nInsira o nome do arquivo: ");
	getchar();
	fgets(fileName, 50, stdin);
	fileName[strlen(fileName)-1] = '\0';
}

int openFile(char fileName[20]){
	FILE *file;
	file = fopen(fileName, "r");
	if(file == NULL)
		printf("\nErro ao abrir o arquivo\n\n");
	else{
		fclose(file);
		printf("\nArquivo existente e e abertura OK!\n\n");
	}
	getchar();
}

void editFile(char fileName[50]){
	char text[256];
	FILE *file;
	printf("\n\nComo deseja modificar o arquivo?\n");
	printf("1 - Sobrescrever Aquivo\n");
	printf("2 - Adicionar texto no final do arquivo\n");
	int option;
	scanf("%i", &option);

	switch(option){
	case 1:
		file = fopen(fileName, "w");
		if(file == NULL)
			printf("Erro ao abrir o Arquivo");
		else{
			printf("Insira o novo texto do arquivo:\n");
			getchar();
			fgets(text, 256, stdin);
			fputs(text, file);
			fclose(file);
		}
		break;
	case 2:
		file = fopen(fileName, "a");
		if(file == NULL)
			printf("Erro ao abrir o arquivo");
		else{
			printf("Insira o texto a ser adicionado no arquivo:\n");
			getchar();
			fgets(text, 256, stdin);
			fputs(text, file);
			fclose(file);
		}
		break;
	defaut:
		 printf("Escolha Invalida!\n\n");
	}
}

void printFile(char fileName[50]){
	char carac;
	FILE *file;
	file = fopen(fileName, "r");
	if(file == NULL)
		printf("Erro ao abrir o arquivo!\n\n");
	else{
		carac = fgetc(file);
		while(!feof(file)){
			printf("%c", carac);
			carac = fgetc(file);
		}
		fclose(file);
	}
	getchar();
}

void copyFile(char fileName[50]){
	char newFileName[50];
	char carac;
	printf("Nome do novo Arquivo: ");
	fgets(newFileName, 50, stdin);
	newFileName[strlen(newFileName)-1] = '\0';
	FILE *original;
	FILE *copy;
	original = fopen(fileName, "r");
	if(original == NULL)
		printf("Erro ao abrir o arquivo original");
	else{
		copy = fopen(newFileName, "w");
		if(copy == NULL)
			printf("Erro ao criar copia!");
		else{
			carac = fgetc(original);
			while(!feof(original)){
				fputc(carac, copy);
				carac = fgetc(original);
			}
		fclose(copy);
		}
	fclose(original);
	}
}


int main (void)
{
	int option;
	char fileName[50];
	int running = 1;

	while(running){
	clearFileName(fileName);

	printf("\n*** Mini Bloco de Notas da FATEC ***\n");
	printf("************************************\n");
	printf("\n1 - Verificar Arquivo\n");
	printf("2 - Editar arquivo\n");
	printf("3 - Exibir arquivo\n");
	printf("4 - Copiar Arquivo\n");
	printf("5 - Sair\n");
	printf("\n************************************\n");

	printf("Escolha sua opcao: ");
	scanf("%i", &option);

	switch(option){
		case 1:
			getFileName(fileName);
			openFile(fileName);
			break;
		case 2:
			getFileName(fileName);
			editFile(fileName);
			break;
		case 3:
			getFileName(fileName);
			printFile(fileName);
			break;
		case 4:
			getFileName(fileName);
			copyFile(fileName);
			break;
		case 5:
			running = 0;
			break;
	}
	}

	return 0;
}
