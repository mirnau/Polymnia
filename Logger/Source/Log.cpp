#include "Log.h"

std::mutex LoggerTool::Log::s_m_mutex;
LoggerTool::Log* LoggerTool::Log::Instance = nullptr;

LoggerTool::Log::Log() noexcept :
    color(new LogColor())
{}

LoggerTool::Log::~Log() noexcept
{
    delete color;
    color = nullptr;
}

LoggerTool::Log* LoggerTool::Log::GetInstance()
{
    std::lock_guard<std::mutex> lock(s_m_mutex);
    if(!Instance)
    {
        Instance = new Log();
    }

    return Instance;
}

void LoggerTool::Log::DestroyInstance()
{
    if(Instance)
    {
        delete Instance;
    }

    Instance = nullptr;
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