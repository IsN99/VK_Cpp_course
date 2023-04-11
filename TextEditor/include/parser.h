#include <string>
#include <memory>
#include <vector>
#include "operations.h"

class Parser{
public:
    explicit Parser(const std::string& expression) : expression_(expression) {}

    // Построение конвеера из наследников IOperation 
    std::unique_ptr<IOperation> OpsQueue(){
        // Разбиваем выражение по '|'
        std::vector<std::string> operations = SplitLine(expression_, '|');

        // Указатель на следующую операцию
        std::unique_ptr<IOperation> next_operation = nullptr;

        // Обходим вектор операций с конца
        for (auto it = operations.rbegin(); it != operations.rend(); ++it){
            // Создаем объект операции
            std::unique_ptr<IOperation> current_operation = CreateOperation(*it);

            // Устанавливаем указатель на следующую операцию
            current_operation->SetNextOperation(std::move(next_operation));

            // Обновляем указатель на следующую операцию для следующей итерации цикла
            next_operation = std::move(current_operation);
        }

        // Возвращаем указатель на первую операцию в конвейере
        return next_operation;
    }

private:
    // Метод, который создает объект операции на основе строки с описанием операции
    std::unique_ptr<IOperation> CreateOperation(const std::string& operation){
        // Разбиваем строку на аргументы
        std::vector<std::string> args = SplitLine(operation, ' ');
        std::string command = args[0];

        // Создаем объект операции в зависимости от команды
        if (command == "cat") {
            return std::make_unique<CatOperation>(args[1]);
        } else 
        if (command == "echo") {
            return std::make_unique<EchoOperation>(args[1]);
        } else
        if (command == "tail") {
            return std::make_unique<TailOperation>(args[1]);
        } else
        {
        	std::cout<<"Ошибка распознания команды"<<std::endl;
            return nullptr;
        }
    }

    //Делим строку по разделителю
    std::vector<std::string> SplitLine(const std::string& str, char delimiter){
        std::vector<std::string> Words;
        std::size_t start = 0;
        std::size_t end = str.find(delimiter, start);

        while (end != std::string::npos) {
            Words.push_back(str.substr(start, end - start));
            start = end + 1;
            end = str.find(delimiter, start);
        }

        if (start < str.length()) {
            Words.push_back(str.substr(start));
        }

        return Words;
    }

    //переменная для выражения
    std::string expression_;
};
