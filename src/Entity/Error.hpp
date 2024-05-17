#pragma once
#include <exception>
#include <string>

namespace Entity
{

class Error: public std::exception
{
public:
    enum Type {
        NotInit
    };
private:
    Type _error;
public:
    Error(Type e): _error(e) {};
    ~Error() = default;
    const char* what() const noexcept override {
        switch (_error)
        {
        case NotInit:
            return "method not initalize";
        default:
            return "Unknow Error";
        };
    }
};

} // namespace Entity
