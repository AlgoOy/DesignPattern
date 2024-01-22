/**
 * Created by AlgoOy on 2024/1/22.
 */

#include <cstdio>
#include "singleton.h"

int main()
{
	std::cout << "------------------------" << std::endl;

	SingletonEager& obj1 = SingletonEager::getInstance();
	SingletonEager& obj2 = SingletonEager::getInstance();
	SingletonEager& obj3 = SingletonEager::getInstance();
	printf("obj1 = %p\nobj2 = %p\nobj3 = %p\n", &obj1, &obj2, &obj3);

	std::cout << "------------------------" << std::endl;

	SingletonLazy& obj4 = SingletonLazy::getInstance();
	SingletonLazy& obj5 = SingletonLazy::getInstance();
	SingletonLazy& obj6 = SingletonLazy::getInstance();
	printf("obj4 = %p\nobj5 = %p\nobj6 = %p\n", &obj4, &obj5, &obj6);

	std::cout << "------------------------" << std::endl;

	SingletonExtension& obj7 = SingletonExtension::getInstance();
	SingletonExtension& obj8 = SingletonExtension::getInstance();
	SingletonExtension& obj9 = SingletonExtension::getInstance();
	printf("obj7 = %p\nobj8 = %p\nobj9 = %p\n", &obj7, &obj8, &obj9);
	SingletonExtension& obj10 = SingletonExtension::getInstance();
	SingletonExtension& obj11 = SingletonExtension::getInstance();
	SingletonExtension& obj12 = SingletonExtension::getInstance();
	printf("obj10 = %p\nobj11 = %p\nobj12 = %p\n", &obj10, &obj11, &obj12);

	return 0;
}
