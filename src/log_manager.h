#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

class LogManager
{
public:
    static void activateLogging()
    {
        spdlog::set_level(spdlog::level::debug);
        spdlog::flush_on(spdlog::level::debug);

        if(loggingMode_ == LoggingMode::LOG_TO_FILE_AND_CONSOLE)
        {
            qDebug() << "Logging to file and console";
            spdlog::default_logger()->sinks().push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.txt", true));
        }
        else if(loggingMode_ == LoggingMode::LOG_TO_FILE_ONLY)
        {
            qDebug() << "Logging to file only";
            spdlog::default_logger()->sinks().push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.txt", true));
        }
        else if(loggingMode_ == LoggingMode::LOG_TO_CONSOLE_ONLY)
        {
            qDebug() << "Logging to console only";
        }
    }

private:
    enum class LoggingMode
    {
        LOG_TO_FILE_AND_CONSOLE, LOG_TO_FILE_ONLY, LOG_TO_CONSOLE_ONLY
    };

    inline static LoggingMode loggingMode_ = LoggingMode::LOG_TO_FILE_AND_CONSOLE;
};
