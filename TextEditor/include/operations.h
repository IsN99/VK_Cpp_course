#include <string>
#include <list>
#include <memory>
#include <fstream>
#include <iostream>


// интерфейс - базовый родитель
class IOperation {
public:
    virtual void ProcessLine(const std::string& str) = 0;
    virtual void HandleEndOfInput() = 0;
    virtual void SetNextOperation(std::unique_ptr<IOperation> NextOperation) = 0;
    virtual ~IOperation() = default;
};


// cat<filename>
class CatOperation: public IOperation{
public:
    explicit CatOperation(const std::string FileName){
        FileName_ = FileName;
    }

    void ProcessLine(const std::string& str)override{
        Buffer.emplace_back(str);
    }

    void HandleEndOfInput()override{
        std::ifstream file (FileName_);//debug
        std::string temp;

        while (std::getline(file, temp)){
            Buffer.emplace_back(temp);
        }

        if (NextOperation_) {
            for (const auto& str : Buffer) {
                NextOperation_->ProcessLine(str);
            }
            NextOperation_->HandleEndOfInput();
        } 
        
        else {
            for (const auto& str : this->Buffer) {
                std::cout << str << std::endl;
            }
        }
    }

    void SetNextOperation(std::unique_ptr<IOperation> NextOperation)override{
        NextOperation_ = std::move(NextOperation);
    }

private:
    std::string FileName_;
    std::list<std::string> Buffer;
    std::unique_ptr<IOperation> NextOperation_;
};


// echo<some string>
class EchoOperation: public IOperation{
public:
    explicit EchoOperation(const std::string String){
        String_ = String;
    }

    void ProcessLine(const std::string& str)override{
        // pass
    }

    void HandleEndOfInput()override{
        if (NextOperation_) {
            NextOperation_->ProcessLine(String_);
            NextOperation_->HandleEndOfInput();
        } 
        
        else {            
            std::cout << String_ << std::endl;            
        }
    }

    void SetNextOperation(std::unique_ptr<IOperation> NextOperation)override{
        NextOperation_ = std::move(NextOperation);
    }

private:
    std::string String_;
    // std::list<std::string> Buffer;
    std::unique_ptr<IOperation> NextOperation_;
};


//tail<N>
class TailOperation: public IOperation{
public:
    explicit TailOperation(const std::string N){
        N_ = std::stoi (N);
    }

    void ProcessLine(const std::string& str)override{
        if (N_ > 0){
            Buffer.emplace_back(str);
        }

        if (Buffer.size() > N_){
            Buffer.pop_front();//debug
        }
    }

    void HandleEndOfInput()override{
        if (NextOperation_) {
            for (const auto& str : Buffer){
                NextOperation_->ProcessLine(str);
            }
        } 
        
        else {    
            for (const auto& str : Buffer){
                std::cout << str << std::endl;
            }        
                        
        }
    }

    void SetNextOperation(std::unique_ptr<IOperation> NextOperation)override{
        NextOperation_ = std::move(NextOperation);
    }

private:
    int N_;
    std::list<std::string> Buffer;
    std::unique_ptr<IOperation> NextOperation_;
};