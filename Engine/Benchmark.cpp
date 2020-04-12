#include "Benchmark.h"
#include <fstream>
#include <iomanip>

void Benchmark::Start()
{
	last = std::chrono::steady_clock::now();
}

void Benchmark::End()
{
	auto deltaTime = std::chrono::steady_clock::now() - last;
	if (deltaTime.count() < minTime) {
		minTime = deltaTime.count();
	}

	if (deltaTime.count() > maxTime) {
		maxTime = deltaTime.count();
	}
}

Benchmark::~Benchmark()
{
	std::ofstream out("Benchmark.txt", std::ios_base::app);

	LogBenchmarkMarker(out);
	out << "Min time: " << std::setprecision(5) << minTime * std::pow(10, -6) << " ms\n";
	out << "Max time: " << std::setprecision(5) << maxTime * std::pow(10, -6) << " ms\n";
	LogBenchmarkMarker(out);
	out.flush();
	out.close();
}

void Benchmark::LogBenchmarkMarker(std::ofstream& output)
{
#ifdef NDEBUG
	output << "\n" << "<===== Benchmark Release =====>" << "\n";
#else
	output << "\n" << "<===== Benchmark Debug =====>" << "\n";
#endif
}
