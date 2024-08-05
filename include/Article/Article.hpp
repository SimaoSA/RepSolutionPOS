#pragma once

#include <string>

class Article
{
    protected:
        float _Iva;
        float _UnitPrice;
        std::string _Description; 

    public:
        Article(float iva, float UnitPrice, std::string description) : _Iva(iva), _UnitPrice(UnitPrice), _Description(description) {};
        ~Article() {};
};


