#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

//log macros
#define ENGINE_TRACE_LOG(...) ::EngineCore::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ENGINE_WARN_LOG(...) ::EngineCore::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_INFO_LOG(...) ::EngineCore::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_ERROR_LOG(...) ::EngineCore::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENGINE_FATAL_LOG(...) ::EngineCore::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define CLIENT_TRACE_LOG(...) ::EngineCore::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_WARN_LOG(...) ::EngineCore::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_INFO_LOG(...) ::EngineCore::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_ERROR_LOG(...) ::EngineCore::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_FATAL_LOG(...) ::EngineCore::Log::GetClientLogger()->fatal(__VA_ARGS__)

namespace EngineCore 
{
	class ENGINE_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}
	};
}
