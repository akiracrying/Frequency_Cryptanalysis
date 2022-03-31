х#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

FILE* input;
char ru_letters[40] = "оеаинтсрвлкмдпуяыьгзбчйхжшюцщэфёъ";
char ru_letters_b[40] = "ОЕАИНТСРВЛКМДПУЯЫЬГЗБЧЙХЖШЮЦЩЭФЁЪ";
char text[2000] = "";
char text1[2000] = ""; //неизменяемый начальный массив
int sp_flag = 1;
int size_big;
char history[100][20]; int his_place = 0;
struct Words {
	int length;
	char letters[30];
};
struct Words words_text[1500];
struct Words words_uncrypt[1500];
int main();
int scann(int c) {
	scanf("%d", &c);
	return c;
}
void print(char* n) {
	for (int i = 0; i < size_big ; i++){
		printf("%c", n[i]);
	}
	printf("\n\n");
	main();
}
void error() {
	printf("Пожалуйста, выберите числа от 0 до 8\n");
	main();
}
void freq(char *mat) {
	int check = 0;
	int i_check = -1;
	char cur_alph[40] = "";
	float cur_freq[43] = { 0 };
	int useless_trash = 0;
	for (int i = 0; mat[i] != '\0';++i) {
		if (mat[i] == ' ' || mat[i] == '\n' || mat[i] == ';' || mat[i] == '.' || mat[i] == ':' || mat[i] == '!' || mat[i] == '?' || mat[i] == ',' || mat[i] == '-') {
			useless_trash++;
		}
	}
	int len = strlen(mat);
	int len_for_comp = strlen(mat) - useless_trash;
	char used[10000] = "";
	for (int i = 0; i < size_big;i++) {
		i_check++;
		if (mat[i] == ' ' || mat[i] == '\n' || mat[i] == ';' || mat[i] == '.' || mat[i] == ':' || mat[i] == '!' || mat[i] == '?' || mat[i] == ',' || mat[i] == '-') {
			i_check--;
			continue;
		}
		int flag = 0;
		for (int j = 0; j < 10000; j++) {
			if (mat[i] == used[j])flag = 1;
		}
		if (flag == 1) {
			i_check--;
			continue;
		}
		char tmp = mat[i];
		int count = 0;
		for (int j = 0; j < size_big; j++) {
			if (mat[j] == mat[i]) {
				count++;
			}
		}
		int flag_g = 0;
		float float_fr = 1. * count / len_for_comp;
		for (int j = 0; j < 40; j++) {
			if (cur_alph[j] == tmp) {
				flag_g = 1;
				i_check--;
			}
		}
		if (flag_g != 1 && i < size_big) {
			cur_alph[i_check] = tmp;
			cur_freq[i_check] = float_fr;
		}
		flag_g = 0;
		flag = 0;
		count = 0;
		used[i] = tmp;
	}
	int move = 0;//сдвиг в ru_letters
	for (int i = 0; i < 33;i++) {
		float maximum = -1.000000;//значение максимума
		int tmp_max = 0;//индекс текущего максимума
		for (int j = 0; j < 33;j++) {
			if (cur_freq[j] > maximum) {
				maximum = cur_freq[j];
				tmp_max = j;
			}
		}
		printf("%c = %f -> %c\n", cur_alph[tmp_max], cur_freq[tmp_max], ru_letters[move]);
		move++;
		float checkccc = cur_freq[tmp_max];
		int haha = 0;
		cur_freq[tmp_max] = -2.000000;
		int is_it = 0;
	}
	main();
}
void decrypt(char* mat) {
	history[his_place][0] = 'D';history[his_place][1] = 'E';history[his_place][2] = 'C';history[his_place][3] = '\n';
	his_place++;
	int i_check = -1;
	char cur_alph[40] = "";
	float cur_freq[43] = {0};
	int useless_trash = 0;
	for (int i = 0; mat[i] != '\0';++i) {
		if (mat[i] == ' ' || mat[i] == '\n' || mat[i] == ';' || mat[i] == '.' || mat[i] == ':' || mat[i] == '!' || mat[i] == '?' || mat[i] == ',' || mat[i] == '-') {
			useless_trash++;
		}
	}
	int len = strlen(mat);
	int len_for_comp = strlen(mat) - useless_trash;
	char used[10000]="";
	for (int i = 0; i < size_big;i++) {
		i_check++;

		if (mat[i] == ' ' || mat[i] == '\n' || mat[i] == ';' || mat[i] == '.' || mat[i] == ':' || mat[i] == '!' || mat[i] == '?' || mat[i] == ',' || mat[i] == '-') {
			i_check--;
			continue;
		}
		int flag = 0;
		for (int j = 0; j < 10000; j++) {
			if (mat[i] == used[j])flag = 1;
		}
		if (flag == 1) {
			i_check--;
			continue;
		}
		char tmp = mat[i];
		int count = 0;
		for (int j = 0; j < size_big; j++) {
			if (mat[j] == mat[i]) {
				count++;
			}
		}
		int flag_g = 0;
		float float_fr = 1. * count / len_for_comp;
		for (int j = 0; j < 40; j++) {
			if (cur_alph[j] == tmp) {
				flag_g = 1;
				i_check--;
			}
		}
		if (flag_g != 1 && i < size_big) {
			cur_alph[i_check] = tmp;
			cur_freq[i_check] = float_fr;
		}
		flag_g = 0;
		flag = 0;
		count = 0;
		used[i] = tmp;
	}
	int move = 0;//сдвиг в ru_letters
	for (int i = 0; i < 33;i++) {
		float maximum = -1.000000;//значение максимума
		int tmp_max = 0;//индекс текущего максимума
		for (int j = 0; j < 33;j++) {
			if (cur_freq[j] > maximum) {
				maximum = cur_freq[j];
				tmp_max = j;
			}
		}
		float checkccc = cur_freq[tmp_max];
		int haha = 0;
		cur_freq[tmp_max] = -2.000000;
		int is_it = 0;
		for (int j = 0; j < size_big; j++) {
			if (mat[j] == cur_alph[tmp_max]) {
				mat[j] = ru_letters[move];
				is_it = 1;
				haha = j;
			}
		}
		if (is_it == 1) {
			move++;
		}
	}
	main();
}
void words_len() {
	int v = -1;
	int k = 0;
	for (int i = 0; i < size_big;i++) {
		if (text[i] == ' ' || text[i] == '\n' || text[i] == ';' || text[i] == '.' || text[i] == ':' || text[i] == '!' || text[i] == '?' || text[i] == ',' || text[i] == '-') {
			k = 0;
			v++;
			continue;
		}
		else {
			if (v == -1)v = 0;
			words_text[v].letters[k] = text[i];
			k++;
			words_text[v].length++;
		}

	}
	int max = 0;
	int ind = 0;
	int f = 0;
	for (int i = 0; i < v;i++) {
		for (int j = 0; j < v;j++) {
			if (words_text[j].length > max) {
				max = words_text[j].length;
				ind = j;
			}
		}
		words_text[ind].length = -1;
		for (int z = 0; z < max; z++){
			printf("%c", words_text[ind].letters[z]);
			f = 1;
		}
		if(f == 1)printf("\n");
		f = 0;
		max = 0;
		ind = 0;
	}
	main();
}
void words_non_crypt() {
	int v = -1;
	int k = 0;
	for (int i = 0; i < size_big;i++) {
		if (text[i] == ' ' || text[i] == '\n' || text[i] == ';' || text[i] == '.' || text[i] == ':' || text[i] == '!' || text[i] == '?' || text[i] == ',' || text[i] == '-') {
			k = 0;
			v++;
			continue;
		}
		else {
			if (v == -1)v = 0;
			words_uncrypt[v].letters[k] = text[i];
			k++;
			if((words_uncrypt[v].letters[k-1] >= 'А')&&(words_uncrypt[v].letters[k-1] <= 'Я')) {
				words_uncrypt[v].length++;
			}
		}
	}
	int max = 0;
	int ind = 0;
	int f = 0;
	for (int i = 0; i < v;i++) {
		for (int j = 0; j < v;j++) {
			if (words_uncrypt[j].length > max) {
				max = words_uncrypt[j].length;
				ind = j;
			}
		}
		words_uncrypt[ind].length = -1;
		for (int z = 0; z < max; z++) {
			printf("%c", words_uncrypt[ind].letters[z]);
			f = 1;
		}
		if (f == 1)printf("\n");
		f = 0;
		max = 0;
		ind = 0;
	}
	main();
}
void replace() {
	char replacing[10] = "";
	char by[10] = "";
	int flag = 0;
	printf("Введите 2 буквы:\n");
	scanf("%s %s", &replacing[0], &by[0]);
	for (int i = 0; i < size_big; i++) {
		if (text[i] == replacing[0]) {
			text[i] = by[0];
			flag = 1;
		}
	}
	if (flag == 1) {
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				history[his_place][j] = *replacing;
			}
			else if (j == 1) {
				history[his_place][j] = '=';
			}
			else if (j == 2) {
				history[his_place][j] = *by;
			}
			else if (j == 3) {
				history[his_place][j] = '\n';
			}
		}
		his_place++;
	}
	main();
}
void history_print() {
	for (int i = 0; i < his_place; i++) {
		printf("%s", history[i]);
	}
	main();
}
void clear() {
	if (history[his_place - 1][0] == 'D' && history[his_place - 1][1] == 'E' && history[his_place - 1][2] == 'C') {
		int to_know = his_place;
		for (int i = 0; i < size_big; i++){
			text[i] = text1[i];
		}
		his_place = 0;
		for (int i = 0; i < to_know; i++){
			int flag = 0;
			for (int i = 0; i < size_big; i++) {
				if (text[i] == history[his_place][0]) {
					text[i] = history[his_place][2];
					flag = 1;
				}
			}
			if (flag == 1) {
				for (int j = 0; j < 4; j++) {
					if (j == 0) {
						history[his_place][j] = history[his_place][0];
					}
					else if (j == 1) {
						history[his_place][j] = '=';
					}
					else if (j == 2) {
						history[his_place][j] = history[his_place][2];
					}
					else if (j == 3) {
						history[his_place][j] = '\n';
					}
				}
				his_place++;
			}
		}
		his_place++;
	}

	char comeback = history[his_place-1][0];
	char useless = history[his_place-1][2];
	for (int i = 0; i < size_big;i++) {
		if (text[i] == useless) {
			text[i] = comeback;
		}
	}
	his_place--;
	main();
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	setlocale(LC_ALL, "Russian");
	int chosen = -1;
	printf("Выберите действие:\n"
		"0) Вывод массива в текущем состоянии\n"
		"1) Анализ частоты\n"
		"2) Автодешифровка\n"
		"3) Вывод слов по количеству букв\n"
		"4) Вывод слов по количеству букв(нерасшиврованный)\n"
		"5) Замена буквы\n"
		"6) История\n"
		"7) Удалить последнее действие\n"
		"8) Выход из программы\n");
	chosen = scann(chosen);
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {} //очистка входного буфера
	int count = 0;
	char tmp = { 0 };
	if (sp_flag) {
		input = fopen("input1.txt", "r");
		if (input == NULL) {
			printf("Файл с таким именем не найден!");
			return 0;
		}
		while (fscanf(input, "%c", &tmp) != EOF) {
			text[count] = tmp;
			text1[count] = tmp;
			count++;
		}
		size_big = count;
		sp_flag = 0;

	}
	if (size_big == 0) {
		printf("Файл пуст!");
		return 0;
	}
	switch (chosen) {
	case 0:
		print(text);
		break;
	case 1:
		freq(text);
		break;
	case 2:
		decrypt(text);
		break;
	case 3:
		words_len();
		break;
	case 4:
		words_non_crypt();
		break;
	case 5:
		replace();
		break;
	case 6:
		history_print();
		break;
	case 7:
		clear();
		break;
	case 8:
		printf("\nВыход");
		return 0;
	}
	if (chosen != 7 && chosen != 6 && chosen != 5 && chosen != 4 && chosen != 3 && chosen != 2 && chosen != 1 && chosen != 0 && isalpha(chosen) == 0) {
		error();
	}
	fclose(input);
	return 0;
}
