#pragma once
#include <memory>
#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
namespace SAMI
{

	class SAMI_API Log
	{

	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:

		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return  s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	};


}



//ENGINE SIDE,CORE SIDE LOG
#define SM_ENGINE_ERROR(...) ::SAMI::Log::GetEngineLogger()->error(__VA_ARGS__)
#define SM_ENGINE_WARN(...) ::SAMI::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define SM_ENGINE_TRACE(...) ::SAMI::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define SM_ENGINE_INFO(...) ::SAMI::Log::GetEngineLogger()->info(__VA_ARGS__)
#define SM_ENGINE_FATAL(...) ::SAMI::Log::GetEngineLogger()->fatal(__VA_ARGS__)

//CLIENT SIDE LOG
#define SM_ERROR(...) ::SAMI::Log::GetClientLogger()->error(__VA_ARGS__)
#define SM_WARN(...) ::SAMI::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SM_TRACE(...) ::SAMI::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SM_INFO(...) ::SAMI::Log::GetClientLogger()->info(__VA_ARGS__)
#define SM_FATAL(...) ::SAMI::Log::GetClientLogger()->fatal(__VA_ARGS__)


//ENGINE SIDE

//#define SM_ENGINE_ERROR(...):: SAMI
