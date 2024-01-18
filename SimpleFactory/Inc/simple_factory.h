/**
 * Created by AlgoOy on 2024/1/18.
 */

#ifndef DESIGNPATTERN_SIMPLE_FACTORY_H
#define DESIGNPATTERN_SIMPLE_FACTORY_H

#include <iostream>
#include <string>
#include <memory>
#include <map>

namespace DesignPattern
{
	class Interface
	{
	public:
		virtual void doWork(std::string s) = 0;
	protected:
		Interface() = default;
	};

	class ImplOne : public Interface
	{
	public:
		ImplOne() = default;

		void doWork(std::string s) override
		{
			std::cout << "ImplOne doWork: " << s << std::endl;
		}
	};

	class ImplTwo : public Interface
	{
	public:
		ImplTwo() = default;

		void doWork(std::string s) override
		{
			std::cout << "ImplTwo doWork: " << s << std::endl;
		}
	};

	class Factory
	{
	public:
		static std::shared_ptr<Interface> createInterface(int type)
		{
			std::shared_ptr<Interface> pInterface = nullptr;
			if (type == 1)
			{
				pInterface = std::make_shared<ImplOne>();
			}
			else if (type == 2)
			{
				pInterface = std::make_shared<ImplTwo>();
			}
			return pInterface;
		}
	};

/*--------------------------------------------------------------------------------------*/

	class ObjectRegister
	{
	public:
		typedef std::shared_ptr<Interface> (* Constructor)();
		static void registerClass(const std::string& className, Constructor constructor)
		{
			constructors()[className] = constructor;
		}

		static std::shared_ptr<Interface> createObject(const std::string& className)
		{
			Constructor constructor = nullptr;
			if (constructors().find(className) != constructors().end())
			{
				constructor = constructors().find(className)->second;
			}
			if (constructor)
			{
				return constructor();
			}
			return nullptr;
		}

	private:
		inline static std::map<std::string, Constructor>& constructors()
		{
			static std::map<std::string, Constructor> instance;
			return instance;
		}
	};

#define REG_CLASS(className) \
    class className##Helper \
    { \
    public: \
        className##Helper() \
        { \
            ObjectRegister::registerClass(#className, createObject); \
        } \
        static std::shared_ptr<Interface> createObject() \
        { \
            return std::make_shared<className>(); \
        } \
    };                       \
    className##Helper className##HelperInstance;

	REG_CLASS(ImplTwo)

	REG_CLASS(ImplOne)

	class AutoFactory
	{
	public:
		static std::shared_ptr<Interface> createInterface()
		{
			std::shared_ptr<Interface> pInterface = nullptr;
			pInterface = ObjectRegister::createObject("ImplOne");
			return pInterface;
		}
	};
}

#endif //DESIGNPATTERN_SIMPLE_FACTORY_H
