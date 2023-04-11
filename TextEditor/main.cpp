#include "include/parser.h"

int main (int argc, char* argv[]){
    std::cout << "ВВОД: " << argv[0] << " \'выражение\'\n";
    std::cout << "Формат ввода выражения: operation <argument>|operation <argument>\n";
    std::cout << "Без лишних пробелов, разделитель без пробелов спереди и сзади, между операцией и аргументом 1 пробел\n";
    if(argc != 2){        
        return 1;
    }

    // Создаем парсер и получаем указатель на первую операцию в конвейере
    Parser parser(argv[1]);
    std::unique_ptr<IOperation> first_operation = parser.OpsQueue();

    // Запускаем конвейер
    std::string line;
    while (std::getline(std::cin, line)) {
        first_operation->ProcessLine(line);
    }

    // Обрабатываем конец ввода
    first_operation->HandleEndOfInput();//debug

    return 0;
}
