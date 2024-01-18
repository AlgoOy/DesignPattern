/**
 * Created by AlgoOy on 2024/1/18.
 */
#include "simple_factory.h"
#include <iostream>

int main()
{
	std::shared_ptr<DesignPattern::Interface> p = DesignPattern::AutoFactory::createInterface();
	p->doWork("hello world");
	return 0;
}