/*
@file
@author Daniel Guerra Gallardo
@version 0.0.1
@description: memory pool template
Copyright (C) Daniel Guerra 2020
*/

#include <iostream>
#include "MemoryPool.h"

using namespace MemoryPool;

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size);
void operator delete(void* memory, size_t size);

/// Llamada a función en cada invocación del operador new
void* operator new(size_t size)
{
	s_AllocationMetrics.TotalAllocated += size;

	//std::cout << "Allocating " << size << " bytes\n";

	// Memoria asignada por new 
	return malloc(size);
}

/// Llamada a función en cada invocación del operador delete
void operator delete(void* memory, size_t size)
{
	s_AllocationMetrics.TotalFreed += size;

	// std::cout << "Freeing " << size << " bytes\n";

	free(memory);
}

/// Total de memoria en uso
static void MemoryPool::PrintMemoryUsage() 
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}


int main()
{
	// Memoria usada al comienzo de la ejecución
	MemoryPool::PrintMemoryUsage();

	// Creo un objeto de prueba
	MemoryPool::Object* obj = new MemoryPool::Object;

	// Memoria usada después de crear el objeto
	MemoryPool::PrintMemoryUsage();
	return 0;
}


