#pragma once
#include "Article.h"
#include <memory>

class EletronicProductFactory 
{
	public:
		 EletronicProductFactory() {}
		~EletronicProductFactory() {}
		std::unique_ptr<Article> createArticle(int64_t idEAN13, double vat, double price, std::string description, std::string power);
};

