#pragma once
#include <chrono>
#include <fstream>
class Benchmark
{
public:
	void Start();
	void End();
	~Benchmark();
private:
	void LogBenchmarkMarker(std::ofstream& output);
private:
	std::chrono::steady_clock::time_point last;
	float startTime = 0;
	float minTime = std::numeric_limits<float>::max();
	float maxTime = std::numeric_limits<float>::min();
};

