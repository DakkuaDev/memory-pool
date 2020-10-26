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

	struct AllocationMetrics
	{
	public:
		uint32_t TotalAllocated = 0;
		uint32_t TotalFreed = 0;

		uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
	};

	struct Object
	{
		int x, y, z;
	};

}