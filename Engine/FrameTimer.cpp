#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	last = std::chrono::steady_clock::now();
}

float FrameTimer::Mark()
{
	const auto oldTime = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> deltaTime = last - oldTime;
	return deltaTime.count();
}
