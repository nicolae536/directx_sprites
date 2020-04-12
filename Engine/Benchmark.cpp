#include "Benchmark.h"
#include <fstream>
#include <iomanip>

void Benchmark::Start()
{
	last = std::chrono::steady_clock::now();
}

void Benchmark::End()
{
	std::chrono::duration<float> deltaTime = std::chrono::steady_clock::now() - last;
	if (deltaTime.count() < minTime) {
		minTime = deltaTime.count();
	}

	if (deltaTime.count() > maxTime) {
		maxTime = deltaTime.count();
	}

	sampler++;
}

Benchmark::~Benchmark()
{
	std::ofstream out("Benchmark.txt", std::ios_base::app);

	LogBenchmarkMarker(out);
	out << "Samples count: " << sampler << " ms\n";
	out << "Min time: " << std::setprecision(5) << minTime * 1000.0f << " ms\n";
	out << "Max time: " << std::setprecision(5) << maxTime * 1000.0f << " ms\n";
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
