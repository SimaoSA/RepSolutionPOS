#pragma once
#include "Article.h"
#include <memory>

class FoodProductFactory 
{
	public:
		 FoodProductFactory() {}
		~FoodProductFactory() {}
		std::unique_ptr<Article> createArticle(int64_t idEAN13, double vat, double price, std::string description, char score);
};

