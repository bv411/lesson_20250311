#include <iostream>
#include <stdio.h>

//#define DEBUG

/*
ДОМАШНЕЕ ЗАДАНИЕ

Доработать программу викторины. 

Чтобы ваша программа получала на вход файл с викторинами разной 
тематики и вы могли этот файл прочитать и проиграть викторину


*/


/*
Задание 1. Дан текстовый файл. Подсчитать количество
слов, начинающихся с символа, который задаёт пользо-
ватель.
*/


#define TYPE 2

#define ERR_MESSAGE "произошла шибка программы"

#define SUM(a,b) (a)+(b)

#define MULT(a,b) (a)*(b)

int main() {

    setlocale(LC_ALL, "Ru");

    std::cout << ERR_MESSAGE << TYPE <<  std::endl;

    std::cout << SUM(2*2,2*3)  <<std::endl; 
    std::cout << MULT(2 + 2, 2 + 3) << std::endl; // 2+2 *2+3

    int x = 4;
    int y = 6;

    int z = MULT(x, y);

    std::cout << z << std::endl;

#ifdef TYPE
    std::cout << "TYPE is define" << std::endl;
#if TYPE == 1
    std::cout << "TYPE для очень простой программы" << std::endl;
#elif TYPE == 2
    std::cout << "TYPE для программы средней сложности" << std::endl;
#endif
#else
    std::cout << "TYPE not define" << std::endl;
#endif // TYPE

}


void print_error(errno_t err) {
    
    switch (err)
    {
    case 2:
        std::cout << "Отсутствует такой файл или каталог. " << "\n";
        break;
    case 13:
        std::cout << "в разрешении отказано.  " << "\n";
        break;
    default:
        std::cout << "Ошибка неизвестна!  " << err << "\n";
        break;
    }
}

void read_file_v1 (const char* path) {

    FILE* in_file{ nullptr };
    errno_t err {};

    err = fopen_s(&in_file, path, "r");
    if (err != 0) {
        print_error(err);
        return;
    }

    std::cout << "The file be opened \n";

    char symb;
    std::cout << "Enter symbol ";
    std::cin >> symb;
    int count = 0;
    char str[255]{};

    /*while (!feof(in_file)) {        
        if (!fgets(str, 255, in_file))
            break;*/

    while (fgets(str, 255, in_file)){

#ifdef DEBUG
        std::cout << str << std::endl;
#endif
        count += (str[0] == symb);

        for (int i = 0; str[i] != '\0'; i++) {   
#ifdef DEBUG
            std::cout << str[i + 1] << " " << count << std::endl;
#endif
            if (str[i] == ' ' && str [i+1] == symb) {
                count++;                
            }
        }
    }
    fclose(in_file);

    std::cout << "Count = " << count << std::endl;
}

/*
Задание 2. Дан текстовый файл.Необходимо создать
новый файл, в который переписать из исходного файла
все слова, состоящие не менее чем из семи букв.
*/

void working_file (const char* path) {

    FILE* in_file{ nullptr };
    errno_t err {};

    err = fopen_s(&in_file, path, "r");
    if (err != 0) {
        print_error(err);
        return;
    }


    const char *out_path = "C:\\temp\\out.txt";
    FILE* out_file{ nullptr };
    
    err = fopen_s(&out_file, out_path, "w");
    if (err != 0) {
        fclose(in_file);
        print_error(err);
        return;
    }


    std::cout << "The file be opened \n";

    char str[255];    
    while (fgets(str, 255, in_file)) {

        bool is_start_word = (str[0] != ' ');
        int count = 0;        
        
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == ' ') {
                if (is_start_word) {
                    is_start_word = false;

                    std::cout << "count = " << count << std::endl;                    
                    if (count >= 6) {
                        char word[200]{};
                        strncpy_s(word, &(str[i - count]), count);
                        fputs(word, out_file);
                        fputc(' ', out_file);                        
                    }
                    count = 0;
                }                
            } else {

                is_start_word = true;
                count++;
            }
        }
        
    }

    fclose(in_file);
    fclose(out_file);
}

int mainXX() {

    setlocale(LC_ALL, "Ru");

    const char* path = "C:\\temp\\test.txt";
    read_file_v1(path);

    return 0;
}

//int main() {
//int main (int argc, char* argv[]){
//	setlocale(LC_ALL, "Ru");
//
//    for (int i = 0; i < argc; i++) {
//        std::cout << i << "     " << argv[i] << std::endl;
//    }
//
//    std::cout << std::endl << std::endl << std::endl << std::endl;
//
//    if (argc >= 3) {
//        int count = atoi(argv[1]);
//        for (int i = 0; i < count; i++)
//            printf("%s \n", argv[2]);
//
//    } else {
//        std::cout << "Вызови меня с числом и строчкой )) \n";
//    }
//    
//    /*if (argc > 1) {
//        read_file_v1(argv[1]);
//    }
//    else {
//        const char* path = "C:\\temp\\test.txt";
//        read_file_v1(path);
//    }*/
//
//   // system("pause");
//	return 0;
//}


//int main(int argc, char* argv[]) {
//    setlocale(LC_ALL, "Ru");
//
//    for (int i = 0; i < argc; i++) {
//        std::cout << i << "     " << argv[i] << std::endl;
//    }
//
//    std::cout << std::endl << std::endl << std::endl << std::endl;
//
//    char word[255];
//    int count = -1;
//    int err = 0;
//    bool count_is_found{};
//    bool word_is_found{};
//    if (argc >= 4) {
//        for (int i = 1; i < argc && (!word_is_found || !count_is_found); i++) {
//            if (strcmp(argv[i], "-n") == 0) {
//                if (i != argc - 1) {
//                    count = atoi(argv[i + 1]);
//                    if (count == 0) {
//                        err = 1;
//                        break;
//                    }
//                    i++;
//                    count_is_found = true;
//                } else {
//                    err = 1;
//                    break;
//                }
//            } else {
//                if (!word_is_found) {
//                    strcpy_s(word, argv[i]);
//                    word_is_found = true;
//                }
//            }
//        }
//    } else {
//        err = 1;
//    }
//
//    if (err == 0) {
//        for (int j = 0; j < count; j++)
//            printf("%s \n", word);
//    }
//    else {
//        std::cout << "Вызови меня с -n число строка )) \n";
//    }
//	
//    return 0;
//}

