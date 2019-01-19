#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>


namespace Kang {
	class HAZEL_API Log
	{
	public:
		static void Init();
		
		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

/* Core logger macros */
#define HZ_CORE_TRACE(...)  Kang::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)   Kang::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)   Kang::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)  Kang::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)  Kang::Log::GetCoreLogger()->fatal(__VA_ARGS__)

/* Client logger macros*/
#define HZ_TRACE(...)		Kang::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)		Kang::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)		Kang::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)		Kang::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)		Kang::Log::GetClientLogger()->fatal(__VA_ARGS__)

