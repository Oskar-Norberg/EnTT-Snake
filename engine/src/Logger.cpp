//
// Created by Oskar.Norberg on 2025-03-28.
//

#include "Logger.h"

namespace Logging
{
    #define CORE_LOGGER_NAME "RNGOCoreLogger"
    #define LOG_PATH "EngineLogs/log.log"
    #define NR_OF_LOG_FILES 6

    #define ENTER_MESSAGE "Starting up RNGOEngine"
    #define EXIT_MESSAGE "Exiting...\n"
    
    std::shared_ptr<spdlog::sinks::daily_file_sink<std::mutex>> Logger::file_sink_;
    std::shared_ptr<spdlog::logger> Logger::logger_;
    
    void Logger::Init()
    {
        file_sink_ = std::make_shared<spdlog::sinks::daily_file_sink<std::mutex>>(LOG_PATH, 0, 0, false, NR_OF_LOG_FILES);
        logger_ = std::make_shared<spdlog::logger>(CORE_LOGGER_NAME, file_sink_);
        // logger_->set_pattern("[%H:%M:%S] [%n] [thread %t]  %v");
        // spdlog::register_logger(logger_);

        LogEnter();
    }

    void Logger::Cleanup()
    {
        LogExit();

        file_sink_ = nullptr;
        logger_ = nullptr;
    }

    std::shared_ptr<spdlog::logger> Logger::GetLogger()
    {
        return logger_;
    }

    void Logger::LogEnter()
    {
        logger_->info(ENTER_MESSAGE);
    }

    void Logger::LogExit()
    {
        logger_->info(EXIT_MESSAGE);
    }
}
