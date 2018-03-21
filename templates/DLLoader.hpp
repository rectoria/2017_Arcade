/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by rectoria
*/

#ifndef DLLOADER_HPP
#define DLLOADER_HPP

#include <string>
#include <dlfcn.h>
#include <iostream>
#include "IGameModule.hpp"
#include "IGraphicLib.hpp"

template<typename T>
class DLLoader {
public :

	DLLoader() = delete;

	explicit DLLoader(std::string &filepath, std::string &&folder)
		: _filePath(folder + filepath)
	{
		ptr = dlopen(_filePath.c_str(), RTLD_LAZY);
		if (!ptr)
			std::cerr << dlerror() << std::endl;
	}

	~DLLoader()
	{
		if (ptr)
			dlclose(ptr);
	}

public:
	T *getInstance()
	{
		void *temp = nullptr;

		if (ptr && !_instance){
			temp = dlsym(ptr, _fctName.c_str());
			_instance = reinterpret_cast<T *(*)()>(temp)();
		}
		return _instance;
	};

private:
	void *ptr;
	T *_instance = nullptr;
	std::string _filePath;
	std::string _fctName = "entryPoint";
};

#endif