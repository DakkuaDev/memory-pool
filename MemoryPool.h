/*
@file
@author Daniel Guerra Gallardo
@version 0.0.1
@description: memory pool template
Copyright (C) Daniel Guerra 2020
*/

#pragma once
#include <iostream>

namespace MemoryPool
{

	static void PrintMemoryUsage();

	// Estructura encargada de calcular y devolver la memoria en bloque en uso
	struct AllocationMetrics
	{
	public:
		uint32_t TotalAllocated = 0;
		uint32_t TotalFreed = 0;

		uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
	};

	// Estructura de Objeto
	struct Object
	{
		int x, y, z;
	};


	// Estructura de Vector3
	class Vector3
	{
	protected:
		float x, y, z;

	public:
		// Constructores
		Vector3() = default;
		Vector3(const Vector3&) = default;
		Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	};
}