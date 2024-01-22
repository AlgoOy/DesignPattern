/**
 * Created by AlgoOy on 2024/1/22.
 */

#ifndef DESIGNPATTERN_SINGLETON_H
#define DESIGNPATTERN_SINGLETON_H

#include <iostream>
#include <memory>
#include <mutex>
#include <unordered_map>

class SingletonLazy
{
private:
	friend std::unique_ptr<SingletonLazy>::deleter_type;

	SingletonLazy()
	{
		std::cout << "build singleton lazy obj" << std::endl;
	}

	// write a class, need to test destructor
	~SingletonLazy()
	{
		std::cout << "destroy singleton lazy obj" << std::endl;
	}
public:
	static SingletonLazy& getInstance()
	{
		return *m_singleton;
	}
private:
	static std::unique_ptr<SingletonLazy> m_singleton;
};

std::unique_ptr<SingletonLazy> SingletonLazy::m_singleton(new SingletonLazy);

class SingletonEager
{
private:
	friend std::unique_ptr<SingletonEager>::deleter_type;

	SingletonEager()
	{
		std::cout << "build singleton eager obj" << std::endl;
	}

	~SingletonEager()
	{
		std::cout << "destroy singleton eager obj" << std::endl;
	}
public:
	static SingletonEager& getInstance()
	{
		static std::once_flag onceFlag;
		std::call_once(onceFlag, []()
		{
			m_singleton.reset(new SingletonEager);
		});
		return *m_singleton;
	}
private:
	inline static std::unique_ptr<SingletonEager> m_singleton;
};

#define MAX_SINGLETON 3

class SingletonExtension
{
private:
	friend std::unique_ptr<SingletonExtension>::deleter_type;

	SingletonExtension()
	{
		std::cout << "build NO." << m_instance_count << " singleton extension obj" << std::endl;
	}

	~SingletonExtension()
	{
		std::cout << "destroy singleton extension obj" << std::endl;
	}
public:
	static SingletonExtension& getInstance()
	{
		m_instance_count++;
		if (m_instance_count > MAX_SINGLETON)
		{
			m_instance_count = 1;
		}
		auto it = m_map.find(m_instance_count);
		if (it != m_map.end())
		{
			return *it->second;
		}
		else
		{
			m_map[m_instance_count].reset(new SingletonExtension);
			return *m_map[m_instance_count];
		}
	}
private:
	inline static std::unordered_map<int, std::unique_ptr<SingletonExtension>> m_map =
			std::unordered_map<int, std::unique_ptr<SingletonExtension>>();
	inline static int m_instance_count = MAX_SINGLETON;
};

#endif //DESIGNPATTERN_SINGLETON_H
