//
// Created by Oskar.Norberg on 2025-03-28.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <memory>

// Exclude some Windows headers which caused conflict with raylib
#if defined(_WIN32)           
    #define NOGDI
    #define NOUSER
    #define WIN32_LEAN_AND_MEAN
#endif


#include <spdlog/spdlog.h>
#include <spdlog/sinks/daily_file_sink.h>

namespace Logging
{
    class Logger
    {
    public:
        Logger() = delete;
        ~Logger() = delete;
        
        static void Init();
        static void Cleanup();
        static std::shared_ptr<spdlog::logger> GetLogger();
    private:
        static void LogEnter();
        static void LogExit();
        
        static std::shared_ptr<spdlog::sinks::daily_file_sink<std::mutex>> file_sink_;
        static std::shared_ptr<spdlog::logger> logger_;
    };
}

// TODO: Don't flush after every log
#define RNGO_LOG_TRACE(message) Logging::Logger::GetLogger()->trace(message); Logging::Logger::GetLogger()->flush();
#define RNGO_LOG_INFO(message) Logging::Logger::GetLogger()->info(message); Logging::Logger::GetLogger()->flush();
#define RNGO_LOG_ERROR(message) Logging::Logger::GetLogger()->error(message); Logging::Logger::GetLogger()->flush();
#define RNGO_LOG_CRITICAL(message) Logging::Logger::GetLogger()->critical(message); Logging::Logger::GetLogger()->flush();
#define RNGO_LOG_WARNING(message) Logging::Logger::GetLogger()->warn(message); Logging::Logger::GetLogger()->flush();

#endif //LOGGER_H
