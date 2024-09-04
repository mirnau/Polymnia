#include "Log.h"

std::mutex LoggerTool::Log::s_m_mutex;
std::shared_ptr<LoggerTool::Log> LoggerTool::Log::Instance = nullptr;

LoggerTool::Log::Log() noexcept :
    color(new LogColor()) {}

LoggerTool::Log::~Log() noexcept
{
    delete color;
    color = nullptr;
}

std::shared_ptr<LoggerTool::Log> LoggerTool::Log::GetInstance()
{
    std::lock_guard<std::mutex> lock(s_m_mutex);
    if(!Instance)
    {
        Instance = std::make_shared<LoggerTool::Log>();
    }

    return Instance;
}

const char* LoggerTool::Log::LevelToString(const Level level) const
{
    switch(level)
    {
        case Trace: return "Trace";
        case Info: return "Info";
        case Warning: return "Warning";
        case Error: return "Error";
        case Fatal: return "Fatal";
        default: return "Unknown";
    }
}